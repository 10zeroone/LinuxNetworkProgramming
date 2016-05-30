//자식 프로세스에서 ls 명령 실행하기


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
	pid_t pid;

	pid = fork();
	switch (pid) {
	case -1:
		perror("fork()"); //fork 함수를 통해 자식 프로세스를 생성합니다.
		exit(-1);
		break;
	case 0: /* child process */
		printf("CHILD PROCESS\n");
		//자식 프로세스에서 execlp 함수를 이용하여 ex07 실행 코드를 ls 명령의 실행 코드로 교체하여 실행합니다. 
		execlp("ls", "ls", "-l", (char *)0);
		
		//execlp 함수의 수행결과와 상관없이 무조건 perror() 함수를 호출하고 있습니다.
		//execlp 함수가 교체에 실패하면 perror()을 수행하지만 교체에 성공한다면 perror()은 존재하지 않기 때문에 이렇게 실행해도 됩니다. 
		perror("execlp"); 
		exit(0);
		break;
	default: /* Parent Process */
		wait(NULL);
		printf("Child is dead\n");
		break;
	}
	return 0;
}



//자식 프로세스에서 ls 명령이 실행되었음을 확인할 수 있습니다. 
/*
codedragon@ubuntu:~/CodeLab/ch05$ gcc -o Ex07 Ex07.c 
codedragon@ubuntu:~/CodeLab/ch05$ ./Ex07
CHILD PROCESS
total 112
-rwxrwxr-x 1 codedragon codedragon 8704 May 29 15:31 Ex01
-rwxrw-rw- 1 codedragon codedragon  738 May 29  2016 Ex01.c
-rwxrwxr-x 1 codedragon codedragon 8904 May 29 17:02 Ex02
-rwxrw-rw- 1 codedragon codedragon 2152 May 30  2016 Ex02.c
-rwxrwxr-x 1 codedragon codedragon 9064 May 29 18:49 Ex03
-rwxrw-rw- 1 codedragon codedragon 1169 May 30  2016 Ex03.c
-rwxrwxr-x 1 codedragon codedragon 9168 May 29 19:39 Ex04
-rwxrw-rw- 1 codedragon codedragon 1664 May 30  2016 Ex04.c
-rwxrwxr-x 1 codedragon codedragon 8912 May 29 20:05 Ex05
-rwxrw-rw- 1 codedragon codedragon  816 May 30  2016 Ex05.c
-rwxrwxr-x 1 codedragon codedragon 8848 May 29 20:56 Ex06
-rwxrw-rw- 1 codedragon codedragon  972 May 30  2016 Ex06.c
-rwxrwxr-x 1 codedragon codedragon 8848 May 29 20:59 Ex07
-rwxrw-rw- 1 codedragon codedragon 1423 May 30  2016 Ex07.c
Child is dead
codedragon@ubuntu:~/CodeLab/ch05$ 
*/

