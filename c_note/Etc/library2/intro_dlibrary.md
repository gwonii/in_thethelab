// 동적 라이브러리 


## 동적라이브러리의 개념과 제작 단계
---

* 특징 

1. 실행 중에 필요한 라이브러리를 동적으로 메모리에 로드해서 사용한다. 
2. 실행 파일안에 함수의 구현이 존재하지 않는다. 
3. 실행 파일의 크기가 크지 않다. 
4. 추가적인 로드가 필요하다. 
5. 라이브러리가 변경되어도 다시 컴파일을 할 필요가 있다. 

* 사용되는 명령 

이 키워드들은 #include <dlfcn.h>에 포함되어 있다. 


1. dlopen() 
: dlopen 함수는 라이브러리를 열고 그것이 사용되도록 준비시켜준다
			ex) void *dlopen (const cahr *filename, int flag);
> 여기서 파일이름이 "/" (절대경로) 라면 dlopen()을 즉시 사용하려한다. 그렇지 않다면 dlopen()은 다음과 과 같은 순서로 라이브러리를 찾는다. 

			1) 사용자의 LD_LIBRARY_PATH으 환경변수의 콜론으로 구분지어진 디렉토리 
			2) ~~ 
			3) ~~ 
			추가 순위로 라이브러리를 찾지만 현재 배우지 않았으므로 스킵!

2. dlerror() 
: 에러는 dlerror()를 호출함으로써 보고될 수 있다. dlerror()은 dlerror(), dlsym(), dlclose()중 마지막 부른의 에러의 스트링을 반환한다. 

3. dlsym() 
: DL라이브러리를 사용하는 중요한 루틴은 dlsym이다. 이것은 열려진 라이브러리의 심볼의 값을 찾아준다. 이 함수는 다음과 같이 정의된다. 
			ex) void *dlsym(void *handle, char *symbol);
> 핸들은 dlopen에 의해 반환된 값이고, 심볼은 NIL로 끝나는 스트링이다. 왠만하면 dlsym()의 결과를 void* 자료형으로 저장하지 말 것! 왜냐하면 사용할 때 마다 캐스트해서 사용해야 되기 때문이다. 
> dlsym()은 심볼이 없으면 NULL을 반환할 것이다.

* 추가적인 키워드 

1. -shared : 공유 라이브러리를 사용해서 링크하라는 옵션  
2. -fpic : (position independent code) 현재로 알 수 있는건 사용하지 않아도 동적라이브러리를 사용할 수 있지만 동적라이브러리를 사용하는데 있어서 성능적인 측면에서 좋다. 




* 동적 라이브러리 구현 과정

1. 먼저 필요한 라이브러리를 만든다. 내가 쓸 라이브러리는 "add.c"
2. shell 창에서 add.c를 -c 명령어를 통해 add.o 오브젝트 파일을 만든다. 
3. shell 창에서 "$ gcc add.o -shared -fpic -o libadd.so" 명령어를 통해 add.o 파일을 library.so 파일로 만들어 준다. (동적 라이브러리에서 사용되는 파일은 .so )
4. "main.c" 내에서 dlopen, dlsym을 사용하여 라이브러리 파일을 로딩하는 코드를 작성한다. 
			void *addr = dlopen("./libadd.so",RTLD_LAZY);
			// libadd.so 파일을 열어 라이브러리로 사용하겠다는 코드
			if(addr == NULL) {		// dlopen 이 정상적으로 작동하였는지 확인
				return -1;
			}

			int (*p)(int,int) = dlsym(addr,"add");
			// 열어놓은 라이브러리는 addr에 들어있고 그 addr에 들어있는 add 함수를 
			// 사용하겠다는 코드 

			printf("%d \n", p(10,20));

5. main.c -c 를 통해 main.o 오브젝트 파일을 만들어 준다. 
6. shell 창에서 " $ gcc main.o -ldl " 명령어를 통해 main.o에 dlfcn.h 파일을 링킹해준다.
7. 그러면 a.out 파일이 생성되고 LD_LIBRARY_PATH=. ./a.out을 통해 라이브러리를 사용할 수 있는 패쓰를 지정해주고 a.out을 실행시킨다. 










