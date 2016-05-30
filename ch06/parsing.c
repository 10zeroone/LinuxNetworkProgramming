//TODO 3: 명령어 부분과 각 옵션 및 인자들을 공백 문자를 기준으로 분리시키기
//다음 단계에서는 쉘에서 명령을 입력 받으면 명령어 부분과 각 옵션 및 인자들을 공백 문자를 기준으로 분리해야 합니다.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ** command_parse(char *line) {
	int argcount = 0;
	char * token;
	char **arglist;

	if (line == NULL) {
		return NULL;
	}

	//문자열처리 라이브러리 함수 중 구분자를 기준으로 토큰을 잘라내는 함수인 strtok 함수를 이용합니다. 
	if ((token = strtok(line, " \t\n")) == NULL) {
		return NULL;
	}

	arglist = (char **) malloc(sizeof(char *));

	while (token != NULL) {
		arglist[argcount++] = strdup(token);
		//strtok() 함수의 첫 번째 인자에 NULL 값을 전달하여 연속적으로 토큰을 잘라냅니다.
		token = strtok(NULL, " \t\n");
		//realloc() 함수를 이용하여 동적 할당을 받은 메모리 공간을 다시 할당받습니다. 
		arglist = (char **) realloc(arglist, (argcount + 1) * sizeof(char *));
	}

	arglist[argcount] = NULL;
	return arglist;
}

void command_freelist(char **arglist) {

	int i;

	for (i = 0; arglist[i] != NULL; i++) {
		free(arglist[i]);
	}
	free(arglist);
}

