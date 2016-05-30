//exit 함수의 종료 코드 값을 확인하기

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
	int status;
	
	switch(fork()){
	case -1:
		perror("fork");
		exit(1);
		break;
	case 0:
		sleep(3);
		//TODO 1: exit(0);일때 종료 코드 값을 확인하기
		exit(0);
		//TODO 2: exit(1);일때 종료 코드 값을 확인하기
//		exit(1);
		break;
	default:
		wait(&status);
		if(WIFEXITED(status)){
			//부모 프로세스 수행 시 자식 프로세스가 exit(0) 함수를 통해 전달한 종료 코드가 0임을 알 수 있습니다.
			//즉, 자식 프로세스의 	종료 코드를 부모 프로세스의 wait 함수를 통해 확인할 수 있습니다.
			printf("Exit code of Child process: %d\n", WEXITSTATUS(status));
		}
	}
	
	return 0;
}


//TODO 1: exit(0);일때 종료 코드 값을 확인하기
//부모 프로세스 수행 시 자식 프로세스가 exit(0) 함수를 통해 전달한 종료 코드가 0임을 알 수 있습니다.
//즉, 자식 프로세스의 종료 코드를 부모 프로세스의 wait 함수를 통해 확인할 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex05 Ex05.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex05
Exit code of Child process: 0
codedragon@ubuntu:~/CodeLab/ch05$ 
*/


//TODO 2: exit(1);일때 종료 코드 값을 확인하기
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex05 Ex05.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex05
Exit code of Child process: 1
codedragon@ubuntu:~/CodeLab/ch05$ 
*/


