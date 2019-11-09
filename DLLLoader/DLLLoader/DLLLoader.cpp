#include "pch.h"
#include <iostream>

#include <windows.h> 
#include <stdio.h> 

typedef int(__cdecl *MYPROC)();

void print(const char* output)
{
	std::cout << output << "\n";
}

int main()
{
	LPCTSTR dll_location = L"C:\\Users\\James\\Desktop\\cpp_projects\\DLLLoaderProject\\DLLLoader\\x64\\Debug\\simple_dll.dll";
	LPCSTR dll_entrypoint = "hello";
	HINSTANCE simple_dll;

	simple_dll = LoadLibrary(dll_location);
	if (NULL != simple_dll)
	{
		MYPROC dll_function = (MYPROC)GetProcAddress(simple_dll, dll_entrypoint);
		if (NULL != dll_function)
		{
			print("About to call dll function");
			(dll_function)();
			print("Finished calling dll function");
		}
		else
		{
			print("Unable to get ProcAddress");
			print(dll_entrypoint);
		}

		FreeLibrary(simple_dll);
	}
	else
	{
		print("Unable to load simple dll");
	}

	return 0;
}