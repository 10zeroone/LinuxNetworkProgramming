//실행 시 인자로 터미널 장치 파일명을 받아 문자열을 그 터미널로 출력하는 프로그램

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char buffer[2014];
	int fd, n;
	
	if(argc!=2){
		fprintf(stderr, "Usage: Ex01 device_filename\n");
		exit(1);
	}
	
	//open() 함수를 이용하여 일반 파일과 동일한 방법으로 오픈합니다.
	if((fd=open(argv[1], O_RDWR))==-1){
		perror("open");
		exit(1);
	}
	
	strcpy(buffer, "Hello, Terminal\n");
	n=strlen(buffer);
	//write() 함수를 이용하여 buffer의 내용을 출력합니다.  
	write(fd, buffer, n);
	close(fd);

	return 0;
}



//출력결과
//실행 결과를 살펴보면 위쪽 창은 /dev/pts/3 터미널 장치 파일을 이용 중이고, 아래쪽 창은 /dev/pts/5 장치 파일을 이용 중인 
//상태입니다. 
//실행 시 위쪽 창의 장치 파일명을 인자로 전달하면 일련의 문자열이 해당 터미널에 출력됩니다.
//아래쪽 터미널 장치 파일명을 인자로 전달했다면 일련의 문자열은 아래쪽 터미널 창으로 출력됩니다.
//이와 같이 터미널과 같은 장치 파일도 일반 파일과 동일하게 read(), write() 함수를 통해 장치와의 입출력을 수행할 수 있습니다. 
/* Terminal 1 (위쪽 터미널)
codedragon@ubuntu:~/CodeLab/ch08$ gcc -o Ex01 Ex01.c 
codedragon@ubuntu:~/CodeLab/ch08$ tty
/dev/pts/3
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex01 /dev/pts/3
Hello, Terminal
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex01 /dev/pts/5
codedragon@ubuntu:~/CodeLab/ch08$ 
*/
/* Terminal 2 (아래쪽 터미널)
codedragon@ubuntu:~$ tty
/dev/pts/5
codedragon@ubuntu:~$ Hello, Terminal
*/
