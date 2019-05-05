# Tip



## 1. scanf의 return 값 



```c++
#include <iostream>

using namespace std;

int main() {
    int a;
    int b,c,d;
    
    a = scanf("%d %d %d", b,c,d);
    
    printf("%d", a);
}
```

> 출력값은 3이 출력된다. 위에서 확인할 수 있듯이 scanf의 리턴값은 입력한 수의 개수에 따라 변화한다. ex) 3개를 입력했다면 scanf의 리턴 값은 3이다. 