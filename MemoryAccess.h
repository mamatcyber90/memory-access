#pragma once
#include <Windows.h>
#include <string>

namespace MemoryAccess {
	const int DEFAULT_ADDRESS_NEW_PROTECTION = PAGE_EXECUTE_READWRITE;

	class MemoryAccess
	{
	public:
		MemoryAccess();
		~MemoryAccess();

		char ReadChar(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		short ReadInt16(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		int ReadInt32(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		DWORD ReadDword(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		long ReadInt64(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		float ReadFloat(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		double ReadDouble(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		char* ReadCharArray(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);
		std::string ReadString(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION);

		template<typename T>
		T Read(DWORD address, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION) {
			return this->ReadMemory<T>(address, newProtect);
		}

		void WriteChar(DWORD address, char value, UINT newProtect);
		void WriteInt16(DWORD address, short value, UINT newProtect);
		void WriteInt32(DWORD address, int value, UINT newProtect);
		void WriteDWORD(DWORD address, int value, UINT newProtect);
		void WriteInt64(DWORD address, int value, UINT newProtect);
		void WriteFloat(DWORD address, float value, UINT newProtect);
		void WriteDouble(DWORD address, double value, UINT newProtect);
		void WriteCharArray(DWORD address, char value[], UINT newProtect);

		template<typename T>
		void Write(DWORD address, T value, UINT newProtect = DEFAULT_ADDRESS_NEW_PROTECTION) {
			this->WriteMemory(address, value, newProtect);
		}

	protected:
		template<typename T>
		T ReadMemory(DWORD address, UINT newProtect) {
			DWORD oldProtection;
			T* value;
			int size = sizeof(T);

			VirtualProtect((LPVOID)address, size, newProtect, &oldProtection);
			value = reinterpret_cast<T*>(address);
			VirtualProtect((LPVOID)address, size, oldProtection, NULL);
			return *value;
		}

		template<typename T>
		void WriteMemory(DWORD address, T value, UINT newProtect) {
			DWORD oldProtection;
			int size = sizeof(T);

			VirtualProtect((LPVOID)address, size, newProtect, &oldProtection);
			*reinterpret_cast<T*>(address) = value;
			VirtualProtect((LPVOID)address, size, oldProtection, NULL);
		}
	};
}