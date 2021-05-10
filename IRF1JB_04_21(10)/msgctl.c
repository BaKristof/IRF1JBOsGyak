#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MSGKEY 654321L

main()
{
	int msgid, msgflg,  rtn;
	key_t key;
	key = MSGKEY;
	msgflg = 00666 | IPC_CREAT;
	msgid = msgget( key, msgflg);
	
	rtn = msgctl(msgid, IPC_RMID, NULL);
	printf ("\n Vissztert: %d", rtn);

	exit (0);
}
