#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h> //dup2()


//TODO 19 - 1단계:표준 입출력 재지정 기능과 관련된 함수인 redirectout() 함수부터 구현
//모니터로 출력할 내용을 파일에 저장할 수 있도록 구현
void redirectout(char** arg){
	int i, fd;
	
	//현재 전달된 명령 중에 "1>" 또는 ">" 가 포함되어 있는지 확인합니다.
	for(i=0; arg[i]; i++){
		if((strcmp(arg[i], "1>")==0) || (strcmp(arg[i], ">")==0)){
			
			//TODO  20 - 2단계: 입력된 명령 중 표준 출력재지정자 기호가 있는 경우 파일 중첩함수로 구현해 보겠습니다.
			//명령의 예시 (ls > ls.ok)
			//여기서 >는 출력 재지정자 기호, ls.ok는 저장할 파일명입니다. 즉, 파일명은 재지정자 기호 바로 다음 위치에 있습니다.
			//arg[i+1]: 명령의 수행결과를 저장할 파일명을 지정합니다. 이때 파일명은 출력 재지정자 기호 다음 위치에 전달됩니다. 
			if((fd=open(arg[i+1], O_WRONLY|O_CREAT|O_TRUNC, 0644))==-1){
				perror("open");
				return;
			}
			//파일 중첩함수로 파일 디스크립터 해제와 복사가 한번에 이루어지도록 dup2() 함수를 사용합니다. 
			//fd, 1 파일 디스크립터를 중첩해줌으로써 모니터로 출력할 내용을 파일로 저장하도록 구현
			dup2(fd, 1);
			close(fd);
			arg[i]=NULL;
			break;
		}
	}
}

//TODO 21 - 3단계: 앞서 완성한 redirectout() 함수를 기준으로 표준 입력 재지정자에 대한 처리함수인 redirectin() 함수를 완성
//키보드로 입력 받을 내용을 파일로 입력 받을 수 있도록 구현
void redirectin(char** arg){
	int i, fd;
	
	for(i=0; arg[i]; i++){
		if((strcmp(arg[i], "0<")==0)|| (strcmp(arg[i], "<"))){
			//입력을 받아올 파일의 오픈 플래그(O_RDONLY)를 지정
			if((fd=open(arg[i+4], O_RDONLY))==-1){
				perror("open");
				return;
			}
			//중첩 대상이 될 파일 디스크립터 번호는 0으로 지정
			//fd와 0번 파일 디스크립터를 중첩해 줌으로써 키보드로 입력받을 것을 파일로 부터 입력받을 수 있는 환경을 구현
			dup2(fd, 0);
			close(fd);
			arg[i]=NULL;
			break;
		}
	}
}

//TODO 22 - 4단계: 앞서 완성한 redirectout() 함수를 기준으로 표준 오류 재지정자에 대한 처리 함수 redirecterr() 함수 완성
//프로세스의 수행 결과 중 오류 메시지를 파일로 저장할 수 있도록 구현
void redirecterr(char** arg){
	int i, fd;
	
	for(i=0; arg[i]; i++){
		//표준 오류 재지정자 기호(2>) 입력
		if(strcmp(arg[i], "2>")==0){
			if((fd=open(arg[i+1], O_WRONLY|O_CREAT|O_TRUNC, 0644))==-1){
				perror("open");
				return;
			}
			//중첩 대상이 될 파일 디스크립터 번호는 2입니다. 
			//fd와 표준 에러 파일 디스크립터인 2번를 중첩해 줌으로써 프로세스의 수행 결과 중 오류 메시지를 파일로 저장할 수 있는 환경 구현
			dup2(fd, 2);
			close(fd);
			arg[i]=NULL;
			break;
		}
	}
}