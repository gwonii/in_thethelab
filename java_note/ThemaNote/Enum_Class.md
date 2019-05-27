# Enum Class 

### 1. Enum Class란?

* 열거형 클래스
* primitive type이 아닌 reference type
* 클래스 처럼 보이게 하는 상수들의 모임 클래스 
* 서로 관련 있는 상수들을 모아 심볼릭한 명칭의 집합으로 정의하는 것
* enum 클래스형을 기반으로 한 클래스형 선언 

### 2. Enum Class 의 사용 

#### 2.1 상수의 열거형 

##### 2.1.1 하나의 java 파일로 만들어서 선언하기 

```java
public enum Type {
    APPLE, BANANA, CANDY, DELISH
}
```

> 해당 모듈에서 여러 클래스들이 사용하는 경우 하나의 java파일로 만들어 사용할 수 있도록 한다. 

##### 2.1.2 클래스 안에서 선언하기 

```java
public class play {
	public String name;
    ~~
        
    private enum Type {
        APPLE, BANANA, CANDY, DELISH
    }
}
```

> 해당 클래스 안에서만 사용되는 enum이라면 클래스 안에서 선언하고 사용할 수 있도록 한다. 

##### 2.1.3 클래스 밖에서 선언하기 

```java
enum Type {
    APPLE, BANANA, CANDY, DELISH
}

public class play {
    public String name;
    ~~
}
```

> 병렬적으로 존재하는 여러 클래스에서 사용한다면 클래스 밖에서 enum을 선언해서 사용하도록 한다. 

##### 2.1.4 상수의 열거형으로 enum 사용하기 

```java
enum Type {
    APPLE, BANANA, CANDY, DELISH
}

public class play {
    public String name;
    public Type type;
    
    type = Type.APPLE;			// Type.APPLE은 자료형이 Type이다. 
    
    System.out.println(type);
}
```

#### 결과 

```
APPLE
```



#### 2.2 enum class에 내장되어 있는 method 사용하기

| method              | discription                                            |
| ------------------- | ------------------------------------------------------ |
| valueOf(Stirng arg) | String 값을 enum에서 가져온다. (값이 없으면 예외 발생) |
| values()            | enum의 요소들을 순서대로 enum타입의 배열로 리턴        |
| name()              | 호출된 값의 이름을 String으로 리턴                     |
| ordinal()           | 해당 값이 enum의 정의된 순서를 리턴                    |

> 대표적으로 사용되는 메소드들이다. 이외에 enum 을 많이 쓰게 되면 다른 메소드들에 대해서도 알아보도록 하자. 

##### 2.2.1 values()

```java
enum Type {
    WALKING, RUNNING, TRACKING, HIKING
}
public class Shoes {
    public String name;
    public int size;
    public Type type;
     
    public static void main(String[] args) {
        for(Type type : Type.values()) {
            System.out.println(type);
        }	// 배열을 담고 있기 때문에 루프문을 통하여 출력을 할 수 있다.
    }
}
```

##### 출력

```java
WALKING
RUNNING
TRACKING
HIKING
```



##### 2.2.2 ordinal()

```java
enum Type {
    WALKING, RUNNING, TRACKING, HIKING
}
public class Shoes {
    public String name;
    public int size;
    public Type type;
     
    public static void main(String[] args) {
        Shoes shoes = new Shoes();
         
        shoes.name = "나이키";
        shoes.size = 230;
        shoes.type = Type.RUNNING;
         
        System.out.println(shoes.type.ordinal());
         
        Type tp = Type.HIKING;
         
        System.out.println(tp.ordinal());
    }
}
```

##### 출력

```java
1
3
```

> enum은 인덱스 0부터 매칭되기 때문에 1, 3이 출력된다.

### < enum의 값을 가져오는 방법>

1. enum 형 객체를 만들어서 값을 가져온다.

   ex) Type.WALKING

2.  valueOf() 메소드를 이용해서 가져온다.

   ex) Type.valueOf("WALKING")

3. enum class를 import하여 enum의 값을 가져온다.



### 2.3 enum에 get함수 이용하기 

```java
enum Type {
    WALKING("워킹화"), RUNNING("러닝화")
    , TRACKING("트래킹화"), HIKING("등산화")
     
    final private String name;
     
    private Type(Stirng name) { //enum에서 생성자 같은 역할
        this.name = name;
    }
    public String getName() { // 문자를 받아오는 함수
        return name;
    }
}

public class Shoes {
    public static void main(String[] args) {
        for(Type type : Type.values()){
            System.out.println(type.getName());
        }
    }
}
```

### 출력

```java
워킹화
러닝화
트래킹화
등산화
```

> 이 처럼 enum class 내에 생성자와 get 메소드를 사용하여 enum 상수에 원하는 값을 대입하고 자유롭게 이용할 수 있다. 

### 2.4 상수 클래스를 만들어 열거형 선언하기 

```java
class Type {
    static final String WALKING = "워킹화";
    static final String RUNNING = "러닝화";
    static final String TRACKING = "트래킹화";
    static final String HIKING = "등산화";
}

public class Shoes {
    public static void main(String[] args) {
        String w = Type.WALKING;
        System.out.println(w);
    }
}
```

> 이런 방식으로 상수들을 모아놓는 클래스를 만들어 사용할 수 있다. 

### 2.5 abstract method를 사용하여 상수 mehod 사용하기 

```java
public enum Direction {

  RIGHT {
    @Override
    public int moveRow(int times) {
      return +times;
    }

    @Override
    public int moveCol(int times) {
      return 0;
    }
  },
  LEFT{
    @Override
    public int moveRow(int times) {
      return -times;
    }

    @Override
    public int moveCol(int times) {
      return 0;
    }
  };

  public abstract int moveRow(int times);
  public abstract int moveCol(int times);

}
```

> 이런 식으로 enum 클래스 내에서 추상 메소드를 선언하고 enum 상수마다 메소드를 정의할 수 있다. 

