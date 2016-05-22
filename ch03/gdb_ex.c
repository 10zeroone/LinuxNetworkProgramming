#include <stdio.h>
#include <stdlib.h>
#define MAX 256

int main(void)
{
	int n;
	char* buff;
	FILE *fp;

	if((fp=fopen("/etc/hosts", "r"))==NULL){
		printf("Can not open file\n");
		exit(1);
	}
	n=fread(buff, 1, MAX, fp);
	buff[n]='\0';
	printf("buf: %s\n", buff);
	fclose(fp);
	
	return 0;
}