//자식 프로세스를 처리하면서 동시에 부모 프로세스에서도 일련의 작업 수행하기


#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

int main(void) {
	pid_t child_pid1, child_pid2, return_pid;
	int i=0;
	
	switch(child_pid1=fork()){
	case -1:
		perror("fork1");
		exit(1);
		break;
	case 0: //첫 번째 생성한 자식 프로세스는 긴 작업을 수행하는 프로세스
		printf("%d: Long time child process\n", getpid());
		sleep(10);
		exit(0);
		break;
	default:
		switch(child_pid2=fork()){
		case -1:
			perror("fork2");
			exit(1);
			break;
		case 0: //두 번째 생성한 자식 프로세스는 짧은 작업을 수행하는 프로세스
			printf("%d: Short time child process\n", getpid());
			sleep(1);
			exit(0);
			break;
		}
		while(1){ 
			//TODO 1: waitpid 함수에서 WNOHANG일때 결과확인하기
			//두 개의 자식 프로세스를 생성한 후 부모 프로세스에서는 반복문을 이용하여 더 이상 자식 프로세스가 존재하지 않을 때까지 waitpid 함수를 계속 호출합니다.
			//이때 인자로 WNOHANG 옵션을 전달했으므로 블록 되지 않고 계속 100000번에 한 번 씩 putchar('*');를 수행합니다. 
//			while((return_pid=waitpid(-1, NULL, WNOHANG))>0){
			//TODO 2: waitpid 함수에서 WNOHANG을 0으로 변경한 후 결과 확인하기
			while((return_pid=waitpid(-1, NULL, 0))>0){
				printf("\nReturn value of waitpid(): %d\n", return_pid);
			}
			if(errno==ECHILD){
				printf("No Child\n");
				break;
			}
			if(i==100000){
				putchar('*');
				fflush(stdout);
				i=0;
			}
			i++;
		}
		break;
	}
	return 0;
}




//TODO 1: waitpid 함수에서 WNOHANG일때 결과확인하기
//waitpid 함수를 이용하여 종료신호를 보낸 자식 프로세스를 처리하면서 동시에 부모 프로세스에서는 일련의 작업, 즉, putchar 함수 수행을 병행하고 있음을 의미합니다.
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex04 Ex04.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex04
17196: Short time child process
17195: Long time child process
*************************************************************************************************
Return value of waitpid(): 17196
**************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************************
Return value of waitpid(): 17195
No Child
codedragon@ubuntu:~/CodeLab/ch05$ 
*/


//TODO 2: waitpid 함수에서 WNOHANG을 0으로 변경한 후 결과 확인하기
//결과 화면에 문자 '*' 이 출력되지 않습니다.
//그 이유는 자식 프로세스가 모두 종료될 때까지 부모 프로세스는 블록되므로 소스 코드 47~52번 줄이 수행되지 않기 때문입니다. 
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex04 Ex04.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex04
17213: Short time child process
17212: Long time child process

Return value of waitpid(): 17213

Return value of waitpid(): 17212
No Child
codedragon@ubuntu:~/CodeLab/ch05$ 
*/
