
#include <iostream>
#include <Windows.h>
#include <process.h>
#include <stdlib.h>
using namespace std;
void main(int argc, char *argv[])
{
	if (argc != 2) cout << "error in second\n";
	else
	{
		cout << "second started\n";
		cout << "argv[1]=" << argv[1] << endl;
		int k = atoi(argv[1]);
		//cout<<endl<<"k="<<k<<endl;
		HANDLE h = OpenProcess(PROCESS_QUERY_INFORMATION | SYNCHRONIZE, FALSE, k);
		if (h == INVALID_HANDLE_VALUE)
		{
			cout << "error\n";
		}
		else
		{
			cout.flush();
			WaitForSingleObject(h, INFINITE);
			cout << "second finished\n";
		}

	}
}