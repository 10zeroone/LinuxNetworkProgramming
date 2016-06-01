//TODO 4: command_parse() 함수외 command_freelist() 함수의 원형을 선언할 헤더파일 작성하기

#ifndef LABSHELL_H_
#define LABSHELL_H_

char ** command_parse(char *line);
void command_freelist(char **arglist);

void redirectout(char** arg);
void redirectin(char** arg);
void redirecterr(char** arg);

//TODO 15:헤더파일에 선언문 추가
void exec_command(char** arg);

//TODO 9: 우선 빌트인 명령을 위해 다음과 같은 구조체와 관련 함수를 labshell.h 헤더파일에 선언하기
void hostname_func(char **);
int check_builtin(char **);

typedef struct bt_type{
	char *cmd;
	void (*bt_func)(char **);
}BT_TYPE;

#endif /* LABSHELL_H_ */
