


#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void foo(int signum) {
  int status;
  while (waitpid(0, &status, WNOHANG) > 0) {
    printf("status : %d \n" , status);
  }
}

int main() {
  
  signal (SIGCHLD, foo);
  int i;
  int j;
  pid_t pid;
  
  for (j = 0; j < 10; ++j) {
    pid = fork();	
	sleep(1);							// 5개의 자식 프로세스를 만들겠다. 

	if (pid == 0) {
	  for (i = 0; i < 5; ++i) {
	    printf("child process...\n");
	    sleep(1);
	  }
	  exit(0);
    } 
  }
  for (i = 0; i < 10; ++i){
    printf("prarent process...\n");
	sleep(1);
  }  
  exit(0);
}

// 각자의 프로세스가 각자의 환경을 가지고 있기 때문에 서로의 값은 공유하지 않는다.
