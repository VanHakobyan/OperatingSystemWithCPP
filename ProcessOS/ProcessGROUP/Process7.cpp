#include <process.h>
#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	STARTUPINFO info;
	PROCESS_INFORMATION pinfo;
	memset(&info, 0, sizeof(info));
	info.cb = sizeof(info);
	char cmd[300] = "C:/Program Files/Windows NT/Accessories/wordpad.exe";
	WCHAR cmdw[300];
	for (int i = 0; i<300; i++) cmdw[i] = (WCHAR)cmd[i];

	if (CreateProcess(NULL, cmdw,
		NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL,
		&info, &pinfo) == 0)
		cout << "error";
	else
	{
		cout << "wordpad is running\n";
		unsigned long excode;
		GetExitCodeProcess(pinfo.hProcess, &excode);
		cout << "exitcode for wordpad's process is " << excode << endl;
		WaitForSingleObject(pinfo.hProcess, INFINITE);
		cout << "wordpad finished\n";
	}
	return 0;
}