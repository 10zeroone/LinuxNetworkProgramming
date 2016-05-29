//프로그램을 수행하는 사람의 정보를 확인하는 프로그램

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() { 
	char *name;
	struct passwd *pass;
	
	printf("UID: %d\n", getuid());
	
	pass = getpwuid(getuid()); 
	name = pass->pw_name; 
	printf("This is the login name: %s\n", name);
	
//	printf("Name: %s\n", getlogin()); //deprecated 된 함수입니다. 호출시 null만 반환됩니다.
	
	return 0; 
}



//출력결과
//이 프로그램은 UID 1000인 사용자 codedragon 실행하고 있음을 알 수 있습니다. 
/*
codedragon@ubuntu:~$ cd CodeLab/ch04/
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex03 Ex03.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex03
UID: 1000
This is the login name: codedragon
codedragon@ubuntu:~/CodeLab/ch04$
*/
