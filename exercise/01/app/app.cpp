#include "pch.h"
#include "..\lib\public.h"
#include "..\dll2\public.h"

int main()
{
	const int numberTen = 10;

	// static
	std::cout << "Static lib: " << static_lib::get_value(numberTen) << std::endl;

	// dynamic
	HMODULE dllHandle = LoadLibraryA("dynamic_library.dll");
	if (NULL != dllHandle)
	{
		typedef double (*GetValueType)(int);
		GetValueType getValuePtr = NULL;
		getValuePtr = (GetValueType)GetProcAddress(dllHandle, "get_value");
		if (NULL != getValuePtr)
			std::cout << "Dynamic lib: " << getValuePtr(numberTen) << std::endl;
		FreeLibrary(dllHandle);
	}

	// dynamic with implib
	std::cout << "Dynamic lib with implib: " << get_value(10) << std::endl;
}
