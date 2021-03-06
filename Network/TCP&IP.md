# TCP/IP 통신 



> 참조자료 : youtube TCP/IP 열혈 강의 



## 1. TCP / IP 통신 과정 

* server에는 여러 개의 소켓이 존재한다. (server의 프로그램은 상담원, 소켓은 전화기)
* 이 소켓에는 특정 포트 값이 있으며, 대표 ip 주소와 연결되어 있다. (포트는 내선전화번호, ip는 대표 전화 번호 ) 
* client는 연결하고 싶은 ip에 포트를 찾아 연결하고 소켓을 통해 server프로그램과 연결된다. 

## 2. server 기본요소 

1. socket을 "생성"한다.  (서버 소켓과 연결 소켓)
2. socket에 ip와 port를 연결하여 "bind"한다
3. "listen"한다. (전화기의 개통이라고 생각하면 편함)
4. client의 요청을 "accept" 한다

> accept는 블럭함수이다. 

기본 틀은 TCP/IP 통신을 할 때 바뀌지 않는다. while(1) 문 안에 실행문에 대해서만 확장해 나가는 방식으로 사용된다. 

## 3. client 기본요소 

1. socket을 "생성"한다. (연결 소켓)
2. 연결할 서버와 주소를 설정한다. 
3. server에 "connect"를 한다.



## 4. client에서 조건 요청하기

### 예제

* client에서 "print"라는 문자열을 server에 보내면 그 때서야 문자를 받을 수 있도록 만들어보자 



## 5. TCP와 UDP

### 5.1 프로토콜의 계층구조 

* osi의 7계층 구조 vs TCP/IP 구조 차이  

![osi7계층 구조](C:\Users\hoho\Desktop\thethelab\in_thethelab\Network\img\osi7계층 구조.PNG)

* 현재는 7단계 (osi)로 사용하기보다 4단계(tcp/ip)로 사용하고 있음 

> <https://shlee0882.tistory.com/110>

### 5.2 TCP와 UDP의 차이 

|           | TCP            | UDP            |
| --------- | -------------- | -------------- |
| 신뢰성    | 신뢰성이 높다. | 신뢰성이 낮다. |
| 연결      | 연결형         | 비연결형       |
| 비용      | 고비용         | 저비용         |
| 응용 분야 |                |                |

#### 5.2.1 신뢰성 관련

1. TCP는 데이터를 보내는데 있어서 스스로 오류제어가 가능하기 때문에 안전하게 데이터를 보낼 수 있다. 반면 UDP는 오류를 제어할 수 없다. 그냥 데이터를 보낼 뿐
2. TCP는 흐름제어가 가능하다. (ex. 데이터를 보낼 때 상대방이 받을 수 있는 만큼만 보내는 것 ) 반면 UDP는 상대방의 상태에 신경쓰지 않는다.  

#### 5.2.2 연결 관련 

1. TCP는 데이터를 보내기 전에 경로를 설정한다. 그리고 설정된 경로에 따라 순서를 갖고 데이터를 보낸다. 하지만 UDP는 경로 설정 절차가 없다.  
2. TCP는 자료의 순서가 유지된다. 도착 시간들은 달라질 수 있다. UDP는 자료의 순서가 뒤바뀔 수 있다. 

#### 5.2.3 비용 관련 

1. TCP는 more space, more time 여러 경로 설정과 확인 절차로 인하여 많은 시간과 많은 공간이 사용된다 . 반면 UDP는 마구잡이로 데이터를 보내기 때문에 공간과 시간이 덜 든다. 



## 6.  바이트 순서 와 바이트 순서 간 자료 변환

### 6.1  IP와 Port

* ip는 이진 값, port는 실제적으로 2바이트 이진 값(big-endian 방식)을 사용한다 

#### 6.1.1 IP 

* ip는 3가지 방법으로 표현할 수 있다. 
  1. 도메인 이름 문자열 : ex) www.naver.com
  2. 점과 10진수 문자열 : ex) 202.131.30.61
  3. 이진 값 : 0xcbf82738

#### 6.1.2 port

* port는 2바이트 이진 값으로만 표현된다. 

### 6.2 바이트 순서 

* 2바이트 정수 

  |               | n번지 | n+1번지 |
  | ------------- | ----- | ------- |
  | Big-endian    | 0x12  | 0x34    |
  | Little-endian | 0x34  | 0x12    |

* 네트워크 바이트 순서 -> Big-endian
* 호스트 바이트 순서 -> machine-dependent 에 따라서  (Big-endian / Little-endian)











