#pragma once
#include <QString>
#include <QByteArray>
#include "protocolparser_global.h"
class PROTOCOLPARSER_EXPORT ProtocolParser
{
public:
static QByteArray encode(const QString& message)//打包
{
	QByteArray body = message.toUtf8();
	quint16 len = body.size();
	QByteArray frame;
	frame.append(0xA5);//
	frame.append(0x5A);//帧头
	frame.append(0x01);//命令字
	frame.append(len>>8);//长度要从电脑存储的小端序转换为通信协议中的大端序，右移八位得到高位的数据
	frame.append(len & 0xFF);//按位与0xFF，来把高位清空为0，得到低位数据
	frame.append(body);//数据
	frame.append(0xFE);//帧尾
	return frame;
}
public:
	void appendData(const QByteArray& data);//数据喂入
	bool hasCompleteMessage();//完整性检测
	QString takeNextMessage();//提取出队
	int getBufferSize();
private:
	int findFrameStart();//帧头同步
	bool parseFrame(int startPos,int& dataLen, int& totalLen);
	QByteArray m_buffer;
};
