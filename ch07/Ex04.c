//read()와 write()
//Ex03.c 예제에 read()와 write() 함수를 추가한 소스코드


#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h> //read(), close()

int main(void) {
	int fd, n;
	struct stat fbuff;
	char* buffer;

	//TODO 1: "/etc/hosts" 파일 오픈하기
	if((fd = open("/etc/hosts", O_RDONLY)) == -1) {
		perror("open1");
		fprintf(stderr, "File Read Fail.......\n");
	}else {
		printf("File Read Success!!! fd: %d\n", fd);
		
		//"/etc/hosts" 파일의 크기를 알아보기 위해 stat() 함수를 호출하여 크기만큼 동적 메모리를 할당했습니다.
		stat("/etc/hosts", &fbuff);
		buffer = (char*) malloc(fbuff.st_size);
		
		//read() 함수를 이용하여 오픈한 파일로부터 파일의 크기만큼 할당받은 메모리로 읽어들입니다. 
		read(fd, buffer, fbuff.st_size);
		close(fd);
	}

	//TODO 2: "myhosts" 파일 저장하기
	if((fd = open("myhosts", O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1){ //실패한 경우 수행
		perror("open2");
		fprintf(stderr, "File Create Fail.......\n");
	}else{ //성공한 경우 수행
		fprintf(stderr, "File Create Success!!! fd: %d\n", fd);
		
		//TODO 1에서 읽어 들인 내용을 write() 함수를 이용하여 "myhosts" 파일로 저장합니다. 
		write(fd, buffer, fbuff.st_size);
		close(fd);
	}
}


//출력결과
//실행 결과를 살펴보면 /etc/hosts 파일과 myhosts 파일의 크기가 동일한 것을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch07$ gcc -o Ex04 Ex04.c 
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex04
File Read Success!!! fd: 3
File Create Success!!! fd: 3
codedragon@ubuntu:~/CodeLab/ch07$ ls -l /etc/hosts myhosts
-rw-r--r-- 1 root       root       221 May 19 09:20 /etc/hosts
-rw-rw-r-- 1 codedragon codedragon 221 May 30 07:22 myhosts
codedragon@ubuntu:~/CodeLab/ch07$ 
*/
