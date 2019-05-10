# intptr_t



## 1. 사용 이유 

* intptr_t 또는 unintptr_t는 포인터의 주소를 저장하는데 사용된다. 
* 포인터를 정수 표현으로 변환할 때 유용하게 사용할 수 있다. 

> 포인터를 정수 표현으로 변환해야 하는 상황이 왜 있는거지?

* 대답으로는 intptr_t와 void * 을 포인터 자료형으로 사용할 수 있는데 void *의 경우는 비트 연산이 불가능 하지만, intptr_t를 사용할 경우 bit 연산자를 사용할 수 있다고 한다. 

> <https://stackoverflow.com/questions/35071200/what-is-the-use-of-intptr-t>

