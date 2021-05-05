#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mesg_buffer {
    long mesg_type;
    int a[4];
} message;

int main()
{
    FILE *f;
    f=fopen("eredmeny.txt","w");
    key_t key;
    int msgid;
    key = ftok("bead", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    int i=0;
    printf("\nData Received is :");
    for(i=0;i<4;i++)
    {
    printf("%d ",message.a[i]);
    }
    printf("\n ");
    msgctl(msgid, IPC_RMID, NULL);
    int tm[4];
    for(i=0;i<4;i++)
    {
    tm[i]=message.a[i];
    fprintf(f,"%d ",tm[i]);
    }
 
    fclose(f);
    return 0;
}
