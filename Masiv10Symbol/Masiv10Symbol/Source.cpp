//input 10 sybol masiv and output in file
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int i;	char x[10];	unsigned long z;
	for (i = 0; i < 10; i++)cin >> x[i];
	HANDLE h = CreateFile(TEXT("D:\\work\\osfiles\\a1.txt"),
		GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,
		NULL);
	if (h == INVALID_HANDLE_VALUE) cout << "error\n";
	else {
		WriteFile(h, x, 10, &z, NULL);	CloseHandle(h);
	}	return 0;
}