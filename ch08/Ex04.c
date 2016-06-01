//인자로 전달된 파일명이 디렉토리인 경우 해당 디렉토리에 존재하는 파일의 목록을 출력하는 프로그램

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
	DIR *dirp;
	struct dirent *dirent;
	struct stat fstat;

	if(argc != 2) {
		fprintf(stderr, "Usage: Ex04 directoryname\n");
		exit(1);
	}
	
	//stat() 함수를 이용해 파일의 유형이 디렉토리인지 확인
	stat(argv[1], &fstat);
	if(!S_ISDIR(fstat.st_mode)) {
		fprintf(stderr, "%s is not Directory\n", argv[1]);
		exit(1);
	}
	
	//디렉토리인 경우 opendir() 함수를 이용하여 디렉토리를 오픈합니다.
	if((dirp = opendir(argv[1])) == NULL) {
		perror("opendir");
		exit(1);
	}
	
	//디렉토리에 저장되어있는 엔트리를 한번에 한씩 읽어와 출력
	while((dirent = readdir(dirp)) != NULL) {
		printf("inode: %ld, filename: %s\n", dirent->d_ino, dirent->d_name);
	}
	
	//closedir() 함수로 오픈되었던 디렉토리를 해제합니다.
	closedir(dirp);
	
	return 0;
}



//출력 결과
//실행 결과를 통해 현재 디렉토리에 존재하는 inode 값과 파일명을 확인할 수 있습니다. 
/*
codedragon@ubuntu:~/CodeLab/ch08$ gcc -o Ex04 Ex04.c 
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex04
Usage: Ex04 directoryname
codedragon@ubuntu:~/CodeLab/ch08$ ./Ex04 .
inode: 528923, filename: .
inode: 534909, filename: Ex04
inode: 534905, filename: Ex03.c
inode: 534896, filename: Ex02.c
inode: 534917, filename: Ex04.c
inode: 534887, filename: Ex02
inode: 529897, filename: Ex01
inode: 534903, filename: Ex03
inode: 534906, filename: duptest
inode: 524316, filename: ..
inode: 534877, filename: Ex01.c
codedragon@ubuntu:~/CodeLab/ch08$ 
*/
