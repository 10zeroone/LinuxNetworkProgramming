//system() 함수의 사용법
//system() 함수를 이용하여 sleep 명령과 ls 명령을 수행하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	char cmd_buf[256];
	
	printf(" system() start -------------------- \n\n");
	//system() 함수를 이용하여 sleep 명령 수행
	strcpy(cmd_buf, "sleep 3");
	system(cmd_buf);
	
	//system() 함수를 이용하여 ls 명령 수행
	strcpy(cmd_buf, "ls");
	system(cmd_buf);
	//system() 함수는 새로운 프로세스를 생성하여 인자로 전달된 명령이나 실행 프로그램을 실행하고 종료될 때까지 
	//기다리는 함수입니다. 프로그램이 종료되면 새로 생성되었던 프로세스가 종료되고 system() 함수도 종료합니다.
	
	printf(" system() end --------------------  \n\n");
	return 0;
}


//출력 결과
//프로그램을 실행하면 ls 명령의 실행 결과가 3초 후에 나타납니다. 
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex01 Ex01.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex01
 system() start -------------------- 

Ex01  Ex01.c
 system() end --------------------  

codedragon@ubuntu:~/CodeLab/ch05$ 
*/
