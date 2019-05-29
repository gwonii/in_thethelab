## NIO

## 1. NIO 소개 

* nio는 자바 4부터 생긴 새로운 입출력 (new Input / Output) 이라는 뜻이다. 

### 1.1 NIO 패키지 

| NIO Package             | Contents                                            |
| ----------------------- | --------------------------------------------------- |
| java.nio                | 다양한 버퍼 클래스                                  |
| java.nio.channels       | 파일 채널, TCP 채널, UDP 채널 등의 클래스           |
| java.nio.channels.spi   | java.nio.channels 패키지를 위한 서비스 제공자       |
| java.nio.charset        | 문자센, 인코더, 디코더 API                          |
| java.nio.charset.spi    | java.nio.charset 패키지를 위한 서비스 제공자 클래스 |
| java.nio.file           | 파일 및 파일 시스템에 접근하기 위한 클래스          |
| java.nio.file.attribute | 파일 및 파일 시스템의 속성에 접근하기 위한 클래스   |
| java.nio.file.spi       | java.nio.file 패키지를 위한 서비스 제공자 클래스    |

### 1.2 IO와 NIO의 차이점 

* 기본적으로 데이터를 입출력한다는 목적은 동일하다. 

| 구분                   | IO                 | NIO                          |
| ---------------------- | ------------------ | ---------------------------- |
| 입출력 방식            | stream 방식        | channel 방식                 |
| 버퍼 방식              | non-buffer         | buffer                       |
| 비동기 방식            | 지원하지 않음      | 지원함                       |
| 블로킹 / 넌블로킹 방식 | 블로킹 방식만 지원 | 블로킹 / 넌 블로킹 모두 지원 |

### 1.3 Stream 과 Channel

---

#### 1.3.1 IO의 Stream

* 스트림은 입력 스트림과 출력 스트림이 구분되어 있다. 

* 데이터를 입력하기 위해서는 입력 스트림이 필요하고, 데이터를 출력하기 위해서는 출력 스트림이 필요하다. 

  ex) 파일에서 데이터를 읽고 저장해야 한다면 

  `FileInputStream` 과 `FileOutputStream` 을 별도로 생성해야 한다. 

#### 1.3.2 NIO의 Channel 

* 채널은 스트림과 달리 **양방향으로 입력과 출력**이 가능하다.

* 그렇기 때문에 입력과 출력을 위한 채널을 만들필요 없이 하나의 채널만 생성하면 된다. 

  ex) 파일에서 데이터를 읽고 저장해야 한다면 

  `FileChannel` 하나만 생성한다.

### 1.3 non - buffer 와 buffer

---

* IO에서는 출력 스트림이 1바이트를 쓰면 입력 스트림은 1바이트를 읽는다. 이런 시스템은 속도 면에서 느리게 동작한다. 
* 버퍼를 사용하게 되면 여러 개의 바이트를 한 번에 입력받고 출력할 수 있다. 

> IO에서도 이러한 버퍼를 쓰기위해 보조 스트림인 `BufferedInputStream` 과 `BufferedOutputStream`을 연결해서 사용하기도 한다. 

* NIO는 기본적으로 버퍼를 사용해서 입출력을 하기 때문에 IO보다는 성능이 좋다. 

##### 채널은 버퍼에 저장된 데이터를 출력하고, 입력된 데이터를 버퍼에 저장한다. 

* IO는 스트림에서 읽은 데이터를 즉시 처리한다. 그렇기 때문에 **스트림으로 부터 입력된 전체 데이터를 별도로 저장**하지 않으면, 입력된 데이터의 위치를 이동해 가면서 자유롭게 이용할 수 없다. 

```java
public class IoStream {

    try{    
        InputStream fis = new FileInputStream("url");
        BufferedInputStream bis = new BufferdInputStream(fis);
        OutputStream fos = new FileOutputStream("url");
        BufferedOutputStream bos = new BufferdOutputStream(fos);

        byte[] readBuf = new byte[512];
        
        while(bis.read(readBuf, 0, readBuf.length) != -1){		// 더 이상 읽을 내용이 없을 때 까지 읽는다. 
            bos.write(readBuf);
        }

    } catch (Exception e) {
        System.out.println("파일 입력 에러")

    } finally{
        try {
            bis.close();	// 파일을 닫을 때도 try - catch가 필요함
        } catch (Exception e) {
            System.out.println("스트림 닫기 에러")
        }
    }
}
```

> 이런 식으로 하면 의도적으로 stream에서도 버퍼를 만들어 사용했기 때문에 이동이 자유로워 지지만 단순히 InputStream / OutputStream만 사용하다면 항상 데이터를 별도로 저장해야 한다!

### 1.4 Blocking 과 Non - Blocking

---

#### 1.4.1 IO의 Blocking

* IO는 기본적으로 블로킹이 된다. ( ex) read 메소드를 사용한다면 데이터가 스트림에 들어올 때 까지 계속 기다리는 블로킹 된다. 마찬가지로 write 메소드를 사용하면 데이터가 출력되기 전 까지 쓰레드는 블로킹이 된다.)
* 블로킹을 빠져나오는 유일한 방법은 스트림을 닫는 것이다.

#### 1.4.2 NIO

* NIO는 블로킹과 넌블로킹 특징을 모두 가지고 있다. 
* IO 블로킹과 NIO의 블로킹의 차이점은 NIO의 블로킹은 인터럽트를 통해 빠져나올 수 있지만, IO 블로킹은 그렇지 않다는 것이다. 
* NIO의 넌블로킹은 입출력 작업 준비가 완료된 채널만 선택해서 작업 스레드가 처리하기 때문에 작업 스레드가 블로킹 되지 않는다. (여기서 작업 준비가 완료되었다는 것은 바로 읽고 쓸 수 있는 상태를 얘기한다. )
* NIO 넌블로킹의 핵심 객체는 `멀티플랙서(Mulitplexor)`인 `셀렉터(Selector)`이다.
* 셀렉터는 복수 개의 채널 중에서 준비 완료된 채널을 선택하는 방법을 제공해준다. 

##### 1.4.2.1 SelectorChannel 

* 셀렉터 채널은 모든 소켓채널들의 슈퍼클래스이다. 
* Selector에 등록하려면 우선 등록할 채널을 비블로킹 모드 설정 후 SelectorChannel의 register() 메소드를 호출하여 Selector에 등록한다. 
  1. OP_ACCEPT (접속시도 )
  2. OP_CONNECT (서버가 클러이언트에 접속을 허락했을 때)
  3. OP_READ 와 OP_WRITE 

### 1.5 IO와 NIO의 선택

---

#### 1.5.1 NIO 선택

* NIO는 불특정 다수의 클리언트 연결하는데 유리하다.
* NIO는 넌블로킹이나 비동기로 처리할 수 있다. 

**과도한 스레드 생성을 피하고 스레드를 효과적으로 재사용핟나는 점에서 큰 장점이 있다.**

* 운영체제의 버퍼(다이렉트 버퍼)를 이용한 입출력이 가능하기 때문에 입출력 성능이 향상된다.
* NIO는 하나의 입출력 처리 작업이 오래 걸리지 않는 경우에 사용하는 것이 좋다. ( 만약 하나의 입출력 처리가 오래 걸리는 작업이라면 IO를 사용하는 것이 더 좋다.)

#### 1.5.2 IO 선택

* IO는 입출력을 stream을 통해 바로바로 처리한다. 
* 연결 클라이언트 수가 적고, 전송되는 데이터가 대용량이면서 순차적으로 처리될 필요성이 있는 경우라면 IO를 사용하는 것이 유리하다. 

### 1.6 버퍼 

* NIO에서는 데이터를 입출력하기 위해 항상 버퍼를 사용한다. 
* 버퍼는 읽고 쓰기가 가능한 메모리 배열이다. 
* 버퍼를 잘 이해하고 사용할 줄 알아야 NIO에서 제공하는 API를 올바르게 사용할 수 있다. 



? NIO에서 버퍼를 사용할 때 

----------------------------------- 여기서 일단 잠시 중지

1. 셀럭터 만들고 열어준다. 

2. 서버소켓채널을 만들고 열어준다.
3. 주소를 설정하고 
4. 서버소켓채널에 바인드한다. 
5.  서버소켓채널을 논블럭으로 만들어준다. 
6. 소켓의 validOps 메소드를 사용한다 (가능한지 확인하는 메소드인 것 같음)
7. 셀렉터 키에 해당 소켓을 등록한다. (이제 준비가 완료되었다고 하는 신호같은 것 )
8. select() 메소드를 통해서 준비된 이벤트가 있는지 확인한다. 
9. 



> <https://crunchify.com/java-nio-non-blocking-io-with-server-client-example-java-nio-bytebuffer-and-channels-selector-java-nio-vs-io/>



---------------------------------------------------------- 여기 까지 

