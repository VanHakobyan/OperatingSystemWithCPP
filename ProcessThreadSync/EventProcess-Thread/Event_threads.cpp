//Event_threads


#include <iostream>
#include <process.h>
#include <Windows.h>
using namespace std;

int a[50];
HANDLE h,g;
void first(void*)
{
h=CreateEvent(NULL,FALSE,FALSE,TEXT("event1"));
cout<<"first started\n";
for(int i=0;i<25;i++){a[i]=i+1; cout<<a[i]<<"\t";}
cout<<"first finished\n";
SetEvent(h);
}

void second(void*)
{
g=CreateEvent(NULL,FALSE,FALSE,TEXT("event2"));
	WaitForSingleObject(h,INFINITE);
	cout<<"second started\n";
	for(int i=25;i<50;i++) {a[i]=i+1;cout<<a[i]<<"\t";}
	cout<<"second finished\n";
SetEvent(g);
}

void main()
{
h=CreateEvent(NULL,FALSE,FALSE,TEXT("event1"));


g=CreateEvent(NULL,FALSE,FALSE,TEXT("event2"));


_beginthread(first,0,NULL);

_beginthread(second,0,NULL);

WaitForSingleObject(g,INFINITE);

for(int i=0;i<50;i++) cout<<a[i]<<"\t";
CloseHandle(h);
CloseHandle(g);
}

