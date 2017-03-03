//upper case handler

#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int i;
	unsigned long z, z1;
	char buffer;
	CHAR name[100];
	CHAR name1[100];
	WCHAR fname1[100];
	WCHAR fname[100];
	cin >> name;
	cin >> name1;
	for (i = 0; i < 100; ++i)
	{
		fname = WCHAR(name[i]);
		fname1 = WCHAR(name1[i]);
	}
	HANDLE h = CreateFile(fname, GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE)
		cout << "error" << endl;
	else
	{
		HANDLE a = CreateFile(fname1, GENERIC_WRITE,
			0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (a == INVALID_HANDLE_VALUE)
		{
			cout << "error1" << endl;
			CloseHandle(h);
		}
		else
		{
			ReadFile(h, &buffer, 1, &z, NULL);
			while (z != 0)
			{
				if (buffer >= 'A' && buffer <= 'Z')
					WriteFile(a, &buffer, 1, &z1, NULL);
				ReadFile(h, &buffer, 1, &z, NULL);
			}
			CloseHandle(a);
			CloseHandle(h);
		}
	}
	return 0;
}