//자식 프로세스에서 ps 명령 실행하기


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;

	pid = fork();
	switch (pid) {
	case -1:
		perror("fork()"); //fork 함수를 통해 자식 프로세스를 생성합니다.
		exit(-1);
		break;
	case 0: /* child process */
		printf("CHILD PROCESS\n");
		//자식 프로세스에서 execlp 함수를 이용하여 ex06 실행 코드를 ps 명령의 실행 코드로 교체하여 실행합니다. 
		execlp("ps", "ps", (char *) 0);
		
		//execlp 함수의 수행결과와 상관없이 무조건 perror() 함수를 호출하고 있습니다.
		//execlp 함수가 교체에 실패하면 perror()을 수행하지만 교체에 성공한다면 perror()은 존재하지 않기 때문에 이렇게 실행해도 됩니다. 
		perror("execlp"); 
		exit(0);
		break;
	default: /* Parent Process */
		wait(NULL);
		printf("Child is dead\n");
		break;
	}
	return 0;
}



//자식 프로세스에서 ps 명령이 실행되었음을 확인할 수 있습니다. 
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex06 Ex06.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex06
CHILD PROCESS
   PID TTY          TIME CMD
 13579 pts/3    00:00:00 bash
 17508 pts/3    00:00:00 Ex06
 17509 pts/3    00:00:00 ps
Child is dead
codedragon@ubuntu:~/CodeLab/ch05$ 
*/

