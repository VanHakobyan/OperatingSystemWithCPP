#include <windows.h>
#include <process.h>
#include <iostream>
using namespace std;
int main()
{
	//if (WinExec("notepad.exe",SW_SHOW)<31)cout<<"errror\n";
	//if (WinExec("notepad.exe a.txt",SW_SHOW)<31) cout<<"errror\n";

	//if (WinExec("C:\\Program Files\\Windows NT\\Accessories\\wordpad.exe",SW_SHOW)<31) cout<<"errror\n";
	if (WinExec("C:\\Program Files\\Windows NT\\Accessories\\wordpad.exe a.txt", SW_MAXIMIZE)<31) cout << "errror\n";

	//if (WinExec("C:\\Program Files\\Microsoft Office\\Office12\\WINWORD.EXE",SW_SHOW)<31) cout<<"errror\n";
	//if (WinExec("C:\\Program Files\\Microsoft Office\\Office12\\WINWORD.EXE a.txt",SW_MAXIMIZE)<31) cout<<"errror\n";


	return 0;
}
