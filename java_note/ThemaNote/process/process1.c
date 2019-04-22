


#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>



int main() {
  int i;
  pid_t pid;			// pid_t 자료형의 역할은 무엇인가? 

  pid = fork();			// 프로세스 생성 

  printf("pid의 값은 : %d\n", pid);				// 기본적으로 처음의 pid 값은 양수의 값을
 												// 가지고 있음  

  if(pid > 0) {
    int status;
    wait(&status);
    printf("status: %d\n", status);
     	
	for(i = 0; i < 3; ++i) {
	  printf("parent process... \n");
	  sleep(1);
	}
	exit(0);

  } else if (pid == 0){
      for(i = 0; i < 5; ++i) {
	    printf("child process... \n");
		sleep(1);
	  }
	  sleep(1);
  } else {
      perror("fork");
	  exit(0);  
  }

  printf("hello, world ....\n");

}
