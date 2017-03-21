// 1. ancnel mi makardak verev ev tpel file parunakutyun@
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

	GetCurrentDirectory(100, fname);
	for (i = 0; i<100; i++)name[i] = CHAR(fname[i]);
	cout << "The current directory is: " << name << endl;

	g = FindFirstFile(TEXT("*.*"), &z);

	for (i = 0; i<100; i++)name[i] = CHAR(z.cFileName[i]);

	cout << name << endl << z.nFileSizeHigh << z.nFileSizeLow << endl;
	FileTimeToSystemTime(&z.ftCreationTime, &a);
	cout << a.wDay << '-' << a.wMonth << '-' << a.wYear << endl;

	if (z.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		cout << "directory\n";

	FindNextFile(g, &z);
	for (i = 0; i<100; i++)name[i] = CHAR(z.cFileName[i]);

	cout << name << endl << z.nFileSizeHigh << z.nFileSizeLow << endl;
	FileTimeToSystemTime(&z.ftCreationTime, &a);
	cout << a.wDay << '-' << a.wMonth << '-' << a.wYear << endl;

	if (z.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		cout << "directory\n";
	SetCurrentDirectory(z.cFileName);
	GetCurrentDirectory(100, fname);
	for (i = 0; i<100; i++)name[i] = CHAR(fname[i]);
	cout << "The current directory is: " << name << endl;


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