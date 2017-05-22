#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdlib.h>
using namespace std;
void main()
{
	STARTUPINFO x;
	PROCESS_INFORMATION y;
	char cmd[300] = "C:\\Users\\Van\\Source\\Repos\\OperatingSystemWithCPP\\FirstProcessCallSecondProcess\\Debug\\Second.exe ";
	ZeroMemory(&x, sizeof(x));
	x.cb = sizeof(x);
	int pid = GetCurrentProcessId();
	cout << "current process ID=" << pid << endl;
	char a[15];  _itoa_s(pid, a, 15, 10);
	strcat_s(cmd, a); cout << cmd << endl;
	WCHAR cmdw[300];
	for (int i = 0; i<300; i++) cmdw[i] = (WCHAR)cmd[i];
	cout << "first started\n";
	if (!CreateProcess(NULL, cmdw, NULL, NULL, FALSE, NORMAL_PRIORITY_CLASS, NULL, NULL, &x, &y))
		cout << "error\n";
	else
	{
		//cout << "first sleeping\n";
		//   cout.flush();
		int i = 0;
		while (true)
		{
			cout << "\t" << i << "\t"; i++;
			//Sleep(100);
		}
		cout << "first exiting\n";
	}
	cin.ignore();
	cin.ignore();
}