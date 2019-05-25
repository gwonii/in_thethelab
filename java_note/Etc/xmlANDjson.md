# xml 과 json

* xml과 json은 여러 프로그램언어에서 적용할 수 있는 데이터 형식의 자료이다. 

## 1. xml 

#### 1.1. xml이란? 

* xml (extensible markup language)
* xml은 데이터의 형태를 보여주는 markup language이다. 

* xml은 html과 같은 markup language중 하나이다.
  * xml은 어떠한 데이터를 설명하기 위해 이름을 임의로 지은 태그로 데이터를 감싼다. ( 즉 태그로 데이터 설명을 한다. 

```text
<? xml version="1.0"?>

<컴퓨터언어>

<C언어> C       </C언어>
<C언어> C++    </C언어>
<C언어> C#     </C언어>
<JAVA> java     </JAVA>
<JAVA> android </JAVA>

</컴퓨터언어>
```

> 위의 예시처럼 xml은 태그를 이용하여  필요한 정보들을 받거나 줄 수 있는 데이터 형태를 제공한다. 

### 1.2 xml의 문제점 

* xml은 프로그래밍 언어나 데이터베이스의 시스템을 입력하는데 있어서 맵핑의 어려움이 있다.
* 이식성이 json에 비해 떨어진다
* 보안성이 json에 비해 떨어진다.
* 초기에 작성해야할 코드의 양이 많다. 



## 2. json

### 2.1. json이란? 

* json ( JavaScript Object Notation)

* json은 자바스크립트로 작성되었다. 

* json은 xml이 갖는 많은 문제들을 해결하면서 인기가 급부상하였다. 

  

### 2.2 json의 장점 

* json은 xml보다 데이터를 빨리 처리하고 빨리 읽을 수 있다. 
* 이식성이 높다. 
* json 표현의 구조와 데이터를 처리하는 코드의 구조 사이에서 맵핑이 쉽다. 
* 애자일을 실현시킬 수 있다. 



## 3. 현재의 xml 

* 그렇다고 xml이 단점만 있는 것은 아니다. 
* xml은 메타데이터를 지원하지만, json은 속성에 불과하므로 메타데이터를 표현하기에 어려움이 있다. 