//first model
#include <iostream>
#include <process.h>
#include <Windows.h>
using namespace std;



void main()
{
	HANDLE h;

cout<<"first started\n";

h=CreateEvent(NULL,FALSE,FALSE,TEXT("event1"));

for(int i=0;i<25;i++){cout<<i+1<<"\t";}

cout<<"first finished\n";

SetEvent(h);

}
