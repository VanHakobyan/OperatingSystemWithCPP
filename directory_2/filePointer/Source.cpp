
// stexnasharic mutq e anum fajli anun@, bacum ajn, 
//kardum simvolner@ hakarak kargov u grum ekranin
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	unsigned long z;
	int i; char buffer;
	CHAR name[100], q;
	DWORD k;
	WCHAR fname[100];
	cin >> name;
	for (i = 0; i<100; i++)
		fname[i] = WCHAR(name[i]);

	HANDLE h = CreateFile(fname, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE) cout << "error\n";
	k = SetFilePointer(h, -1, NULL, FILE_END);
	do
	{
		ReadFile(h, &buffer, 1, &z, NULL);
		cout << buffer;
		k = SetFilePointer(h, -2, NULL, FILE_CURRENT);
	} while (k != 0);

	ReadFile(h, &buffer, 1, &z, NULL); cout << buffer;

	CloseHandle(h);
	return 0;
}