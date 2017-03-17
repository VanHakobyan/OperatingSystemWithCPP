// ekran e durs berum @ntacik papkayi bolor fayleri anunner@, nshelov nranc chap@
// ev katalog linel@
#include <iostream>
#include <Windows.h>
using namespace std;

int main()
{
	HANDLE h, g; 
	int i;
	CHAR name[100], name2[100];
	WCHAR  fname[100], dirname[100];

	WIN32_FIND_DATA z;

	GetCurrentDirectory(100, fname);
	for (i = 0; i<100; i++)name[i] = CHAR(fname[i]);
	cout << name;
	cout << endl;


	g = FindFirstFile(TEXT("*.*"), &z);

	for (i = 0; i<100; i++)name[i] = CHAR(z.cFileName[i]);

	cout << name << endl << z.nFileSizeHigh << z.nFileSizeLow << endl;

	if (z.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
		cout << "directory\n";

	while (FindNextFile(g, &z))
	{
		for (i = 0; i<100; i++)name[i] = CHAR(z.cFileName[i]);
		cout << name << endl << z.nFileSizeHigh << z.nFileSizeLow << endl;
		if (z.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY)
			cout << "directory\n";
	}
	FindClose(g);

	return 0;
}