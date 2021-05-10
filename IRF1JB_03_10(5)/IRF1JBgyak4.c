#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int f;

        if((f=fork())==0)
        {
        char *args[]={"./child.c",NULL};
        execvp(args[0],args);
        return 0;
        }
        waitpid(f, NULL, 0);

return 0;
}
