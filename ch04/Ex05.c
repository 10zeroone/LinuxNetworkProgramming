//���� ���� ���α׷��� ������ ��ȣ�� PID�� �� �θ� ���μ����� PPID�� Ȯ���ϴ� ���α׷�

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
	
	printf("PID: %d\n", getpid()); //���� ����Ǵ� ���μ����� PID
	printf("PPID: %d\n", getppid()); //���� ����Ǵ� ���μ����� �θ� ���μ����� Parent PID(PPID)
	
	return 0;
}



//��� ���
//getpid() �Լ��� ������ �� ���μ����� PID�� 14074�̰� 
//getlppid() �Լ��� ������ PPID�� 13579�� ���� �� �� �ֽ��ϴ�.  
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex05 Ex05.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex05
PID: 14074
PPID: 13579
codedragon@ubuntu:~/CodeLab/ch04$ 
*/
