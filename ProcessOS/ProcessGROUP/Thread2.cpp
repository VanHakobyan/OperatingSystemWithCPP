#include <iostream>
#include <windows.h>
#include <process.h>

void thread1(void *)
{
	int i = 0;
	while (1) {
		cout << i << "\t"; i += 2;
		Sleep(5);
	}
}

void thread2(void *)
{
	int i = 1;
	while (1) {
		cout << i << "\t"; i += 2;
		Sleep(5);
	}
}

void main()
{
	cout << "main started\n";
	_beginthread(thread1, 0, NULL);
	_beginthread(thread2, 0, NULL);
	Sleep(5000);
	cout << "\n main finished\n";
}