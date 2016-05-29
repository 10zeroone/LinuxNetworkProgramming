//�� �� ���� ������� �����˾Ƴ���
//�� �� ���� ������� ������ �˾� �������� getpwuid �Լ��� getpwnam �Լ��� �̿��� ���α׷�

#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

int main(void) {
	struct passwd *userinfo;

	userinfo = getpwuid(getuid()); //getpwuid() �Լ� ȣ�� �� getuid() �Լ��� ����� ���ڷ� ����
	printf(
			"getpwuid():\nname = %s, uid = %d, gid = %d, home directory = %s, shell = %s\n",
			userinfo->pw_name, userinfo->pw_uid, userinfo->pw_gid,
			userinfo->pw_dir, userinfo->pw_shell);
	
	
	userinfo = getpwnam(userinfo->pw_name); //getpwnam() �Լ� ȣ�� �� getpwuid() �Լ��� ���� ����� ���ڷ� ����
	printf(
			"\ngetpwname():\nname = %s, uid = %d, gid = %d, home directory = %s, shell = %s\n",
			userinfo->pw_name, userinfo->pw_uid, userinfo->pw_gid,
			userinfo->pw_dir, userinfo->pw_shell);

	return 0;
}



//��� ���
//�� �Լ��� ���� ��� ��� �� ���α׷��� �����ϴ� ������� �̸��� codedragon�̰� UID�� 1000�̸� GID�� Ȩ���丮 ��ġ �� �α��� �� ����ϴ� �� ������ �� �� �ֽ��ϴ�.
/*
codedragon@ubuntu:~/CodeLab/ch04$ gcc -o Ex04 Ex04.c 
codedragon@ubuntu:~/CodeLab/ch04$ ./Ex04
getpwuid():
name = codedragon, uid = 1000, gid = 1000, home directory = /home/codedragon, shell = /bin/bash

getpwname():
name = codedragon, uid = 1000, gid = 1000, home directory = /home/codedragon, shell = /bin/bash
codedragon@ubuntu:~/CodeLab/ch04$
*/

