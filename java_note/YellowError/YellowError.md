# YellowError



### 1. Access can be private 

---

Inspection info: Reports all fields, methods or classes, found in the specified inspection scope, that may have their access modifier narrowed down.

접근 제한이 private으로 바꿀 수 있다는 경고사항

```java
User (int num1, int num2, int num3, int num4, int num5, int num6){
  this.num1 = num1;
  this.num2 = num2;
  this.num3 = num3;
  this.num4 = num4;
  this.num5 = num5;
  this.num6 = num6;
}
```

> 생성자 오버로딩 중에 생성자 User에 yellowError가 발생했다. 원인은 접근 제한자를 아무것도 쓰지 않아서, 더 접근 제한이 강한 private을 쓰라는 얘기이다. 그런데 내 생각에 아직 이 생성자를 통해 객체를 생성하지 않았기 때문에 yellowError가 발생한 것 같다. 만약 다른 클래스에서 객체를 생성하게 되면 에러가 사라질 것 같다. 



### 2.  Non-static field 'user' cannot be referenced from a static context

---

* void main 속에 있는 user에서 에러가 났다. 
* 왜 에러가 발생한 것일까? 

```java
public class BuilderPattern {
  User user = new User(3);
  
  public static void main(String[] args){
    user.getNum1();
  }
}
```

* 에러 이유를 보면 non-static field 'user' 이라고 나와있다. 

인스턴스 user은 전역 변수가 아니기 때문에 public static void main에는 user라는 객체를 사용할 수 없다. 하지만 static 메소드가 아닌 일반 method()의 경우에는 클래스에서 선언한 변수들을 사용할 수 있다. 

static 메소드에 사용될 수 있는 변수는 해당 메소드에서 선언된 지역변수 또는 외부의 static 변수에 한해서 사용이 가능하다. 

#### solution

* Static fields and methods are connected to the class itself and not its instances.

```java
public class BuilderPattern {
  
  public static void main(String[] args){
    User user = new User(3);
    user.getNum1();
  }
}
```

* 사용할 블럭에서 객체를 생성해야 한다. 왜냐하면 main 블럭은 class BuilderPattern의 다른 블럭이기 때문이다. 

#### 또는

```java
public class BuilderPattern {
  static User user = new User(3);
  
  public static void main(String[] args){
    user.getNum1();
  }
}
```

* 이런 식으로 static 전역 변수 선언을 해야 한다. 