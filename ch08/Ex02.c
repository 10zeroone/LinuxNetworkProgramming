//터미널 장치의 속성을 제어하는 프로그램

#include <stdio.h>
#include <stdlib.h> 
#include <termio.h>

#define CR '\012' //엔터키

int main(int argc, char *argv[])
{
	struct termio tbuff, oldtbuff;
	char ch;
	
	//ioctl() 함수를 이용하여 현재 터미널 장치의 속성을 tbuf 변수에 얻어옵니다.
	//첫 번째 인자로 전달된 파일 디스크립터 0은 표준입력장치를 의미하는 번호입니다.
	if(ioctl(0, TCGETA, &tbuff)==-1){ 
		perror("ioctl");
		exit(1);
	}
	oldtbuff=tbuff;
	
{ //TODO 2: 최소 1문자만 입력되어도 입력이 완료된 것으로 간주하는 현재 블럭 코멘트 처리 후 결과 다시 확인하기
	tbuff.c_lflag &= ~ICANON; //터미널 모드를 ICANON 모드에서 RAW 모드로 변경
	tbuff.c_cc[VMIN]=1; //입력문자 수를 1로 지정
	tbuff.c_cc[VTIME]=0; //완료시간을 0으로 지정
	//터미널 장치의 속성 중 터미널 모드를 ICANON 모드에서 RAW 모드로 변경하고 입력문자 수를 1, 완료시간을 0으로 지정하여 
	//최소 1문자만 입력되어도 입력이 완료된 것으로 간주하도록 설정했습니다.
	if(ioctl(0, TCSETAF, &tbuff)==-1){
		perror("ioctl");
		exit(1);
	}
}
	
	
	//한 문자가 입력될 때마다 그 문자를 16진수 값으로 변환하여 출력
	while(1){
		ch=getchar();
		if(ch==CR) //<enter>키 입력시 종료
			break;
		printf("%x", ch);
	}
	
	//터미널 장치의 속성을 원래대로 복귀시키는 부분입니다
	if(ioctl(0, TCSETAF, &oldtbuff)==-1){
		perror("ioctl");
		exit(1);
	}
	
	return 0;
}



//TODO 1: 최소 1문자만 입력되어도 입력이 완료된 것으로 간주할 경우 결과 확인
//실행 결과를 살펴보면 a 문자를 입력하면 61이, b 문자를 입력하면 62가, c 문자의 경우에는 63등이 출력된 것을 확인할 수 있습니다.
//문자가 입력되자마자 getchar() 함수를 빠져나와 printf 함수를 수행했기 때문입니다. 
/*
codedragon@ubuntu:~/CodeLab/ch08$ gcc -o Ex02 Ex02.c 
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex02
a61b62c63d64e65f66
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex02
c63o6fd64e65d64r72a61g67o6fn6e
codedragon@ubuntu:~/CodeLab/ch08$ 
*/


//TODO 3: 코멘트 처리 후 결과
/*
codedragon@ubuntu:~/CodeLab/ch08$ gcc -o Ex02 Ex02.c 
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex02
codedragon
636f6465647261676f6ecodedragon@ubuntu:~/CodeLab/ch08$ 
*/

