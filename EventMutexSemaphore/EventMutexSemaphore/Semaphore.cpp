#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	HANDLE sem = CreateSemaphore(NULL, 3, 3, TEXT("Semaphore"));
	cout << "checking semaphore\n";
	cout.flush();
	WaitForSingleObject(sem, INFINITE);
	cout << "semaphore found\n";
	cout.flush();
	MessageBox(NULL, TEXT("semaphore is ok"), TEXT("Semaphore"), MB_OK);
	ReleaseSemaphore(sem, 1, NULL);
	CloseHandle(sem);


	return 0;
}