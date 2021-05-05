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
    int tomb [3];
    FILE *ponter;
    ponter = fopen("IRF1JB","r");
    int i,j;

    for (i = 0; i < 3; i++)
    {
        fscanf(ponter, "%d ", &tomb[i]);
        
    }
    int tm[3];
    for(i=0;i<3;i++)
    {
       tm[i]=tomb[i];
    }
    for(i=0;i < 2;i++)
    {
        for(j=0;j<2;j++)
        {

            if(tomb[j]>tomb[j+1])
            {
                int cs = tomb[j];
                tomb[j]=tomb[j+1];
                tomb[j+1]=cs;
            }
        }
    }
    key_t key;
    int msgid;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;
    
        
    
    int a=tomb[0]+tomb[1];
    int b=tomb[2];
    if(b < a)
    {
    printf("%d < %d",b,a);

    for(i=0;i<3;i++)
    {
    message.a[i]=tm[i];
    }
    message.a[3]=0;

    }
    else
    {

    printf("%d > %d",b,a);
    for(i=0;i<3;i++)
    {
    message.a[i]=tm[i];
    }
    message.a[3]=1;
    
    }
    msgsnd(msgid, &message, sizeof(message), 0);
    fclose(ponter);
    return 0;
}
