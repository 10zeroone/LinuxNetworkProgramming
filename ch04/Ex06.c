//시스템의 사양 알아보기
//시스템의 사양에 대하여 알아보기 위해 gethostname()과 uname()함수를 사용한 프로그램
//gethostname() 함수를 이용하여 호스트 명에 대한 정보와 uname() 함수를 이용하여  OS 종류와 호스트명, 커널 버전, 빌드된 버전 및 하드웨어 종류를 알 수 있습니다. 

//----------------------
/*
//uname 함수에서 사용하는 struct utsname 구조체 자료형
#include <sys/utsname.h>
struct utsname {
	char sysname[]; //OS 종류
	char nodename[]; //호스트 명
	char release[]; //커널 릴리즈 번호
	char version[]; //커널 빌드 버전 번호
	char machine[]; //하드웨어 사양 (32bit/64bit)
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>


int main(void) {
	
	struct utsname mysystem;
	char myhostname[256];
	
	//gethostname() 함수를 이용하여 호스트 명에 대한 정보 알아오기
	if(gethostname(myhostname, 255)!=0){
		perror("gethostname");
		exit(1);
	}
	printf("gethostname: %s\n", myhostname);
	
	
	//uname() 함수를 이용하여  OS 종류와 호스트명, 커널 버전, 빌드된 버전 및 하드웨어 종류를 알아오기
	if(uname(&mysystem)==-1){
		perror("uname");
		exit(1);
	}
	printf("OS name: %s\n", mysystem.sysname); //OS 종류
	printf("hostname: %s\n", mysystem.nodename); //호스트 명
	printf("release: %s\n", mysystem.release); //커널 릴리즈 번호
	printf("version: %s\n", mysystem.version); //커널 빌드 버전 번호
	printf("hardware: %s\n", mysystem.machine); //하드웨어 사양 (32bit/64bit)
	
	return 0;
}


//실행 결과를 살펴보면 
//현재 OS는 리눅스이고 호스트명은 ubuntu, 커널 릴리즈 번호는 4.4.0-21-generic이며, 2016년 04월 18일에
//빌드되었고, 64비트 CPU가 장착된 시스템에서 동작 중임을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex06 Ex06.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex06
gethostname: ubuntu
OS name: Linux
hostname: ubuntu
release: 4.4.0-21-generic
version: #37-Ubuntu SMP Mon Apr 18 18:33:37 UTC 2016
hardware: x86_64
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
