//fork 함수를 이용한 예제
//fork 시스템 콜을 이용하여 새로운 프로세스를 생성하는 프로그램


#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>

int main(void) {

	pid_t pid;
	
	switch (pid = fork()) { //fork 시스템 콜을 이용하여 새로운 프로세스를 생성
	case -1:
		perror("fork");
		break;
	case 0: // child process 
		//자식 프로세스에게는 0이 반환되므로 소스코드의 16~21번 줄을 수행합니다.
		printf("CHILD PROCESS : %d\n", getpid());
		sleep(3);
		system("echo CHILD"); //CHILD 문자열 표시
		system("ps -l"); //자식 프로세스에서 sleep()로 3초 후 ps –l 명령이 수행
		exit(0); //자식 프로세스는 exit 함수를 호출한 후 종료합니다. 
		break;
	default: // parent process
		//부모 프로세스에게는 자식 프로세스의 PID, 즉, 0보다 큰 값이 반환되므로 소스코드의 24~29번 줄을 수행합니다.
		printf("PARENT PROCESS: %d\n", getpid());
		printf("Return Value of fork: %d\n\n", pid);
		sleep(7);
		system("echo PARENT"); //PARENT 문자열 표시
		system("ps -l");
		break;
	}

	return 0;
}


//출력결과
//부모 프로세스에서 자신의 PID와 반환 값을 출력한 결과는 각각 16749와 16750입니다.
//자식 프로세스에서 자신의 PID를 출력한 결과는 16750로 부모 프로세스에서 확인한 fork() 함수의 반환 값과 일치하는 것을 알 수 있습니다.
//자식 프로세스에서 3초 후 ps –l 명령을 수행한 결과 ex02의 프로세스가 2개 수행되고 있으며, 두 프로세스 모두 S(Sleep) 상태임을 알 수 있습니다. 
//명령의 수행 결과 중 PID 와 PPID를 분석해보면 위쪽에 보이는 PID 16749번의 ex02가 부모 프로세스이고, 아래쪽에 보이는 PID 16750번의 ex02가 자식 프로세스임을 알 수 있습니다.
//7초 후 부모 프로세스에서 ps –l 명령을 수행한 결과를 분석해보면. 부모프로세스의 상태는 여전히 S(Sleep)상태이나 자식 프로세스는 종료되지 않고 Z(Zombie)상태로 남아있음을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex02 Ex02.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex02
PARENT PROCESS: 16749
Return Value of fork: 16750

CHILD PROCESS : 16750
CHILD
F S   UID    PID   PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  13579  13572  0  80   0 -  7396 wait   pts/3    00:00:00 bash
0 S  1000  16749  13579  0  80   0 -  1089 hrtime pts/3    00:00:00 Ex02
1 S  1000  16750  16749  0  80   0 -  1089 wait   pts/3    00:00:00 Ex02
0 S  1000  16752  16750  0  80   0 -  1127 wait   pts/3    00:00:00 sh
0 R  1000  16753  16752  0  80   0 -  8996 -      pts/3    00:00:00 ps
PARENT
F S   UID    PID   PPID  C PRI  NI ADDR SZ WCHAN  TTY          TIME CMD
0 S  1000  13579  13572  0  80   0 -  7396 wait   pts/3    00:00:00 bash
0 S  1000  16749  13579  0  80   0 -  1089 wait   pts/3    00:00:00 Ex02
1 Z  1000  16750  16749  0  80   0 -     0 -      pts/3    00:00:00 Ex02 <defunct>
0 S  1000  16755  16749  0  80   0 -  1127 wait   pts/3    00:00:00 sh
0 R  1000  16756  16755  0  80   0 -  8996 -      pts/3    00:00:00 ps

codedragon@ubuntu:~/CodeLab/ch05$ 
*/

