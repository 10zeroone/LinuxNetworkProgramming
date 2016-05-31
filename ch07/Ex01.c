//인자로 전달되는 파일의 정보를 확인하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char * argv[]) {
	struct stat fstatbuff;
	
	if(argc!=2){
		fprintf(stderr, "Usage: Ex01 filename\n");
		exit(1);
	}
	
	//stat() 함수를 이용하여 파일에 대한 정보를 stat 구조체 변수 fstatbuff에 받아옵니다.  
	if(stat(argv[1], &fstatbuff)==-1){
		perror(argv[1]);
		exit(1);
	}
	
	//구조체 멤버 중 st_mode 멤버를 이용하여 파일의 유형을 알아냅니다. 이때 매크로 함수를 사용합니다
	if(S_ISDIR(fstatbuff.st_mode))
		printf("%s is Directory\n", argv[1]);
	else if(S_ISREG(fstatbuff.st_mode))
		printf("%s is Regular File\n", argv[1]);
	else if(S_ISCHR(fstatbuff.st_mode))
		printf("%s is Character Device File\n", argv[1]);
	else if(S_ISBLK(fstatbuff.st_mode))
		printf("%s is Block Device File\n", argv[1]);
	
	//st_mode 멤버를 이용하여 파일의 권한을 확인합니다. 이때는 권한 관련 매스크를 사용합니다.  
	printf("Permission: ");
	if(fstatbuff.st_mode & S_IRUSR)
		putchar('r');
	if(fstatbuff.st_mode & S_IWUSR)
		putchar('w');
	if(fstatbuff.st_mode & S_IXUSR)
		putchar('x');
	putchar('\n');
	
	//stat 구조체에 저장된 파일의 inode, 파일 생성자와 파일의 크기 정보도 출력하기
	//%lu (unsigned long int)
	printf("inode: %lu, uid: %d, size: %lu\n", 
			fstatbuff.st_ino, fstatbuff.st_uid, fstatbuff.st_size);

	return 0;
}


//출력결과
//"/etc/passwd" 파일은 일반 파일(Regular File)로 파일을 생성한 사람이 읽기/수정하기(rw)가 가능하고 
//inode는 162216이고, 생성자의 UID는 0, 즉, root가 생성자이며 크기는 2255 바이트입니다. 
/*
codedragon@ubuntu:~/CodeLab/ch07$ gcc -o Ex01 Ex01.c 
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex01
Usage: Ex01 filename
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex01 /etc/passwd
/etc/passwd is Regular File
Permission: rw
inode: 162216, uid: 0, size: 2255
codedragon@ubuntu:~/CodeLab/ch07$
*/

