//dup() 함수를 이용한 예제

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {
	
	int fd;
	char buffer[]="Hello dup function!!!\n";
	//"duptest" 파일을 쓰기전용으로 오픈했습니다
	if((fd=open("duptest", O_WRONLY|O_CREAT|O_TRUNC, 0666))==-1){
		perror("open");
		exit(1);
	}
	
	//1번 디스크립터를 해제
	close(1);
	//dup() 함수를 호출했으므로 1번 디스크립터도 duptest 파일을 가리키고 있습니다.
	dup(fd);
	//다시 fd를 해제했습니다.
	close(fd);
	//write() 함수를 이용하여 1번 디스크립터로 buffer의 내용을 저장
	write(1, buffer, strlen(buffer));
	//printf 함수로 문자열을 출력
	printf("This is dup() test file\n");

	return 0;
}


//출력결과
//프로그램을 수행시켜보면 화면에는 아무것도 출력되지 않습니다.
//"duptest" 파일을 열어보면 write() 함수와 print() 함수의 수행결과가 모두 이 파일에 저장되어 있음을 알 수 있습니다.
//이 예제는 0, 1, 2번 뿐 아니라 어떤 파일 디스크립터도 다른 디스크립터와 중첩이 가능합니다. 
/*
codedragon@ubuntu:~/CodeLab/ch08$ gcc -o Ex03 Ex03.c 
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex03
codedragon@ubuntu:~/CodeLab/ch08$ ls -l dup*
-rw-rw-r-- 1 codedragon codedragon 46 May 30 12:26 duptest
codedragon@ubuntu:~/CodeLab/ch08$ cat duptest 
Hello dup function!!!
This is dup() test file
codedragon@ubuntu:~/CodeLab/ch08$ 
*/
