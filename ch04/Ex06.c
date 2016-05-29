//�ý����� ��� �˾ƺ���
//�ý����� ��翡 ���Ͽ� �˾ƺ��� ���� gethostname()�� uname()�Լ��� ����� ���α׷�
//gethostname() �Լ��� �̿��Ͽ� ȣ��Ʈ �� ���� ������ uname() �Լ��� �̿��Ͽ�  OS ������ ȣ��Ʈ��, Ŀ�� ����, ����� ���� �� �ϵ���� ������ �� �� �ֽ��ϴ�. 

//----------------------
/*
//uname �Լ����� ����ϴ� struct utsname ����ü �ڷ���
#include <sys/utsname.h>
struct utsname {
	char sysname[]; //OS ����
	char nodename[]; //ȣ��Ʈ ��
	char release[]; //Ŀ�� ������ ��ȣ
	char version[]; //Ŀ�� ���� ���� ��ȣ
	char machine[]; //�ϵ���� ��� (32bit/64bit)
};
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <unistd.h>


int main(void) {
	
	struct utsname mysystem;
	char myhostname[256];
	
	//gethostname() �Լ��� �̿��Ͽ� ȣ��Ʈ �� ���� ���� �˾ƿ���
	if(gethostname(myhostname, 255)!=0){
		perror("gethostname");
		exit(1);
	}
	printf("gethostname: %s\n", myhostname);
	
	
	//uname() �Լ��� �̿��Ͽ�  OS ������ ȣ��Ʈ��, Ŀ�� ����, ����� ���� �� �ϵ���� ������ �˾ƿ���
	if(uname(&mysystem)==-1){
		perror("uname");
		exit(1);
	}
	printf("OS name: %s\n", mysystem.sysname); //OS ����
	printf("hostname: %s\n", mysystem.nodename); //ȣ��Ʈ ��
	printf("release: %s\n", mysystem.release); //Ŀ�� ������ ��ȣ
	printf("version: %s\n", mysystem.version); //Ŀ�� ���� ���� ��ȣ
	printf("hardware: %s\n", mysystem.machine); //�ϵ���� ��� (32bit/64bit)
	
	return 0;
}


//���� ����� ���캸�� 
//���� OS�� �������̰� ȣ��Ʈ���� ubuntu, Ŀ�� ������ ��ȣ�� 4.4.0-21-generic�̸�, 2016�� 04�� 18�Ͽ�
//����Ǿ���, 64��Ʈ CPU�� ������ �ý��ۿ��� ���� ������ �� �� �ֽ��ϴ�.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex06 Ex06.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex06
gethostname: ubuntu
OS name: Linux
hostname: ubuntu
release: 4.4.0-21-generic
version: #37-Ubuntu SMP Mon Apr 18 18:33:37 UTC 2016
hardware: x86_64
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
