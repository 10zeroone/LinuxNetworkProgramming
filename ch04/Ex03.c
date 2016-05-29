//���α׷��� �����ϴ� ����� ������ Ȯ���ϴ� ���α׷�

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

int main() { 
	char *name;
	struct passwd *pass;
	
	printf("UID: %d\n", getuid());
	
	pass = getpwuid(getuid()); 
	name = pass->pw_name; 
	printf("This is the login name: %s\n", name);
	
//	printf("Name: %s\n", getlogin()); //deprecated �� �Լ��Դϴ�. ȣ��� null�� ��ȯ�˴ϴ�.
	
	return 0; 
}



//��°��
//�� ���α׷��� UID 1000�� ����� codedragon �����ϰ� ������ �� �� �ֽ��ϴ�. 
/*
codedragon@ubuntu:~$ cd CodeLab/ch04/
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex03 Ex03.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex03
UID: 1000
This is the login name: codedragon
codedragon@ubuntu:~/CodeLab/ch04$
*/
