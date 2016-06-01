//디렉토리 제어 프로그램

#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <sys/stat.h> //mkdir()
#include <sys/types.h>
#include <unistd.h> //chdir()

int main(void) {

	char cmdbuff[256];
	char pathbuff[2024];

	//mkdir 함수를 이용해 "testdir" 디렉토리를 생성했습니다.
	mkdir("testdir", 0755);
	strcpy(cmdbuff, "ls -l | grep ");
	strcat(cmdbuff, "testdir");
	printf("%s\n", cmdbuff);
	system(cmdbuff);

	//chdir() 함수를 이용하여 testdir 디렉토리로 이동합니다.
	chdir("testdir");
	
	//getcwd 함수를 이용하여 현재 작업 디렉토리를 확인하고 출력하였습니다.
	if(getcwd(pathbuff, 1023)==NULL){
		perror("getwd");
		exit(1);
	}
	printf("Current Directory: %s\n", pathbuff);

	chdir("..");
	//rmdir() 함수를 이용하여 testdir 디렉토리를 삭제한 후 결과를 확인해 보면 현재 디렉토리에 testdir 디렉토리가 존재하지 않음을 알 수 있습니다. 
	rmdir("testdir");
	printf("%s\n", cmdbuff);
	system(cmdbuff);

	return 0;
}



//출력결과
//실행 결과에서 testdir 디렉토리가 생성되었음을 알 수 있습니다.
//rmdir() 함수를 이용하여 testdir 디렉토리를 삭제한 후 결과를 확인해 보면 현재 디렉토리에 testdir 디렉토리가 존재하지 않음을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch08$ gcc -o Ex05 Ex05.c 
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex05
ls -l | grep testdir
drwxr-xr-x 2 codedragon codedragon 4096 May 30 13:31 testdir
Current Directory: /home/codedragon/CodeLab/ch08/testdir
ls -l | grep testdir
codedragon@ubuntu:~/CodeLab/ch08$ 
*/
