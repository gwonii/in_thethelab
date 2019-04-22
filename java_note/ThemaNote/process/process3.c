


#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int a = 42;

int main() {
  
  int b = 10;
  pid_t pid;					 

  pid = fork();					


  if(pid > 0) {
    a += 10;
    b += 10;	
	printf("parent a : %d, b : %d \n", a,b);
	sleep(1);	
  
  } else if (pid == 0){
	  printf("child a : %d, b : %d \n", a,b); 
	  
  } else {
      perror("fork");
	  exit(0);  
  }
}

// 각자의 프로세스가 각자의 환경을 가지고 있기 때문에 서로의 값은 공유하지 않는다.
