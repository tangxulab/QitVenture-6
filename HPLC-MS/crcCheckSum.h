//校验码类
#pragma once
#include <QByteArray>
#include <QString>
#include <QStringList>
#include <QDebug>
typedef unsigned char u8;
typedef unsigned char byte;
typedef unsigned short u16;
typedef unsigned int u32;
class crcCheckSum
{
public:
	crcCheckSum();
	quint16 crc16ForModbus(const QByteArray& data);

	quint8 Crc8(const QByteArray& data);
	quint16 Crc16(const QByteArray& data);
	u32 Crc32(byte* _pBuff, u16 _size);
};

