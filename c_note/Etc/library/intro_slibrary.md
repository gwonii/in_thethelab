## 정적 라이브러리 단계와 설명 

* 정적 라이브러리 정의

: 1)컴파일러와 링커의 구분 

컴파일러: 컴파일러는 사람이 만든 소스코드를 obj 파일로 만들어주는 역할을 한다. 

링커: 링커가 obj 파일을 묶어서 하나의 exe파일로 만들어준다. 

정적 라이브러리를 이용하면 링커가 obj파일을 묶을 때 lib이라는 파일도 같이 묶어서 exe파일을 만들게 된다. 

linux.a (.a의 확장자를 가지고 있음)




* 구현 내용  

: add라는 함수를 헤더파일로 만들어서 main.c 파일에서
add의 기능이 구현될 수 있도록 라이브러리를 사용한다. 


* 구현 단계 

1. 먼저 사용할 main.c 함수와add.c 그리고  헤더파일 add.h를   만든다.
2. main.c 소스코드를 gcc add.c -c 를 통해서 
add.o 즉 add의 obj파일을 만든다. 그리고 main.c 파일도 add.c와 마찬가지로 obj파일로 만들어 준다. 

3. ar rcv libadd.a add.o 를 이용하여 하나의 라이브러리 파일을 만든다. (여기서 묶고싶은 obj 파일들을 add.o 뒤에 나열 시키면 된다.)

> rcv  명령어는 libadd.a ( ~~~ ) 여러 개의 .o 파일들을 엮어서 libadd.a 파일로 만든다는 것이다. 
			-r: 라이브러리에 새로운 objcet를 추가하겠다는 옵션 
			-c: archive가 존재하지 않으면 추가하겠다는 옵션 
			-v: tar의 옵션과 같이 library 과정을 보여주겠다는 옵션


4. 마지막으로 gcc main.o -ladd -L. 을 통해서 사용할 라이브러리 들과 main의 obj파일을 연결해 준다 . 
> 여기서 -l은 library의 줄 임말 만들어 놓은 main.c에서 사용할 .a 파일 이름을 넣어주면 된 다.
>-L은 사용할 라이브러리의 폴더 위치를 말해준다. 현재 파일에 있다면 -L.  아니면 -L./~~~ 하면 된다. 







