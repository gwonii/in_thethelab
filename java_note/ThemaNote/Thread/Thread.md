# Thread

# 3. Thread

------

## 3.1 Thread란?

- 프로세스 내에서 실행되는 여러 흐름의 단위 
- 프로세스의 수행경로
- 프로세스가 할당받은 자원을 이용하는 실행의 단위 

![thread](C:\Users\hoho\Desktop\thread.png)

## 3.2 Thread의 특징

- 스레드는 프로세스 내에서 각각 stack에만 따로 할당받고 code, data, heap 영역은 공유한다. 
- 프로세스 내의 주소 공간이나 자원들을 같은 프로세스 내에 스레드끼리 공유하면서 실행된다.
- 각각의 스레드는 별도의 레지스터와 스택을 갖고 있다. 

## 3.3 Multi Thread

- 하나의 응용프로그램을 여러 개의 스레드로 구성하고 각 스레드로 하여금 하나의 작업을 처리하도록 하는 것이다. 
- 대부분의 운영체제에서 멀티 스레딩을 기본적으로 사용하고 있다. 

### 3.3.1 장점

- 시스템 자원 소모 감소 (자원의 효율성 증대)
  - 프로세스를 생성하여 자원을 할당하는 시스템 콜이 줄어들어 자원을 효율적으로 관리할 수 있다. 
- 시스템 처리량 증가 (처리 비용 감소)
  - 스레드 간 데이터를 주고 받는 것이 간단해지고 시스템 자원 소모가 줄어들게 된다. 
  - 스레드 사이의 작업량이 작아 Context Switching이 빠르다. 
- 간단한 통신 방법으로 인한 프로그램 응답 시간 단축 
  - 스레드는 프로세스 내에 stack 영역을 제외한 모든 메모리를 공유하기 때문에 통신의 부담이 적다. 

### 3.3.2 단점

- 주의깊은 설계가 필요하다. 
- 디버깅이 까다롭다. 
- 단일 프로세스 시스템의 경우 효율성을 기대하기 어렵다. 
- 멀티 스레드의 경우 공유 자원의 문제가 생길 수 있다. (동기화 문제)
- 하나의 스레드에 문제가 발생하면 전체 스레드에 영향을 주어 프로세스에 문제가 생긴다. 

> <https://gmlwjd9405.github.io/2018/09/14/process-vs-thread.html>

## 4. 구현 

- 기본적으로 <pthread.h> 헤더 파일을 통해 스레드를 생성할 수 있다. 
- 새로운 스레드를 생성하지 않는다면 main 함수를 실행시키는 main(primary) thread가 자동적으로 생긴다. 
- pthread_create를 통해 새로운 스레드를 생성시킬 수 있다. 
- pthread_join을 통해 스레드를 관리할 수 있다. 

### pthread_create 

```c
int pthread_create(pthread_t *th_id, const phtread_attr_t *attr, 
					void *함수명, void *arg);

// 첫번째 인자, pthread_t *th_id
// pthread 식별자로 thread가 성공적으로 생성되면 thread 식별값이 주어진다. 

// 두번째 인자, const pthread_attr_t *attr
// pthread 속성(옵션), 기본적인 thread 속성을 사용할 경우 NULL

// 세번째 인자, void *함수명
// pthread로 분기할 함수. 반환값이 void* 타입이고
// 매개변수도 void* 으로 선언된 함수만 가능하다. 

// 네번째 인자, void *arg
// 분기할 함수로 넘겨줄 인자값. 어떤 자료형을 넘겨줄 지 모르기 때문에 
// void 형으로 넘겨주고 상황에 맞게 분기하는 함수내에서 원래의 자료형으로 
// 캐스팅해서 사용하면 된다. 
```

### pthread_join

```c
int pthread_join(pthread_t th_id, void** thread_return);

// 첫번째 인자, pthread_t th_id
// 어떤 pthread를 기다릴지 정하는 식별자 

// 두번째 인자, pthread의 return 값, 포인트로 값을 받아오는 점에 주의하라

// 특징
// pthread가 종료될 때까지 기다리다가 특정 pthread가 종료시 자원을 해제시켜준다.
```

### pthread_detach

```c
int pthread_detach(pthread_t th_id);

// th_id 식별자를 가지는 pthread가 부모 pthread로부터 독립한다. 
// 즉, 이렇게 독립된 pthread는 따로 pthread_join()이 없어도 종료시
// 자동으로 자원을 해제한다. 
```

### pthread_exit

```c
void pthread_exit(void *ret_value);

// 현재 실행중인 thread를 종료시킬 때 사용한다. 
```

### 이외 함수들 

```c
void pthread_cleanup_push( void *함수명, void *arg);
// phtread_exit()이 호출될 때 handler를 정하는 함수

void pthread_cleanup_pop( int exec);
// 설정된 handler를 제거하기 위한 함수

pthread_t pthread_self(void);
// 현재 동작중인 pthread의 식별자를 리턴한다.
```

#### thread01.c

```c
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

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
    // pthread_t를 이용하여 thread id를 가지게 한다. 
    pthread_create(&thread, NULL, foo, NULL);
    // create를 통해 만들어 놓은 thread를 새로운 thread로 생성시킨다. 
    pthread_detach(thread);
    // 내가 만든 thread를 메인 thread와 분리시켜 
    // 각각 동시적으로 일을 할 수 있도록 만든다.
    
    for(i = 0; i < 5; ++i){
        sleep(1);
        printf("main, thread...\n");
    }
}
```

- 실행을 시킬 때는 thread01.c -c 를 통해 오브젝트 파일을 만들고, thread01.0 -lpthread를 통해서 링킹을 하고난 후의 실행파일을 만든다. 

### 4.1 공유자원을 사용하는 스레드 

- 프로세스와 달리 스레드는 프로세스내에 있는(heap에 들어 있는) 데이터들을 공유한다. 그러다보니 동시 다발적으로 공유자원을 사용하게 되면 문제가 생길 수 있다. 

#### thread02.c

```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread_count = 1;

int sum = 0;
void *foo(void *arg) {
	int i;
	for (i = 0 ; i < 100000000 / thread_count; ++i) {
		++sum;
	}

	return 0;
}

int main(int argc, char* argv[]) {
	if (argc == 2) {
		thread_count = atoi(argv[1]);
	}

	int i;
	// pthread_t thread[thread_count]; // !!
	pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);

	for (i = 0 ; i < thread_count ; ++i) {
		pthread_create(thread + i, NULL, foo, NULL);
	}

	for (i = 0 ; i < thread_count ; ++i) {
		pthread_join(thread[i], NULL);
	}

	printf("sum: %d\n", sum);
	free(thread);
}
```

### 문제점 

- 멀티 스레드가 공유자원의 사용으로 경쟁 조건에 의해 연산의 결과인 sum의 값이 실행마다 다르게 나타난다. 
  - 경쟁 조건은 공유 변수의 값을 변경하는 연산이 원자적이지 않기 때문에 발생하는 것이다. 
  - 연산은 cpu의 ALU(arithmetic and logic unit) 산술 논리 장치에서 관장하는데, 메모리에서 레지스터로 데이터를 전달하고 연산을 진행한 후 다시 주 기억장치인 메모리로 데이터를 전달한다. 이 과정에서 누락되는 연산들이 생기는 것이다.  

### 해결책

- 상호 배제(mutal exclusion -> mutex)를 이용하여 하나의 스레드가 작동하고 있을 때, 다른 스레드가 임계 영역에 접근하지 못하도록 만들어야 한다. 
- 임계 영역(critical section)는 여러 개의 스레드가 동시 접근을 할 수 없는 코드 블럭을 얘기한다.

#### thread03.c

```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread_count = 1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
void *foo(void *arg) {
	int i;
	for (i = 0 ; i < 100000000 / thread_count; ++i) {
        
        // mutext를 이용하여 하나의 스레드가 작동할 때, 
        // 다른 스레드가 접근하지 못하게 하도록 임계영역을 설정한다. 
		pthread_mutex_lock(&mutex);
		++sum;
		pthread_mutex_unlock(&mutex);
	}
	return 0;
}


int main(int argc, char* argv[]) {
	if (argc == 2) {
		thread_count = atoi(argv[1]);
	}
    
	// pthread_t thread[thread_count]; // !!
    // 동적 메모리를 할당하지 않고 단순히 배열을 만들어
    // thread를 저장시켜 놓으면 안된다. 
	pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);

    int i;
	for (i = 0 ; i < thread_count ; ++i) {
		pthread_create(thread + i, NULL, foo, NULL);
	}

	for (i = 0 ; i < thread_count ; ++i) {
		pthread_join(thread[i], NULL);
	}

	printf("sum: %d\n", sum);
	free(thread);
}
```

###  문제점

- 멀티 스레드들이 공유자원을 사용하면서 생기는 연산의 누락을 막기위하여 mutex를 이용하여 임계영역을 설정하였다. 
- 하지만 임계영역을 설정하므로써 동시성을 잃게 되었다. 하나의 스레드가 작동할 때 다른 스레드는 접근할 수 없기 때문에 단일 스레드를 사용하는 것과 크게 다르지 않아졌다. 

### 해결책

- 공유 변수로 바로 접근하는 것이 아니라, 지역 변수를 이용하여 스레드가 동시적으로 연산을 할 수 있도록 만들어준다. 
- 결국 각각의 스레드는 지역 변수에 대한 연산은 동시적으로 발생하고, 그 지역 변수를 전역 변수로 대입하려고 할 때만 임계영역을 설정하는 것이다. 

#### thread04.c

```c
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

int thread_count = 1;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
void *foo(void *arg) {
	int i;
	int local = 0;
	for (i = 0 ; i < 1000000000 / thread_count; ++i) {
		++local;
	}

    // 단순히 값을 증가시키는 연산은 local(지역변수)를 사용하여 연산을 하게 하고 
    // 공유 변수에 대한 대입은 지역 변수의 연산히 다 끝난 후에 하게 한다. 
    // 그러면 각각의 스레드가 쉬는 시간 없이 일을 동시적으로 수행할 수 있다. 
	pthread_mutex_lock(&mutex);
	sum += local;
	pthread_mutex_unlock(&mutex);
	return 0;
}

int main(int argc, char* argv[]) {
	if (argc == 2) {
		thread_count = atoi(argv[1]);
	}
    
	pthread_t *thread = (pthread_t *)malloc(sizeof(pthread_t) * thread_count);
	
    int i;
	for (i = 0 ; i < thread_count ; ++i) {
		pthread_create(thread + i, NULL, foo, NULL);
	}

	for (i = 0 ; i < thread_count ; ++i) {
		pthread_join(thread[i], NULL);
	}
	
	printf("sum: %d\n", sum);
	free(thread);
}
```

### 결론

- 모든 운영체제에서 멀티 스레드는 기본적으로 사용된다. 그런데 멀티 스레드를 사용하는데 있어서는 여러 문제들이 생길 수 있다. 
- 그렇기 때문에 스레드를 사용하기 전에 **"멀티 스레드가 왜 필요하고, 몇 개의 스레드가 필요하고, 각각의 스레드가 어떻게 통제되어야 하고"** 에 대한 정의가 분명해야 한다. 