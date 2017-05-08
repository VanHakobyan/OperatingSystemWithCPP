#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;
void thread1(void * c)
{
	int *a = (int*)c;
	int k = a[0];
	while (1) { for (int i = 1; i<k; i++) cout << a[i] << "\t"; Sleep(10); cout << endl; }
}

void main()
{
	int c[6]; c[0] = 6;
	for (int i = 1; i<6; i++)cin >> c[i];
	cout << "main1 started\n";
	_beginthread(thread1, 0, (void *)c);
	Sleep(5000);
	cout << "\n main1 finished\n";
}