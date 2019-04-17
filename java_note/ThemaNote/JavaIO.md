# 18강 IO기반 입출력 및 네트워킁 



## 1. 개요

---

* 모든 프로그래밍의 기본은 입출력에서 시작된다. 

프로그램이란 입력받은 데이터에 따라 결과를 연산하고 다른 시스템에 이를 전달하는 것이다. 

**모든 것은 파일로 이루어져있다.**

* 모든 프로그램은 사용자가 데이터를 입력하는 방법이 존재해야 하고, 사용자가 그 결과를 받을 수 있어야 한다. 

* java에는 크게 콘솔 입출력과 파일 입출력이 있다. 

콘솔 입출력은 프로그램 실행 환경에 따라 각각 달라진다. 파일 입출력은 파일을 가지고 입출력을 실행하기 때문에 모든 환경에서 동일하게 나타난다. 파일을 읽는 매체가 같다면 



## 2. Class

---

* 먼저 구체적인 class를 보기 전에 Stream에 대해 먼저 알아보자 
* **Stream**

프로그램이 데이터를 주고 받을 때는 Stream이 필요하다. 스트림은 일방향적이여서 각각의 출력 스트림과 입력 스트림이 존재한다. 

프로그램을 기준으로 프로그램이 정보를 받는다면 입력스트림, 프로그램이 정보를 내보낸다면 출력스트림을 통해 데이터가 주고받아진다. (InputStream, OutputStream)

| java.io 패키지의 주요 클래스                                 | 설명                                                  |
| ------------------------------------------------------------ | ----------------------------------------------------- |
| File                                                         | 파일 시스템의 파일 정보를 얻기 위한 클래스            |
| Console                                                      | 콘솔로 부터 문자를 입출력하기 위한 클래스             |
| InputStream / OutputStream                                   | 바이트 단위 입출력을 위한 최상위 입출력 스트림 클래스 |
| FileInputStream / FileOutputStream<br />DataInputStream / DataOutputStream<br />ObjectInputStream / ObjectOutputStream<br />PrintStream<br />BufferedInputStream / BufferedOutputStream | 바이트 단위 입출력을 위한 하위 스트림 클래스          |
| Reader / Writer                                              | 문자 단위 입출력을 위한 최상위 입출력 스트림 클래스   |
| FileReader / FileWriter<br />InputStreamReader / OutputStreamReader<br />PrintWriter<br />BufferedReader / BufferedWriter | 문자 단위 입출력을 위한 하위 스트림 클래스            |

#### 기본 콘솔입력 예시

```java
public static void main (String[] args){
    InputStream str = System.in;
    
    int a;
    a = in.read();
    System.out.println(a);
}
```

> 이런식으로 InputStream의 기본 클래스를 사용하여 입출력이 가능하다. 
>
> 기본적으로 1byte씩 read()를 통해 읽어낸다.

```java
public static void main (String[] args){
    InputStream str = System.in;
    
    int a;
    int b;
    int c;
    
    a = in.read();
    b = in.read();
    c = in.read();
    
    System.out.println(a + b + c);
}
```

> 출력 예시) 123 
>
> 각각의 a,b,c에 들어있는 값들이 나란히 출력된다. 

위는 처음에 3byte의 값을 입력하고 3byte를 모두 출력하는 모습을 볼 수 있다. 이 처럼 read()는 1byte씩 읽는다. 