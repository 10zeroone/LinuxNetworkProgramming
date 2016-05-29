//실행 중인 프로그램의 고유한 번호인 PID와 그 부모 프로세스의 PPID를 확인하는 프로그램

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	
	printf("PID: %d\n", getpid()); //현재 수행되는 프로세스의 PID
	printf("PPID: %d\n", getppid()); //현재 수행되는 프로세스의 부모 프로세스인 Parent PID(PPID)
	
	return 0;
}



//출력 결과
//getpid() 함수의 수행결과 이 프로세스의 PID는 14074이고 
//getlppid() 함수의 수행결과 PPID는 13579번 임을 알 수 있습니다.  
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex05 Ex05.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex05
PID: 14074
PPID: 13579
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
