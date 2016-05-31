//파일의 정보를 변경하는 프로그램

#include <stdio.h> 
#include <stdlib.h> //system()
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void) {

	struct stat fstatbuff;
	
	system("touch data; ls -l data");

	//stat() 함수를 이용하여 data 파일의 정보를 얻어옵니다.
	stat("data", &fstatbuff);
	printf("\nchmod()\n");
	//chmod() 함수를 이용하여 생성자 및 같은 그룹 사용자에게 실행 권한을 추가로 설정했습니다.
	chmod("data", fstatbuff.st_mode|S_IXUSR|S_IXGRP);
	system("ls -l data");
	
	//link() 함수의 수행결과로 만들어진 data1 파일은 data 파일의 inode와 동일함을 알 수 있습니다.
	link("data", "data1");
	
	//symlink() 함수를 통해 심볼릭 링크했던 data2 파일의 inode 값은 data 파일과 다르며 마지막 필드에 나타난 파일명에서 원본 파일의 이름을 가리킵니다.
	symlink("data", "data2");

	printf("\nlink() & symlink()\n");
	system("ls -li data data1 data2");

	return 0;
}


//출력결과
//data 파일의 기본 권한에는 실행 권한이 없었으나 chmod() 함수 수행 후 생성자와 그룹의 실행(x) 권한이 추가로 부여되었음을 알 수 있습니다. 
//link() 함수의 수행결과로 만들어진 data1 파일은 data 파일의 inode와 동일함을 알 수 있습니다.
//symlink() 함수를 통해 심볼릭 링크했던 data2 파일의 inode 값은 data 파일과 다르며 마지막 필드에 나타난 파일명에서 원본 파일의 이름을 가리키고 있음을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch07$ gcc -o Ex02 Ex02.c 
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex02
-rw-rw-r-- 1 codedragon codedragon 0 May 30 04:38 data

chmod()
-rwxrwxr-- 1 codedragon codedragon 0 May 30 04:38 data

link() & symlink()
527688 -rwxrwxr-- 2 codedragon codedragon 0 May 30 04:38 data
527688 -rwxrwxr-- 2 codedragon codedragon 0 May 30 04:38 data1
527689 lrwxrwxrwx 1 codedragon codedragon 4 May 30 04:38 data2 -> data
codedragon@ubuntu:~/CodeLab/ch07$ 
*/
