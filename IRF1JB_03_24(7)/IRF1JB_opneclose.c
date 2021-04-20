#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    int fd, a;
    char b[32];
    b[0] = 0;
    fd = open("IRF1JB.txt",O_RDWR);
    if (fd==1)
    {
        perror("open()-el hiba van!");
        exit(-1);}
    a = read(fd,b,32);
    printf("read() olvasott %d byte-ot, ami a kovetkezo %s \n",a,b);
    strcpy(b,"IRF1JB");
    a = lseek(fd,0,SEEK_SET); 
    printf("lseek() mondja %d \n",a);
    a = write(fd,b,32);
    printf("write() mondja %d \n",a);
    close(fd);

    return 0;
}
