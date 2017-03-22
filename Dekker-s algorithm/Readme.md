<p align="center">
<img src="http://jakob.engbloms.se/wp-content/uploads/2008/01/dekkersbug.png">
</p>

## Pseudocode


<tbody><tr>
<td colspan="2" align="left">
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre>    variables
        wants_to_enter : array of 2 booleans
        turn : integer

    wants_to_enter[0] ← false
    wants_to_enter[1] ← false
    turn ← 0   // or 1
</pre></div>
</td>
</tr>
<tr>
<td align="left">
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre>p0:
   wants_to_enter[0] ← true
   while wants_to_enter[1] {
      if turn ≠ 0 {
         wants_to_enter[0] ← false
         while turn ≠ 0 {
           // busy wait
         }
         wants_to_enter[0] ← true
      }
   }

   // critical section
   ...
   turn ← 1
   wants_to_enter[0] ← false
   // remainder section
</pre></div>
</td>
<td align="left">
<div class="mw-highlight mw-content-ltr" dir="ltr">
<pre>p1:
   wants_to_enter[1] ← true
   while wants_to_enter[0] {
      if turn ≠ 1 {
         wants_to_enter[1] ← false
         while turn ≠ 1 {
           // busy wait
         }
         wants_to_enter[1] ← true
      }
   }
 
   // critical section
   ...
   turn ← 0
   wants_to_enter[1] ← false
   // remainder section
</pre></div>
</td>
</tr>
</tbody>

### C++ implementation

```c++

#include <signal.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int Id; /* Segment Id */
int *TURN;
int *FLAG_I;
int *FLAG_J;

void get_out_of_critical(int i)
{
   if(i==0){
      *TURN=1;i=1;
      *FLAG_I=0;
   }
   else{
      *TURN=0;i=0;
      *FLAG_J=0;
   }

}

void get_in_critical(int i)
{
   if(i==0){
      *FLAG_I=1;
      while(*FLAG_J!=0){
           if(*TURN==1){
            *FLAG_I = 0;
            while(*TURN==1){}
         *FLAG_I=1;
         }
      }
   }
   else{
   *FLAG_J=1;
   while (*FLAG_I!=0){
         if(*TURN==0){
            *FLAG_J = 0;
            while(*TURN==0){}
         *FLAG_J=1;
         }
      }
   }

}

void process(int i)
{
   for(int k=1;k<=5;k++){
       get_in_critical(i);
       for(int m=1;m<=5;m++){
           cout<<"Process: "<<i+1<<", K.O. num: "<<k<<" ("<<m<<"/5)"<<endl;
                   //sleep(1);
      }
      get_out_of_critical(i);
   }
}


void del(int sig)
{
   /* free shared memory */
   (void) shmdt((char *) TURN);
   (void) shmdt((char *) FLAG_I);
   (void) shmdt((char *) FLAG_J);
   (void) shmctl(Id, IPC_RMID, NULL);
   exit(0);
}

int main()
{
   cout<<endl;
   /* allocating shared memory */
   Id = shmget(IPC_PRIVATE, sizeof(int)*100, 0600);

   if (Id == -1)
      exit(1);

   TURN = (int *) shmat(Id, NULL, 0);
   *TURN = 0;
   FLAG_I = (int*) shmat(Id, NULL, 0);
   FLAG_J = (int*) shmat(Id, NULL, 0);
   *FLAG_I = 0;
   *FLAG_J = 0;
   sigset(SIGINT, del);// in case of signal interrupt, delete shared memory

   /* starting paralel processes */
   if (fork() == 0) {
      process(0);
      exit(0);
   }
   if (fork() == 0) {
      process(1);
      exit(0);
   }
   wait();
   wait();
   del(0);

   return 0;
}
```


For more [this](https://en.wikipedia.org/wiki/Dekker%27s_algorithm)
