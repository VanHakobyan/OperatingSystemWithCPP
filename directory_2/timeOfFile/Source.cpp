//1. ekran e durs berum @ntacik amsativ@ ev jam@ 
// 2. ekran e durs berum nshvac fayli verjin dimelu (LastAccessTime) masin informacian
// 3. poxum e nshvac fayli stexcman amsativ@ @ntaciki
#include <iostream>
#include<Windows.h>
using namespace std;

int main()
{
	HANDLE h;
	FILETIME a, b, c, z1;
	SYSTEMTIME a1, b1, c1, z;

	GetSystemTime(&z);
	cout << "the current date is: " << z.wDay << '/'<<<<z.wMonth << '/' << z.wYear << endl;
	cout << "the current time is: " << z.wHour << ':' << z.wMinute << ': ' << z.wSecond << endl;

	h = CreateFile(TEXT("d:\\work\\os\\plan.docx"), GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h != INVALID_HANDLE_VALUE)
	{
		GetFileTime(h, &a, &b, &c);
		FileTimeToSystemTime(&a, &a1);
		FileTimeToSystemTime(&b, &b1);
		FileTimeToSystemTime(&c, &c1);
		cout << b1.wDay << '/' << b1.wMonth << '/' << b1.wYear << endl;
		cout << b1.wHour << ':' << b1.wMinute << ':' << b1.wSecond << endl;

		SystemTimeToFileTime(&z, &z1);

		SetFileTime(h, &z1, NULL, NULL);

		CloseHandle(h);
	}
	return 0;
}