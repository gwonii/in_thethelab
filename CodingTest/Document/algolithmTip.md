# 알고리즘 

## 

## 1. c++ 입/출력 정리 

* 기본 코드 

```c++
#include <iostream>
using namespace std;
int main(){
	int a, b;
	cin>>a>>b;
	cout<<a+b<<endl;
	return 0;
}
```



* endl 과 "\n" 의 차이 

```c++
1. endl

cout<<"hello"<<endl;

cout<<"hello"<<"\n";
cout.flush();

// 두 행동을 순차적으로 시행한다. 

2. "\n" 

cout<<"hello"<<"\n";

// 바로 엔터 인식을 한다. 
```

> 그렇기 때문에 endl을 사용하는 것 보다 "\n"을 사용하는 것이 시간상 훨씬 빠르다. 



 