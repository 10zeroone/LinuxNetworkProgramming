//perror 함수 예
//close 함수의 호출이 실패한 경우 perror 함수를 이용하여 오류 메시지를 출력하고 프로그램을 종료하는 프로그램
//-----------------------------------
//perror 함수는 errno 변수에 설정된 값을 해석하여 적절한 오류 메시지를 출력해주므로 프로그램 오류 처리에 반드시 필요한 함수입니다. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int fd=3;
	
	if(close(fd)==-1){ //close 함수의 호출이 실패한 경우
		perror("close"); //perror 함수를 이용하여 오류 메시지를 출력
		exit(1); //프로그램을 종료
	}
	return 0;
}



// 출력결과
/*
codedragon@ubuntu:~/CodeLab/ch04$ ./perrorex01
close: Bad file descriptor
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
