//perror �Լ� ��
//close �Լ��� ȣ���� ������ ��� perror �Լ��� �̿��Ͽ� ���� �޽����� ����ϰ� ���α׷��� �����ϴ� ���α׷�
//-----------------------------------
//perror �Լ��� errno ������ ������ ���� �ؼ��Ͽ� ������ ���� �޽����� ������ֹǷ� ���α׷� ���� ó���� �ݵ�� �ʿ��� �Լ��Դϴ�. 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	int fd=3;
	
	if(close(fd)==-1){ //close �Լ��� ȣ���� ������ ���
		perror("close"); //perror �Լ��� �̿��Ͽ� ���� �޽����� ���
		exit(1); //���α׷��� ����
	}
	return 0;
}



// ��°��
/*
codedragon@ubuntu:~/CodeLab/ch04$ ./perrorex01
close: Bad file descriptor
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
