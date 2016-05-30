//시스템에서 제공하는 자원의 제한 값을 확인하고 변경하는 프로그램
//-------------------------------------------------
/*
struct rlimit {
	rlim_t rlim_cur; //일반적으로 권고하는 소프트 권고치를 설정
	rlim_t rlim_max; //하드 제한치를 설정
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/resource.h>
#include <unistd.h>

void openfile_test(void);

int main(void) {
	
	struct rlimit mylimit;
	
	//자원의 종류를 RLIMIT_NPROC로 설정하여 getrlimit 함수를 호출한 결과 프로세스의 최대 개수를 알아냅니다.
	getrlimit(RLIMIT_NPROC, &mylimit);
	printf("Current Number of Process:\n softlimit( %ld ), hardlimit( %ld )\n",
			mylimit.rlim_cur, mylimit.rlim_max);
	
	//RLIMIT_NOFILE를 이용하여 호출하여 한 프로세스에서 동시에 오픈할 수 있는 파일의 개수을 알아냅니다.  
	getrlimit(RLIMIT_NOFILE, &mylimit);
	printf("Current Number of File:\n softlimit( %ld ), hardlimit( %ld )\n",
				mylimit.rlim_cur, mylimit.rlim_max);
	
	
	//setrlimit 함수를 이용하여 동시에 오픈할 수 있는 파일의 개수를 5개로 조정
	mylimit.rlim_cur = 5;
	setrlimit(RLIMIT_NOFILE, &mylimit);
	//openfile_test 함수를 이용하여 연속하여 파일을 계속 오픈 합니다.
	openfile_test();
	
	return 0;
}

void openfile_test(void){
	char *filename[6] = { "file1", "file2", "file3", "file4", "file5", "file6" };
	FILE *fp;
	int i;
	
	for(i=0; i<6; i++){
		if((fp=fopen(filename[i], "w"))==NULL){
			perror(filename[i]);
			exit(1);
		}
	}
	return ;
}


//출력결과
//자원의 종류를 RLIMIT_NPROC로 설정하여 getrlimit 함수를 호출한 결과 프로세스의 최대 개수가 3749임을 알 수 있습니다. 
//RLIMIT_NOFILE를 이용하여 호출한 결과 한 프로세스에서 동시에 오픈할 수 있는 파일의 개수는 1024개임을 알 수 있습니다.  
//setrlimit 함수를 이용하여 동시에 오픈할 수 있는 파일의 개수를 5개로 조정한 후 openfile_test 함수를 이용하여 파일을 계속 오픈해 
//보았습니다. 그 결과 test3 파일 생성 시 오류가 발생되는 것을 확인할 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex10 Ex10.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex10
Current Number of Process:
 softlimit( 3749 ), hardlimit( 3749 )
Current Number of File:
 softlimit( 1024 ), hardlimit( 65536 )
file3: Too many open files
codedragon@ubuntu:~/CodeLab/ch04$
*/
