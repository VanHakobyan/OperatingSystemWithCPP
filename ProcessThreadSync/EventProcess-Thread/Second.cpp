// second model

#include <iostream>
#include <process.h>
#include <Windows.h>
using namespace std;


void main()
{
	HANDLE h;
cout<<"second started\n";

h=CreateEvent(NULL,FALSE,FALSE,TEXT("event1"));

WaitForSingleObject(h,INFINITE);

for(int i=25;i<50;i++) {cout<<i+1<<"\t";}
	cout<<"second finished\n";
	CloseHandle(h);
}
