
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>


// thread 만들어 사용하기 

int i;

void *foo(void *arg) {

  
  for(i = 0; i < 3; ++i){
    sleep(1);
	printf("hello, world...\n");
  }
  return 0;
}

int main() {
  pthread_t thread;
  pthread_create(&thread, NULL, foo, NULL);
  pthread_detach(thread);

  for(i = 0; i < 5; ++i){
    sleep(1);
	printf("main...\n");
  }
}
