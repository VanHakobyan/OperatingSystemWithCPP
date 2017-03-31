#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	char buffer;
	CHAR name[100];
	WCHAR fName[100];
	unsigned long z, z1;
	cin >> name;
	for (int i = 0; i<100; i++)
	{
		fName[i] = WCHAR(name[i]);
	}
	HANDLE h = CreateFile(fName, GENERIC_READ,
		0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE)
	{
		cout << "error in h" << endl;
		return 0;
	}

	HANDLE g = CreateFile(TEXT("D:\\Copy1.txt"), GENERIC_WRITE,
		0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (g == INVALID_HANDLE_VALUE)
	{
		cout << "error in g" << endl;
		CloseHandle(h);
		return 0;
	}
	SetFilePointer(h, -26, NULL, FILE_END);
	int counter = 0;
	while (counter != 15)
	{
		ReadFile(h, &buffer, 1, &z, NULL);
		if (buffer >= '0' && buffer <= '9')
		{
			WriteFile(g, &buffer, 1, &z1, NULL);
			counter++;
		}
		SetFilePointer(h, -2, NULL, FILE_CURRENT);
	}
	CloseHandle(h);
	CloseHandle(g);
	DeleteFile(fName);
	return 0;
}

