//프로세스의 실행 시간 알아보기
//time 시스템 콜을 99999999번 호출하는데 소요되는 시간을 측정하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //time()
#include <sys/types.h>
#include <sys/times.h>

int main(void) {
	
	int i;
	time_t c_time;
	
	clock_t oldtime, newtime;
	struct tms oldtms, newtms;
	
	//for 반복문을 수행하기 전 times 함수를 호출하여 시간 측정
	if((oldtime=times(&oldtms))==-1){
		perror("old times");
		exit(1);
	}
	
	for(i=1; i<=99999999; i++)
		time(&c_time);
	//for 반복문이 끝낸 후 각각 times 함수를 호출하여 시간 측정
	if((newtime=times(&newtms))==-1){
		perror("new times");
		exit(1);
	}
	printf("Real Time: %ld clocks\n", newtime - oldtime);
	printf("User mode Time: %ld clocks\n", newtms.tms_utime - oldtms.tms_utime);
	printf("System mode Time: %ld clocks\n", newtms.tms_stime - oldtms.tms_stime);
	
	return 0;
}



//실행결과
//for 반복문을 수행하기 전과 반복문을 끝낸 후 각각 times 함수를 호출하여 시간을 측정한 후 그 시간을 
//확인해본 결과 실행 전체에는 23개의 clocks이 소요되었고, 그 중 21개의 clocks이 User mode에서 소요되었음을 알 수 있습니다.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex08 Ex08.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex08
Real Time: 23 clocks
User mode Time: 21 clocks
System mode Time: 0 clocks
codedragon@ubuntu:~/CodeLab/ch04$ 
*/


