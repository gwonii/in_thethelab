


#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void foo (int signum) {

		printf("자식이 죽음...\n");
		int status;
		wait(&status);
		printf("status : %d\n", status);
		
		printf("signum : %d\n", signum);
}



int main() {

		signal(SIGCHLD, foo);			// SIGCHLD는 child process의 상태가 변할 때 신호를 보낸다.
		int i;
		pid_t pid;					// pid_t 자료형의 역할은 무엇인가? 

		pid = fork();					// 프로세스 생성 

		printf("pid의 값은 : %d \n", pid);

		if(pid > 0) {
				//int status;
				//wait(&status);
				//printf("status: %d\n", status);

				for(i = 0; i < 20; ++i) {
						printf("parent process... \n");
						sleep(1);
				}
				exit(0);

		} else if (pid == 0){

				for(i = 0; i < 5; ++i) {
						printf("child process... \n");
						//pid = -2;							// pid 값은 사용자가 임의적으로 변경할 수 없다.
						sleep(1);
				}
				exit(0);
		} else {
				perror("fork");
				exit(0);  
		}

		printf("hello, world ....\n");

}
