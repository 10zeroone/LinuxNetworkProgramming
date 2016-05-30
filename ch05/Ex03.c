//wait() 로 자식 프로세스까지 종료시키기
//자식 프로세스는 종료되지 않고 Z(Zombie)상태로 남아있는 것을 정상 종료시키기
//Ex02.c 코드에서 수정하여 작성하였으며 그 차이를 확인하시기 바랍니다.


#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	
	pid_t pid;
	int status;
	
	switch(pid=fork()){
	case -1:
		perror("fork");
		break;
	case 0:
		printf("CHILD PROCESS: %d\n", getpid());
		sleep(3);
		system("echo CHILD");
		system("ps -l");
		exit(0);
		break;
	default:
		printf("PARENT PROCESS: %d\n", getpid());
		printf("Return Value of fork: %d\n\n", pid);
		
		//부모 프로세스에 해당되는 부분의 sleep(7); 을 wait 함수로 변경하고, wait 함수에서 받아온 종료 상태 값을 분석하도록 수정했습니다.
		//이 프로그램을 실행해보면 자식 프로세스가 종료되자마자 부모 프로세스가 수행됨을 알 수 있습니다.
		wait(&status);
		//종료 상태의 값도 매크로를 이용하여 exit 함수에 의해 종료되었음을 확인할 수 있습니다.
		if(WIFEXITED(status)){
			printf("Child Process is deaded by exit()\n");
		}else if(WIFSIGNALED(status)){
			printf("Child Process is deaded by Signal\n");
		}
		system("echo PARENT");
		system("ps -l");
		break;
	}
	return 0;
}


/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex03 Ex03.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex03
PARENT PROCESS: 17041
Return Value of fork: 17042

CHILD PROCESS: 17042
CHILD
F S   UID    PID   PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  13579  13572  0  80   0 -  7398 wait   pts/3    00:00:00 bash
0 S  1000  17041  13579  0  80   0 -  1089 wait   pts/3    00:00:00 Ex03
1 S  1000  17042  17041  0  80   0 -  1089 wait   pts/3    00:00:00 Ex03
0 S  1000  17044  17042  0  80   0 -  1127 wait   pts/3    00:00:00 sh
0 R  1000  17045  17044  0  80   0 -  8996 -      pts/3    00:00:00 ps
Child Process is deaded by exit()
PARENT
F S   UID    PID   PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  13579  13572  0  80   0 -  7398 wait   pts/3    00:00:00 bash
0 S  1000  17041  13579  0  80   0 -  1089 wait   pts/3    00:00:00 Ex03
0 S  1000  17047  17041  0  80   0 -  1127 wait   pts/3    00:00:00 sh
0 R  1000  17048  17047  0  80   0 -  8996 -      pts/3    00:00:00 ps
codedragon@ubuntu:~/CodeLab/ch05$ 
*/

