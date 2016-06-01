//TODO 1: exit 명령 입력시 쉡을 종료하도록 구현
//첫 번째 단계로 사용자의 입력을 기다리는 무한 루프의 구조 프로그램으로 exit 명령 입력 시 쉘을 종료하도록 구현하기

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
//TODO 6: command_parse() 함수외 command_freelist() 함수의 원형이 선언되어 있는 labshell.h 헤더 파일을 include합니다.
#include "labshell.h"

#define MAXLINE 255

int main(void) {

	char line[MAXLINE];
	//TODO 5-1
	int i;
	char** arglist;

	fputs("labshell> ", stdout);

	while (fgets(line, MAXLINE, stdin)) { //키보드 입력 받기
		if (!strncmp(line, "exit", 4))
			exit(0);
		//TODO 5-2: TODO 1에서 완성했던 main() 함수에 command_parse() 함수와 command_freelist() 함수를 적용하기
		if (arglist = command_parse(line)) { //command_parse()함수를 통해 명령어를 분석

			//TODO 11: 빌트인 명령을 위한 isbuiltin.c를 완성했으니  main() 함수에서 이 함수를 호출하도록 설정
			if (!check_builtin(arglist)) { //내장 명령인지 체크
				
				for (i = 0; arglist[i]; i++) {
					//TODO 16: 외부명령일 때 exec_command()함수 호출하도록 수정
					exec_command(arglist); 
//					printf("[%d]: %s\n", i, arglist[i]); //외부 명령일때 인수의 목록을 출력
				}
				command_freelist(arglist);
			}
		}
//		fputs(line, stdout);

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

