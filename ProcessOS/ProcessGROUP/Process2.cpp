#include <process.h>
#include <windows.h>
#include <iostream>
using namespace std;
int main()
{
	STARTUPINFO info;
	PROCESS_INFORMATION pinfo;
	memset(&info, 0, sizeof(info));
	info.cb = sizeof(info);
	char cmd[300] = "notepad.exe";
	WCHAR cmdw[300];
	for (int i = 0; i<300; i++) cmdw[i] = (WCHAR)cmd[i];
	if (CreateProcess(NULL, cmdw, NULL, NULL, FALSE,
		NORMAL_PRIORITY_CLASS, NULL, NULL, &info, &pinfo) == 0) cout << "error"; return 0;
}