#include <iostream>
#include <windows.h>
#include <process.h>
using namespace std;


void thread1(void *)
{
int i=0;
while(1)  {cout<<i<<"\t"; i+=1;Sleep(10);}
}

void main()
{
cout<<"main1 started\n";
_beginthread(thread1,0,NULL);
Sleep(5000);
cout<<"\n main1 finished\n";
}
