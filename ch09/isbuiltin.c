//TODO 10: 빌트인 명령을 구현하기 위한 소스코드

#include <stdio.h>
#include <string.h>
#include <pwd.h>
#include <sys/utsname.h>
#include "labshell.h"

//Builtin Command List
//빌트인 명령을 위한 bt_array 배열의 초기화 부분으로 hostname 명령은 hostname_func 함수에서 수행할 수 있도록 등록했습니다.  
BT_TYPE bt_array[]={
		"hostname", hostname_func, 
		NULL, 
		NULL
};

//check_builtin() 함수에서 사용자가 입력한 명령이 빌트인 명령인지 확인하고 이 명령인 경우 관련된 함수를 호출하도록 구현했습니다.
int check_builtin(char **arglist){
	int i;
	
	for(i=0; bt_array[i].cmd; i++){
		if(!strcmp(bt_array[i].cmd, arglist[0])){ //사용자가 입력한 명령이 빌트인 명령인지 확인
			//빌트인 명령인 경우 관련된 함수를 호출
			bt_array[i].bt_func(arglist);
			return 1; //함수 종료 시 빌트인 명령을 처리한 경우에는 1을 반환
		}
	}
	return 0; //빌트인 명령이 아닌 경우에는 0을 반환
}

//hostname_func() 함수에서는 uname() 함수를 이용하여 리눅스 시스템의 정보를 받아와 nodename 멤버에 있는 호스트명을 출력하도록 구현
void hostname_func(char **arg){
	struct utsname hostinfo;
	
	if(uname(&hostinfo)==-1){
		perror("uname");
		return;
	}
	printf("hostname: %s\n", hostinfo.nodename);
}