//input array and output ASCII code
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int i, x[10]; unsigned long z;
	for (i = 0; i<10; i++)cin >> x[i];
	HANDLE h = CreateFile(TEXT("d:\\work\\osfiles\\b1.txt"),
		GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (h == INVALID_HANDLE_VALUE) cout << "error\n";
	else {
		char c[10]; for (i = 0; i<10; i++) c[i] = (char)x[i];
		for (i = 0; i<10; i++)
			WriteFile(h, &c[i], 1, &z, NULL);
		CloseHandle(h);
	}
	return 0;
}