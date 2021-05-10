#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        execl("./child.c","child",(char *)NULL);

return 0;
}
