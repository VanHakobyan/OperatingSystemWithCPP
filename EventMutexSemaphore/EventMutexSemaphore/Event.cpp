#include <iostream>
#include <Windows.h>
using namespace std;
int main(int argc, char* argv[])
{
	HANDLE ev = CreateEvent(NULL, FALSE, FALSE, TEXT("EVENT"));
	if (argc == 1)
	{
		cout << "waiting for event" << endl;      cout.flush();
		WaitForSingleObject(ev, INFINITE);
		cout << "event finished" << endl;      cout.flush();
	}
	else
	{
		cout << "set event\n";     SetEvent(ev);
	}
	CloseHandle(ev);
}
