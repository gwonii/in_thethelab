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

   ex) Type.WALKING	// enum 클래스는 객체를 만들 수 없다. 

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
    
    System.out.println(type.WALKING.getName());	// 이렇게 하나의 요소만 사용할 수도 있다. 
    
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



### 3. Enum의 장점 

1. 문자열과 비교해, IDE의 적극적인 지원을 받을 수 있다. 
   * 자동완성, 오타검증, 텍스트 리펙토링 등등 
2. 허용 가능한 값들을 제한할 수 있다. 
3. **리팩토리시 변경 범위가 최소화**된다. 
   * 내용의 추가가 필요하더라도, Enum 코드외에 수정할 필요가 없다. 

* C/C++ 의 경우 Enum이 결국 int값을 갖고 있지만, Java의 Enum은 완전한 기능을 갖춘 클래스이다. 

#### 3.1 데이터들 간의 연관관계 표현

#### Enum 사용 전 

* DB 테이블을 관리하기 위하여 만든 class 

```java
public class LegacyCase {
    public String toTable1Value(String originValue){
        if("Y".equals(originValue)){
            return "1";
        } else {
            return "2";
        }
    }
    
    public String toTable2Value(String originValue){
        if("Y".equals(originValue)){
            return true;
        } else{
            return false;
        }
    }
}
```

> 문제점 : origin의 테이블 값은 "Y" , "N" 으로 표현되어 있는데 DB의 테이블 1, 2 의 값은 다르게 표현되어 있다. (table1은 "1" , "0"  table2는 true, false)
>
> 그렇기 때문에 origin의 값에 따라 table의 값을 정해주는 클래스가 별도로 필요했다. 그렇기에 위의 클래스를 만들어 사용하게 된 것이다. 

위 처럼 사용하면 기능상에는 문제가 없지만 가독성이 떨어지는 문제가 생긴다. 개발자는 전체 코드를 보지 않으면 "Y"가 "1" , false와 동일하다는 확신을 할 수 가 없다. 

그리고 불필요한 메소드를 하게된다. 만약 origin의 값과 table의 값이 동일하게 표현되어 있다면 위 class처럼 값을 매기는 메소드를 따로 만들 필요가 없기 때문이다. 



#### Enum 사용 후 

```java
public enum TableStatus {
    Y("1", true),
    N("0", false);
    
    private String table1Value;
    private boolean table2Value;
    
    TableStatus(String table1Value, boolean table2Value){
        this.table1Value = table1Value;
        this.table2Value = table2Value;
    }
    
    public String getTable1Value() {
        return table1Value;
    }
    public boolean getTable2Value() {
        return table2Value;
    }
}
```

> enum을 이용하여 Y , "1", true를 하나로 묶었다. 그리고 추가 타입이 필요한 경우 enum의 상수와 get메소드만 추가하면 된다. 
>
> 만약 lombok의 @Getter을 사용한다면 enum의 get 메소드까지 제거가 되어 더울 깔끔한 코드가 된다. 

#### 3.2 상태와 행위를 한 곳에서 관리 

ex) DB에 저장된 code의 값이 "CALC_A" 일 경우엔 값을 그대로, "CALC_B"일 경우엔 *10을 한 값을 전달해야 한다면? 

#### Enum 사용 전 

```java
public class LegacyCalculator {
    public static long calculate(String code, long originValue){
        
        if("CALC_A".equals(code)){
            return originValue;
        } else if("CALC_B",equals(code)){
            return originValue * 10;
        }
    }
}
```

```java
public void codeCalculator() {
    String code = selectCode();
    long originValue = 1000L;
    long result = LegacyCalculator.calculate(code,originValue);
}
```

> 이런 식으로 calculate 메소드를 static으로 만들어 어디서나 사용할 수 있게 만들었다. 이런 코드를 사용하면 원하는 상황에 따라 다른 메소드를 수행할 수 있도록 만들 수 있다. 
>
> 하지만 code값과 originValue를 다른 곳에서 가져온다는 것에서 문제가 있다. 

#### Enum 사용 후 

```java
public enum CalculatorType {
    CAL_A{
    	@Override
    	public long calculate(long value){
            return value;
    	}
    }
    CAL_B{
        @Override
        public long calculate(long value){
            return value * 10;
        }
    }
     
    public abstract long calculate(long value);
}
```

> java 8 이전에는 이렇게 추상메소드를 사용하며 enum에 각각의 메소드를 사용했다. 하지만 java8 이후부터는 파라미터에 메소드를 넣을 수 있게되면서 파라미터에 메소드를 넣는 방식으로 사용할 수 있다. (이것은 나중에 정리하는 것으로 하자)

#### 3. 3 데이터 그룹 관리 

#### 3.4 관리 주체를 DB에서 객체로 

3, 4 번은 나중에 또 정리를 하도록 하자.. 