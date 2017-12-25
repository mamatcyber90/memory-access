#pragma once
#include "MemoryAccess.h"

MemoryAccess::MemoryAccess::MemoryAccess()
{
}


MemoryAccess::MemoryAccess::~MemoryAccess()
{
}

char MemoryAccess::MemoryAccess::ReadChar(DWORD address, UINT newProtect)
{
	return this->ReadMemory<char>(address, newProtect);
}

short MemoryAccess::MemoryAccess::ReadInt16(DWORD address, UINT newProtect)
{
	return this->ReadMemory<short>(address, newProtect);
}

int MemoryAccess::MemoryAccess::ReadInt32(DWORD address, UINT newProtect)
{
	return this->ReadMemory<int>(address, newProtect);
}

DWORD MemoryAccess::MemoryAccess::ReadDword(DWORD address, UINT newProtect)
{
	return this->ReadMemory<DWORD>(address, newProtect);
}

long MemoryAccess::MemoryAccess::ReadInt64(DWORD address, UINT newProtect)
{
	return this->ReadMemory<long>(address, newProtect);
}

float MemoryAccess::MemoryAccess::ReadFloat(DWORD address, UINT newProtect)
{
	return this->ReadMemory<float>(address, newProtect);
}

double MemoryAccess::MemoryAccess::ReadDouble(DWORD address, UINT newProtect)
{
	return this->ReadMemory<double>(address, newProtect);
}

char * MemoryAccess::MemoryAccess::ReadCharArray(DWORD address, UINT newProtect)
{
	return this->ReadMemory<char*>(address, newProtect);
}

std::string MemoryAccess::MemoryAccess::ReadString(DWORD address, UINT newProtect)
{
	char* cArray = this->ReadMemory<char*>(address, newProtect);
	return std::string(cArray);
}

void MemoryAccess::MemoryAccess::WriteChar(DWORD address, char value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}

void MemoryAccess::MemoryAccess::WriteInt16(DWORD address, short value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}

void MemoryAccess::MemoryAccess::WriteInt32(DWORD address, int value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}

void MemoryAccess::MemoryAccess::WriteDWORD(DWORD address, int value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}

void MemoryAccess::MemoryAccess::WriteInt64(DWORD address, int value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}

void MemoryAccess::MemoryAccess::WriteFloat(DWORD address, float value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}

void MemoryAccess::MemoryAccess::WriteDouble(DWORD address, double value, UINT newProtect)
{
	this->WriteMemory(address, value, newProtect);
}
