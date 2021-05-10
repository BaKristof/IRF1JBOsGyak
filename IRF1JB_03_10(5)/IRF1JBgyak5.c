#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
void forke()
{

    if (fork() == 0)
        printf("Hello from Child!\n");

int main()
{
   if (fork() == 0)
   {
	exit(1);
   }
     if (fork() == 0)
   {
	abort();
   }  if (fork() == 0)
   {
	int a=60;
	int b=a/0;

   }
    return 0;
}
