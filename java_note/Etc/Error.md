# Error 

### 1. 파일 입출력 에러 

```java
try
	{
		fileStream = new FileInputStream(filePath);// 파일 스트림 생성
			
		do
		{
			i = fileStream.read(); //한 바이트 읽기
			System.out.print((char) i);
		}
		while(i != -1);		// 더이상 stream에 내용이 없을 때 까지 
			
		}
		catch (Exception e)
		{
			System.out.println("파일 입출력 에러!!" + e);
		}
```

* stream을 생성하고 입력 또는 출력을 할 때 예외처리를 해줘야 한다. 

### 2. 스트림 닫기 

```java
try
	{
		fileStream.close();// 파일 닫기. 여기에도 try/catch가 필요하다.
	}
	catch (Exception e)
	{
		System.out.println("닫기 실패" + e);
	}
```

* stream을 닫을 때도 잘 닫혔는지 예외처리를 해줘야 한다. 

### 3. Socket 생성 

#### 3.1 IOException 

```java
    try {
      ServerSocket serverSocket = new ServerSocket(5500);
      Socket socket = serverSocket.accept();
    } catch (IOException e) {
      e.printStackTrace();
    }
```

* 소켓이 생성되지 않았을 수도 있으므로 소켓을 생성할 때 예외처리를 해줘야 한다. 
* 서버소켓, 연결소켓 모두 포함됨 



### 4. Sleep 

#### 4.1  InterruptedException

```java
    try {
      ServerSocket serverSocket = new ServerSocket(5500);
      Socket socket = serverSocket.accept();

      InputStream is = socket.getInputStream();


      byte[] data = new byte[1024];
      int count = 0;
      while(true) {

        int ret = is.read(data);
        if(ret == -1) {
          System.out.println("데이터를 읽는데 에러가 발생했습니다.");
        }

        ByteArrayInputStream bis = new ByteArrayInputStream(data);
        DataInputStream dis = new DataInputStream(bis);

        char op = dis.readChar();
        int lhs = dis.readInt();
        int rhs = dis.readInt();

        System.out.printf("%d :  %d  %c %d \n",count++,lhs, op, rhs);

        Thread.sleep(100);
      }


    } catch (IOException | InterruptedException e) {
      e.printStackTrace();

    }
```

* Thread.sleep 을 사용할 때는 항상 InterruptedException예외를 처리해줘야 한다. 