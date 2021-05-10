#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#define MS 100
char* msg ="Bakos Kristóf IRF1JB";
  
int main()
{
    char inbuf[MS];
    int p[2], i;
    pipe(p);
  if(fork()==0)
  {
      write(p[1], msg, MS);
  }
  


    close(p[1]);    
        read(p[0], inbuf, MS);
        printf("%s \n", inbuf);
    return 0;
}
