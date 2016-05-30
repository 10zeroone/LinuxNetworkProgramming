//TODO 14: 새로운 프로세스를 생성하여 외부 명령을 수행할 수 있는 함수 작성
//exec_command()에서 전달받은 내용이 외부명령인지 판단했다는 전제하게 수행 코드 작성

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void exec_command(char** arg){ //명령을 인자로 전달 받을 때 명령과 옵션을 분리해서 목록 형태로 입력받습니다.
	
	pid_t pid;
	
	switch(pid=fork()){
	case -1: //fork()함수가 실패한 경우
		perror("fork"); //실패에 대한 메시지 출력
		break;
	case 0: //Child 프로세스를 의미하므로 Child 프로세스에서는 외부명령을 직접 실행하는 작업을 하게 됩니다.
		//exec관련 함수를 호출합니다.
		//명령과 옵션이 몇개가 들어올지 모르므로 벡터로 외부명령은 쉘의 환경변수인 PATH를 확용하기 위해 vp옵션을 사용하도록 하겠습니다.
		//arg[0]: 실행파일의 이름, arg: execv는 인수의 목록을 통재로 전달
		execvp(arg[0], arg); 
		//execvp()는 현재 실행되던 프로세스의 세그먼트 영역을 교체해서 수행하므로 실패하면 교체할 수 없으므로 기존의 코드를 그대로 수행하게 됩니다. 
		//실패한 경우 error 메시지를 출력후 바로 종료
		perror("execvp");
		exit(1);
		break;
	default: //반환값이 -1이나 0이 아닌경우는 Parent 프로세스를 의미합니다.
		//부모프로세스에서는 fork함수를 통해서 자식프로세스를 생성했으므로 당연히 wait함수를 수행해 주어야 합니다.
		//자식 프로세스 값(pid)을 알고 있으므로 waitpid로 구현하도록 하겠습니다.
		waitpid(pid, NULL, 0); //종료상태에 대해 처리할 것은 없으며(NULL), Child 프로세스가 종료될 때 기다리게 설정(0)
		break;
	}
}