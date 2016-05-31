//두 개의 파일을 오픈했다가 닫는 프로그램
//open() 과 close() 함수를 이용한 예제 프로그램


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h> //close()
#include <sys/stat.h>
#include <sys/types.h>

int main(void) {
	int fd;

	//TODO 1: "/etc/hosts" 파일을 읽기전용으로 오픈
	if((fd = open("/etc/hosts", O_RDONLY)) == -1){ //실패한 경우 수행
		perror("open1");
		fprintf(stderr, "File Read Fail.......\n");
	}else { //성공한 경우 수행
		//실행 결과를 보면 성공했으며 이때 받아온 파일 디스크립터가 3임을 알 수 있습니다.
		printf("File Read Success!!! fd: %d\n", fd); //File Read Success!!! fd: 3
		//TODO 4: 오픈한 파일을 close하지 않고 실행 결과를 확인하여 파일 디스크립터 확인하기 (close함수 주석처리하여 전후의 결과확인)
		close(fd);
	}
	
	//TODO 2: "myhosts" 파일을 쓰기 전용 및 생성 옵션과 기존의 내용을 삭제하는 옵션을 이용하여 오픈
	if((fd = open("myhosts", O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1){ //실패한 경우 수행
		perror("open2");
		fprintf(stderr, "File Create Fail.......\n");
	}else{ //성공한 경우 수행
		fprintf(stderr, "File Create Success!!! fd: %d\n", fd); //File Create Success!!! fd: 3
																//File Create Success!!! fd: 4
		close(fd);
	}
}



//TODO 3: 수행 결과 (이전에 오픈한 파일 close)
//수행 결과를 보면 TODO 1에서 오픈했던 파일을 닫았기(close) 때문에 다시 3번 디스크립터를 받아왔습니다.
/*
codedragon@ubuntu:~/CodeLab/ch07$ gcc -o Ex03 Ex03.c 
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex03
File Read Success!!! fd: 3
File Create Success!!! fd: 3
codedragon@ubuntu:~/CodeLab/ch07$ 
*/


//TODO 4: 수행 결과  (이전에 오픈한 파일 close하지 않은 경우)
/*
codedragon@ubuntu:~/CodeLab/ch07$ gcc -o Ex03 Ex03.c 
codedragon@ubuntu:~/CodeLab/ch07$ ./Ex03
File Read Success!!! fd: 3
File Create Success!!! fd: 4
codedragon@ubuntu:~/CodeLab/ch07$ 
*/

