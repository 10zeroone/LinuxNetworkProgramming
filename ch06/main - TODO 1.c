//TODO 1: exit 명령 입력시 쉡을 종료하도록 구현
//첫 번째 단계로 사용자의 입력을 기다리는 무한 루프의 구조 프로그램으로 exit 명령 입력 시 쉘을 종료하도록 구현하기

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define MAXLINE 255

int main(void) {

	char line[MAXLINE];
	
	fputs("labshell> ", stdout);
	
	while(fgets(line, MAXLINE, stdin)){
		if(!strncmp(line, "exit", 4))
			exit(0);
		fputs(line, stdout);
		fputs("labshell> ", stdout);
	}
	return 0;
}


//TODO 2: 결과 확인하기
//exit 명령 입력시 쉡을 종료 확인하기
/*
codedragon@ubuntu:~/CodeLab/ch06$ gcc -o main main.c
codedragon@ubuntu:~/CodeLab/ch06$ ./main
labshell> 

labshell> ls
ls
labshell> dir
dir
labshell> exit
codedragon@ubuntu:~/CodeLab/ch06$ 
*/

