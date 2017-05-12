#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	HANDLE mtx = CreateMutex(NULL, FALSE, TEXT("MUTEX"));
	cout << "checking mutex\n";
	cout.flush();
	WaitForSingleObject(mtx, INFINITE);
	cout << "mutex found\n";
	cout.flush();
	MessageBox(NULL, TEXT("program has mutex"), TEXT("MUTEX"), MB_OK);
	ReleaseMutex(mtx);
	CloseHandle(mtx);
}