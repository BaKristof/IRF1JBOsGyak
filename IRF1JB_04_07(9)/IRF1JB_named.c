#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MS 100


int main()
{
    int fd;
    char * fifo = "IRF1JB";

    mkfifo(fifo, 0666);
  
    char msg[] ="Bakos Kristóf";
    char ar[strlen(msg)+1];
        if(fork()==0)
        {
        
        fd = open(fifo, O_WRONLY);
  
        write(fd, msg, strlen(msg)+1);
        close(fd);
  	}
  
        fd = open(fifo, O_RDONLY);
  
        read(fd, ar, sizeof(ar));
  

        printf("Az üzenet: %s \n", ar);
        close(fd);
    return 0;
}
