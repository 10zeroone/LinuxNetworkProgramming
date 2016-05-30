//리눅스 시스템의 현재 시각을 알아보는 프로그램
//초 단위의 시간으로 확인할 수 있는 time 함수와 마이크로세컨드까지 정밀하게 알아볼 수 있는 gettimeofday() 함수를 사용하여 구현
//------------------------------
/*
//struct timeval 구조체
#include <sys/time.h>
struct timeval {
	time_t tv_sec; // 초
	suseconds_t tv_usec; // 마이크로 초
};
*/

#include <stdio.h>
#include <unistd.h>
#include <time.h> //time()
#include <sys/time.h> //gettimeofday()


int main(void) {
	
	time_t current_time;
	struct timeval cur_gettimeofday;
	
	current_time = time(&current_time);
	//current_time = time((time_t *)0);
	printf("current seconds: %ld\n", current_time);
	
	
	gettimeofday(&cur_gettimeofday, NULL);
	printf("current seconds: %ld, micro seconds: %ld\n", 
			cur_gettimeofday.tv_sec, // 초
			cur_gettimeofday.tv_usec); // 마이크로 초
	
	return 0;
}


//실행 결과에서 알 수 있듯이
//time()과 gettimeofday() 함수로부터 알 수 있는 시간 정보는 사람들이 사용하는 연, 월, 일, 시, 분, 초 
//단위의 시간 정보가 아니라 시간 확인이 불편합니다.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex07 Ex07.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex07
current seconds: 1464539665
current seconds: 1464539665, micro seconds: 896101
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
//이런 형식으로 시간 정보를 표현해야 하는 경우에는 ctime(), localtime(), strftime() 등의 라이브러리 함수를 이용하여 시간 정보를 변환하여 사용하면 됩니다.
//이 시간 변환 함수에 대해서는 C 언어의 기초 과정에서 다루므로, 개인적으로 온라인 매뉴얼을 통해 자세한 사용 방법을 익히고 실습해보시기 바랍니다.

