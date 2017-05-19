// printing 121212
#include <iostream>
#include <process.h>
#include <Windows.h>
using namespace std;

int a[1000],i=0;
HANDLE h,g,f;
void first(void*)
{
	h=CreateEvent(NULL,FALSE,FALSE,TEXT("event1"));
	while(1)
	{
		a[i]=1;
		cout<<"\t i="<<i<<"  "<<a[i]<<"\t";
		i++; 
		if (i>=100) {SetEvent(f); break;}
		SetEvent(h);
		WaitForSingleObject(g,INFINITE);
	
	}
}

void second(void*)
{
	g=CreateEvent(NULL,FALSE,FALSE,TEXT("event2"));
	WaitForSingleObject(h,INFINITE);
	while(1)
	{
	a[i]=2;
	cout<<"\t i="<<i<<"  "<<a[i]<<"\t";
	i++;
	if (i>=100) {SetEvent(f); break;}
	SetEvent(g);
	WaitForSingleObject(h,INFINITE);
	}
}

void main()
{
h=CreateEvent(NULL,FALSE,FALSE,TEXT("event1"));

g=CreateEvent(NULL,FALSE,FALSE,TEXT("event2"));

f=CreateEvent(NULL,FALSE,FALSE,TEXT("event3"));

_beginthread(first,0,NULL);


_beginthread(second,0,NULL);

WaitForSingleObject(f,INFINITE);

cout<<endl<<"main printing\n";
for(i=0;i<100;i++) 
	//cout<<"\t mi="<<i<<" "<<a[i]<<"\t";
	cout<<a[i]<<"\t";
	CloseHandle(h);
CloseHandle(g);
CloseHandle(f);
}
