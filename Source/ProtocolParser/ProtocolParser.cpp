#include "ProtocolParser/ProtocolParser.h"
void ProtocolParser::appendData(const QByteArray& data)
{
	m_buffer.append(data);
}


bool ProtocolParser::hasCompleteMessage()
{
    // 1. 先调用 findFrameStart确保缓存开头是帧头
    if (findFrameStart() == -1) return false;

    // 2. 检查缓存长度是否至少够一个最小包（帧头2 + 命令字1 + 长度2 + 帧尾1 = 6）
    if (m_buffer.size() < 6) return false;

    // 3. 读取长度字段（大端序，位置 3 和 4）
    unsigned char lenHigh = (unsigned char)m_buffer.at(3);
    unsigned char lenLow = (unsigned char)m_buffer.at(4);
    quint16 dataLen = (lenHigh << 8) | lenLow;

    // 4. 计算完整包的总长度 = 6（固定部分）+ dataLen
    int totalLen = 6 + dataLen;

    // 5. 检查缓存长度是否足够容纳整个包
    if (m_buffer.size() < totalLen) return false;

    // 6. 检查帧尾是否为 0xFE
    if ((unsigned char)m_buffer.at(totalLen - 1) != 0xFE) return false;

    return true;
}

QString ProtocolParser::takeNextMessage()
{
    if (!hasCompleteMessage())
        return QString();
    unsigned char lenHigh = m_buffer.at(3);
    unsigned char lenlow = m_buffer.at(4);
    quint16 datalen = (lenHigh << 8) | lenlow;
    int totallen = 6 + datalen;

    QByteArray body = m_buffer.mid(5, totallen);
    m_buffer.remove(0, totallen);
	return QString::fromUtf8(body);
}

int ProtocolParser::getBufferSize()
{
    return m_buffer.size();
}


int ProtocolParser::findFrameStart()
{
	int pos = m_buffer.indexOf("\xA5\x5A");
	if (pos == -1)
	{
		return -1;
	}
	if (pos > 0)
	{
		m_buffer.remove(0, pos);
		return 0;
	}
	return 0;
}

bool ProtocolParser::parseFrame(int startPos, int& dataLen, int& totalLen)
{
	return false;
}
