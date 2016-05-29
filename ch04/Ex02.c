//환경 변수를 이용 함수인 getenv(), putenv()함수를 이용하여 사용자의 홈 디렉토리에 "test.log" 파일을 생성하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *homedir, filename[80];
	FILE *fp;
	homedir = getenv("HOME"); //쉘의 환경 변수 HOME을 이용하여 사용자의 홈 디렉토리의 경로를 알아오기
	strcpy(filename, homedir);
	strcat(filename, "/test.log"); //사용자의 홈 디렉토리의 경로를 알아내고 여기에 test.log 파일명을 추가하여 파일명을 완성합니다. 
	if ((fp = fopen(filename, "w")) == NULL) { //fopen 함수를 이용하여 이 파일을 "w"모드로 오픈시 오류가 있으면
		perror("fopen"); //errno 변수에 설정된 값을 해석하여 적절한 오류 메시지를 출력
		exit(1); //프로그램 종료
	}
	//fopen 함수로 파일 오픈시 오류가 없이 홈 디렉로리에 test.log 파일이 정상적으로 생성되는 경우
	fwrite("getenv test success\n", 20, 1, fp); //파일에는 "getenv test success"란 문자열을 저장합니다.  
	fclose(fp);
	
	return 0;
}


//출력결과
/*
PID와 그 부모 프로세스의 PPID를 확인
*/