//좀 더 상세한 사용자의 정보알아내기
//좀 더 상세한 사용자의 정보를 알아 보기위해 getpwuid 함수와 getpwnam 함수를 이용한 프로그램

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

int main(void) {
	struct passwd *userinfo;

	userinfo = getpwuid(getuid()); //getpwuid() 함수 호출 시 getuid() 함수의 결과를 인자로 전달
	printf(
			"getpwuid():\nname = %s, uid = %d, gid = %d, home directory = %s, shell = %s\n",
			userinfo->pw_name, userinfo->pw_uid, userinfo->pw_gid,
			userinfo->pw_dir, userinfo->pw_shell);
	
	
	userinfo = getpwnam(userinfo->pw_name); //getpwnam() 함수 호출 시 getpwuid() 함수의 수행 결과를 인자로 전달
	printf(
			"\ngetpwname():\nname = %s, uid = %d, gid = %d, home directory = %s, shell = %s\n",
			userinfo->pw_name, userinfo->pw_uid, userinfo->pw_gid,
			userinfo->pw_dir, userinfo->pw_shell);

	return 0;
}



//출력 결과
//두 함수의 수행 결과 모두 이 프로그램을 실행하는 사용자의 이름은 codedragon이고 UID는 1000이며 GID와 홈디렉토리 위치 및 로그인 시 사용하는 쉘 종류를 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex04 Ex04.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex04
getpwuid():
name = codedragon, uid = 1000, gid = 1000, home directory = /home/codedragon, shell = /bin/bash

getpwname():
name = codedragon, uid = 1000, gid = 1000, home directory = /home/codedragon, shell = /bin/bash
codedragon@ubuntu:~/CodeLab/ch04$
*/

