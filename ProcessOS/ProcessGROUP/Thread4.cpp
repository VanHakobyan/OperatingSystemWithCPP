#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;
void thread1(void * c)
{
	int i = (int)c;
	while (1) { cout << i << "\t"; i += 1; Sleep(10); }
}

void main()
{
	int c = 10;
	cout << "main1 started\n";
	_beginthread(thread1, 0, (void *)c);
	Sleep(5000);
	cout << "\n main1 finished\n";
}