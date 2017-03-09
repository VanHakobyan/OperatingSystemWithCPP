// 1. ekran e durs berum @ntacik folder-i  bolor fayleri kam subfolderner-i anunner@, nshelov nranc chap@,
//    stexcman or@,amis@, tarin ev subfolder linel@
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE h, g; int i;
	CHAR name[100], name2[100];
	WCHAR  fname[100], dirname[100];
	SYSTEMTIME a;
	WIN32_FIND_DATA z;


	g = FindFirstFile(TEXT("*.*"), &z);

	for (i = 0; i<100; i++)name[i] = CHAR(z.cFileName[i]);

	cout << name << endl << z.nFileSizeHigh << z.nFileSizeLow << endl;
	FileTimeToSystemTime(&z.ftCreationTime, &a);
	cout << a.wDay << '-' << a.wMonth << '-' << a.wYear << endl;

	if (z.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		cout << "directory\n";

	while (FindNextFile(g, &z))
	{
		for (i = 0; i<100; i++)name[i] = CHAR(z.cFileName[i]);
		cout << name << endl << z.nFileSizeHigh << z.nFileSizeLow << endl;
		FileTimeToSystemTime(&z.ftCreationTime, &a);
		cout << a.wDay << '-' << a.wMonth << '-' << a.wYear << endl;

		if (z.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
			cout << "directory\n" << endl;
	}
	FindClose(g);

	return 0;
}