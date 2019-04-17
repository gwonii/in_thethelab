# Builder Pattern



## 1. Constructor Pattern

---

* 생성자에 매개변수가 많을 때 취해지는 3가지 방법으로 점층적 생성자 패턴, 빈즈 패턴, 빌더 패턴이 있다. 



## 2. Builder Pattern

---

- Separate the construction of a complex object from its representation so that the same construction process can create different representations.

객체 생성의 공정은 동일하지만, 다른 표현을 가지는 객체를 생성할 때, 사용하는 패턴 

빌더 패턴은 생성자에 들어갈 매개 변수가 많든 적든 차례차례 매개 변수를 받아들이고 모든 매개 변수를 받은 뒤에 이 변수들을 통합해서 한번에 사용한다. 

## 3. Builder Pattern 을 사용하는 이유 

---

#### 1. 생성자의 인자가 많은 경우, 공정이 복잡한 경우 사용한다. 

#### 2. 객체를 불변으로 생성할 경우 (ex. String, StringBuilder)

> 반복적인 보일러플레이트에 의해서 사용하게 된 것



## 4. Builder Pattern 유도하기 

---

* 1단계 (생성자 오버로딩)

```java
class User {

  // 생성자 오버로딩
  // 사용자의 정보를 담고 있는 class

  // 필드
  private String name;
  private int age;
  private String address;

  // 생성자
  User(String name, int age, String address) {
    this.name = name;
    this.age = age;
    this.address = address;
  }

  User(String name, int age){
    this(name,age,"");              // 인자를 두 개만 받을 때는 0값으로 초기화
  }

  User(String name){
    this(name,0,"");
  }
}
```

#### 사용하기 

```java
public static void main (String[] args) {
	User user = new User("hogwon",27,"guri");

    // 또는
    String a = "javin";
    int b = 22;
    String c = "seoul";

    User user2 = new User(a,b,c);
}
```

#### 문제점:

만약 전달해야 할 매개변수가 많아진다면 어떻게 할까? 매개변수는 반드시 필요한 정보들이기 때문에 줄이거나 할 수 없다. 그런데 그 많은 인자들을 처리하다보면 타입에 문제가 생길 수 있고, 순서에 문제가 생길 수도 있다. 



* #### 2단계

```java
class User2 {

  // java bean 방식은 setter/getter를 통해 작동한다.

  private String name;
  private int age;
  private String address;

  public void setName(String name) {
    this.name = name;
  }

  public void setAge(int age){
    this.age = age;
  }

  public void setAddress(String address) {
    this.address = address;
  }
}
```

#### 사용하기

```java
public static void main (String[] args) {
	User2 user = new User();
    
    user.setName("hogwon");
    user.setAge("27");
    user.setAddress("guri");   
}
```

#### 문제점:

1. 객체의 일관성이 깨질 위험이 있다. (생성과 초기화가 분리됨으로써, 초기화가 아직 완전하지 않은 객체를 관리해야 하는 문제가 생긴다.)
2. 불변 객체도 사용할 수 없다. 
3. 스레드 이슈



* ### 3단계

```java
class User3 {

  private String name;
  private int age;
  private String address;
  private String woo;
  private String joo;
    
  User(Builder builder){
	 this.name = builder.name;
	 this.age = builder.age;
	 this.address = builder.address;
	 this.level = builder.level;
	 this.money = builder.money;
  }

  // 여기에 Builder class 를 만들어서 한번 감싸준다.
  static class Builder {

    private String name;
    private int age;
    private String address;
    private String woo;
    private String joo;

    // 필수적인 내용들을 생성자로 만들어 사용한다.
    Builder(String name, int age){
      this.name = name;
      this.age = age;
    }

    Builder address(String address){
      this.address = address;
      return this;
    }

    Builder woo(String woo) {
      this.woo = woo;
      return this;
    }

    Builder joo(String joo) {
      this.joo = joo;
      return this;
    }

    User build() {
      return new User(this);
    }
  }
}
```

#### 사용하기

```java
public static void main(String[] args){
    User3.Builder builder = new User3.Builder("Tom",42);
    builder.address("suwon");
    builder.joo("hoho");
    builder.woo("haha");
    
    User3 user = builder.build();
}
```

또는 

```java
public static void main(String[] args){
    User3 user2 = new User3.Builder("Tom",42);
    .address("suwon");
    .joo("hoho");
    .woo("haha");
    .build();
}
```

> 메소드 체인 호출을 통해 자기 자신의 참조를 반환하는 방법 또한 가능하다. 

## 단어 정리하기 

---

### 1. 불변 객체 :

* 객체 지향 프로그래밍에 있어서 불변객체는 생성 후 그 상태를 바꿀 수 없는 객체를 말한다. 

#### 장점:

1. 동일한 내용의 객체를 공유할 수 있다. (Flyweight Pattern )
2. 동일한 내용의 경우 공유할 수 있으므로, 객체를 비교할 때 == 연산을 통해 비교할 수 있다. 

> == : 참조 동등성 판단 ,  equals : 객체 동등성 판단 

### 2. 타입 체계 

 	1. Primitive Type : byte, int 등등 
 	2. Reference Type : class, interface, enum, array 등등 



### 3. Immutability (변경 불가성) :

* 객체가 생성된 이후 그 상태를 변경할 수 없는 디자인 패턴을 의미한다. 

객체는 참조 형태로 전달하고 전달 받는다. 객체가 참조를 통해 공유되어 있다면 그 상태가 언제든지 변경될 수 있기 때문에 문제가 될 가능성도 커지게 된다. 여기서 불변 객체를 사용하게 되면 복제나 비교를 위한 조작을 단순화 할 수 있고  성능 개선에도 도움이 된다. 하지만 객체가 변경 가능한 데이터를 많이 가지고 있는 경우라면 오히려 부적절한 경우가 있다. 

ex) Boolean, null, undefined, Number, String, Symbol ()







