#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define key  435686K 
	int semid,nsems,rtn;
	int semflg;
	struct sembuf sembuf, *sop;
	union semun arg;
	int cmd;

main()
{


	nsems = 1;
	semflg = 00666 | IPC_CREAT;
	semid = semget (key, nsems, semflg);
	if (semid < 0 ) {perror(" semget hiba"); exit(0);}
	else printf("\n semid: %d ",semid);
	printf ("\n");

	cmd = GETVAL;
	rtn = semctl(semid,0, cmd, NULL);

	printf("\n semval: %d ",rtn);
	printf("\n");

}
