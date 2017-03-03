// input path of the file --> file open
//write 10 sybol and write console
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	unsigned long z;
	int i; char buffer[10];
	CHAR name[100];
	WCHAR fname[100];
	cin >> name;
	for (i = 0; i<100; i++)
		fname[i] = WCHAR(name[i]);

	HANDLE h = CreateFile(fname, GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE) cout << "error\n";
	else {

		ReadFile(h, buffer, 10, &z, NULL);

		for (i = 0; i<10; i++)
			cout << buffer[i];

		CloseHandle(h);
	}
	return 0;
}