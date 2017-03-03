//text reversing
#include <iostream>
#include <windows.h>
using namespace std;
int main()
{
	unsigned long z;
	DWORD k;
	char buffer;
	CHAR name[100];
	WCHAR fname[100];
	cin >> name;
	for (int i = 0; i < 100; i++)
	{
		fname[i] = WCHAR(name[i]);
	}
	HANDLE h = CreateFile(fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE)
	{
		cout << "error\n";
	}
	else
	{
		k = SetFilePointer(h, -1, NULL, FILE_END);
		while (k > 0)
		{
			ReadFile(h, &buffer, 1, &z, NULL);
			cout << buffer;
			k = SetFilePointer(h, -2, NULL, FILE_CURRENT);
		}
		ReadFile(h, &buffer, 1, &z, NULL);
		cout << buffer;
		CloseHandle(h);
	}
	return 0;
}
Add Comment