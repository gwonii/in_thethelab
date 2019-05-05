# 오목 설계 기획안 



# CLASS



## client

> PApplet 상속

---

### field

```java
private int LENGTH ;		// 오목판 가로 길이 
private int NUM=16; //
private int EDGE;
private int gameState;
private int gameturn; // 블랙 다음 흰색..,,흰색 다음 블랙...
private static final int BLOCK ;		// 오목판 한 블록 길이
private static final int NONE = 0;			// 돌 X 
private static final int BLACK = 1;			// 검은 돌 
private static final int WHITE = 2;		// 흰 돌
private static final int WAIT = 3000;		// 승리 후 대기시간

private int[][] board;			// 오목판의 상태 
private int color;			// 돌의 색깔
private int winColor			// 승리한 돌의 색깔  
```



## method

* public static void main(String[] args) 
  1. 클라이언트 소켓 생성 및 서버와 연결
  2. PApplet 실행

* public void settings() 
  1. 사이즈 설정
  2. 필드 생성및 초기화
* public void draw()
  1. 오목판 그리기 
  2. 마우스 커서 변경하기 
  3. 돌 그리기 
  4. 승리 출력
* public void mouseCliked()
  1. 현재 마우스의 위치를 board 인덱스로 변경 
  2. 돌을 놓을 수 있는지 확인
     1. 마우스 커서 확인
     2. 돌이 이미 놓여있는지 확인
     3. 금수(3x3, 6목) 확인
  3. board 값 변경
  4. 서버에 전송
  5. 승리 체크

* void drawBoard() 
  * 오목판 그리기 
* void drawStone()
  * 돌 그리기
* boolean inRange(int i, int j)
  * 놓을 수 있는 위치인지 확인
* boolean isForbiden(int i, int j)
  * 금수 확인
* void sendToServer(int i, int j)
  * 서버에 전송
* int win(int i, int j)
  * 승리 확인

## 2. server

### field

```java
private static final int BLACK = 1;			// 검은 돌
private static final int WHITE = 2;			// 흰 돌


private int[][] board;			// 오목판 상태
```



### method

* public static void main (String[] args)
  1. 서버소켓 생성 및 클라이언트와 연결
  2. board 2차원 배열 생성 
  3. 클라이언트와 board값을 주고받음





  **private static final int BLOCK;**

  **private** **static** **final int NONE = 0;**

  **private static final int BLACK = 1;**

  **private static final int WHITE = 2;**

  **private** **static final int** **NU****M** **=** **15;**

   

  **private** **boolean** **gameState****;**

  **private** **boolean** **gameTurn****;**

  **private int length;**

  **private int edge;** 

  **private int[][] board;**

  **private int color;**

  **private int** **winColor****;**



