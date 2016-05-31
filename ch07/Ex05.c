//lseek() 함수를 이용하여 파일에 임의의 위치로 접근하는 프로그램


#include <stdio.h>
#include <stdlib.h> //exit()
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h> //read(), close()

#define MAX_SIZE 256

int main(void) {
	int fd, length;
	char buffer[MAX_SIZE];

	if((fd = open("myhosts", O_RDONLY)) == -1){
		perror("open");
		exit(1);
	}

	//TODO 1: 파일의 시작 위치를기준으로 10바이트 떨어진 위치로 옮깁니다.
	lseek(fd, 10L, SEEK_SET);
	//read() 함수를 이용하여 10바이트를 읽어 출력
	read(fd, buffer, 10);
	buffer[10]='\0';
	printf("SEEK_SET: %s\n", buffer);
	printf("------------------------\n\n");
	
	//TODO 3: 파일의 현재 위치에서 10바이트 이동하여 다시 10바이트를 읽습니다.
	lseek(fd, 10L, SEEK_CUR);
	read(fd, buffer, 10);
	buffer[10]='\0';
	printf("SEEK_CUR: %s\n", buffer);
	printf("------------------------\n\n");
	
	//TODO 5: 파일의 마지막 위치에서 역방향으로 10바이트 이전으로 이동하여 마지막 10바이트 읽어 출력하고 있습니다. 
	lseek(fd, -10L, SEEK_END);
	read(fd, buffer, 10);
	buffer[10]='\0';
	printf("SEEK_END: %s\n", buffer);
	printf("------------------------\n\n");
	close(fd);
	
	return 0;
}



//출력결과
//첫번째 실행 결과를 보면 원본 파일인 myhosts 파일의 첫 번째 줄에 있는 "localhost"입니다. 
//두번째 실행 결과를 살펴보면 두 번째 줄에 있는 "ubuntu"임을 알 수 있습니다.
//세번째 실행 결과를 살펴보면 "llrouters"임을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch07$ gcc -o Ex05 Ex05.c 
codedragon@ubuntu:~/CodeLab/ch07$ cat myhosts 
127.0.0.1        localhost
127.0.1.1        ubuntu

# The following lines are desirable for IPv6 capable hosts
::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex05
SEEK_SET: localhost

------------------------

SEEK_CUR: ubuntu

# 
------------------------

SEEK_END: llrouters

------------------------

codedragon@ubuntu:~/CodeLab/ch07$ 
*/
