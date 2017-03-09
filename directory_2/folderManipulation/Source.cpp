// ekranin durs e berum yntacik folderi anunn
//ayl foldery darcnum yntacik
//stexcum e new folder
//jnjum e goyutyun unecox foldery
#include <iostream>
#include <Windows.h>
using namespace std;
int main()
{
	int i;
	CHAR name[100], name2[100];
	WCHAR fname[100], dirname[100];
	GetCurrentDirectory(100, fname);
	for (i = 0; i<100; ++i)
		name[i] = CHAR(fname[i]);
	cout << "The current directory is:" << name << endl;
	cout << "\nEnter name of new current directory:";
	cin >> name2;
	for (i = 0; i<100; ++i)
		dirname[i] = WCHAR(name2[i]);
	SetCurrentDirectory(dirname);
	cout << "the new current directory is:" << name2 << endl;
	cout << "\nEnter name of new directory: ";
	cin >> name2;
	for (i = 0; i<100; ++i)
		dirname[i] = WCHAR(name2[i]);
	CreateDirectory(dirname, NULL);
	cout << "\nEnter name of deleting directory:";
	cin >> name2;
	for (i = 0; i<100; ++i)
		dirname[i] = WCHAR(name2[i]);
	RemoveDirectory(dirname);
	return 0;

}