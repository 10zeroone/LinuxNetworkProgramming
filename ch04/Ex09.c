//홈디렉토리 정보를 가져와 홈디렉토리에 현재 년월일로 된 파일 생성하기

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <time.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>

int main(void) {
	time_t c_time;
	struct tm *l_time;
	struct stat statbuf;
	char file_name[1024], date_time[10];
	char *home_dir;
	int fd;

	strcpy(file_name, getenv("HOME")); //현재의 홈이렉토리 정보를 가져와 file_name 배열에 저장

	time(&c_time); // time()함수를 통해 시간정보 언어오기
	l_time = localtime(&c_time); //time()함수로 얻어온값을 localtime()의 인자로 전달하여 struct tm 자료형으로 저장합니다.

	//l_time의 구조체의 시간 정보를 포멧(%Y%m%d)에 맞게 가공을 하여 date_time배열에 저장합니다.
	strftime(date_time, 1023, "/%Y%m%d", l_time);

#ifdef DEBUG
	printf("date_time: %s\n", date_time);
#endif
	strcat(file_name, date_time);

#ifdef DEBUG
	printf("filename: %s\n", file_name);
#endif
	if (stat(file_name, &statbuf) == -1) {
		if (errno == ENOENT) {
			fd = creat(file_name, 8666);
#ifdef DEBUG
			printf("file created!!!\n");
#endif
		} else {
			perror("stat");
			exit(1);

		}

	} else {
		if ((fd = open(file_name, O_RDWR)) == -1) { //해당 파일을 읽고 쓰기가능한 모드로 오픈
			perror("open");
			exit(1);
		}
#ifdef DEBUG
		printf("file opened!!! \n");
#endif
	}
	write(fd, "time test\n", 11); // 문자열 저장
	close(fd);

	return 0;
}



//출력결과
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex09 Ex09.c 
codedragon@ubuntu:~/CodeLab/ch04$ date
Sun May 29 12:04:17 PDT 2016
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex09
codedragon@ubuntu:~/CodeLab/ch04$ ls -l ~/20*
-rwx-wx--- 1 codedragon codedragon 11 May 29 12:04 /home/codedragon/20160529
codedragon@ubuntu:~/CodeLab/ch04$ cat ~/20160529 
time test
codedragon@ubuntu:~/CodeLab/ch04$ 
*/

