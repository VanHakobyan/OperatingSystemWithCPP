#include <process.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	PROCESS_INFORMATION pi = { 0 };
	STARTUPINFO si = { 0 };
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOW;


	CreateProcess(NULL,
		"C:\\Program Files\\Internet Explorer\\iexplore.exe http://www.google.com/",
		NULL,
		NULL,
		FALSE,
		NORMAL_PRIORITY_CLASS,
		NULL,
		NULL,
		&si,
		&pi);


	Sleep(4000);
	TerminateProcess(pi.hProcess, 0);
}