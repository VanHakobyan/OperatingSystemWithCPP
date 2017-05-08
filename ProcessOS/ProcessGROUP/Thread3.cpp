#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;
void thread1(void * c)
{
	int i = 1; char *x = (char*)c;
	while (1) { cout << x << "\t"; i += 1; Sleep(10); }
}

void main()
{
	char c[5] = "abcc";
	cout << "main1 started\n";
	_beginthread(thread1, 0, (void *)c);
	Sleep(5000);
	cout << "\n main1 finished\n";
}