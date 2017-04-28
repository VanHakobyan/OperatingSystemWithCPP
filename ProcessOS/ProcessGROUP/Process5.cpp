#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;
int main()
{
	STARTUPINFO info;       PROCESS_INFORMATION pinfo;
	unsigned long excode;    memset(&info, 0, sizeof(info));
	info.cb = sizeof(info);         char cmd[300] = "notepad.exe";
	WCHAR cmdw[300];   for (int i = 0; i<300; i++) cmdw[i] = (WCHAR)cmd[i];
	if (CreateProcess(NULL, cmdw, NULL, NULL, FALSE,
		NORMAL_PRIORITY_CLASS, NULL, NULL, &info, &pinfo) == 0) cout << "error\n";
	else {
		cout << "notepad is running!\n";
		GetExitCodeProcess(pinfo.hProcess, &excode);
		cout << "exitcode for notepad's process is " << excode << endl;
		Sleep(5000); TerminateProcess(pinfo.hProcess, excode);
		cout << "notepade terminated!\n";
	} return 0;
}