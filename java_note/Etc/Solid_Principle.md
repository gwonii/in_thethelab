## Solid 원칙 

### 1. SRP ( Single Responsibility Principle )

#### 1.1 정리

* 클래스는 하나의 기능만 가지며, 클래스가 제공하는 모든 서비스는 하나의 책임을 수행하는데 집중되어야 한다. 
* 클래스를 변경될 수 있는 이유는 해당 클래스가 갖고 있는 책임소재를 분리하거나 병합하고 싶을 때 이다. 
* SRP원리를 적용하면 무엇보다 책임 영역이 확실해진다. 때문에 한 책임의 변경에서 다른 책임의 변경으로 연쇄작용에서 자유로울 수 있다. 
* 책임을 적절히 분배하면, 코드의 가독성 향상과 유지보수비용의 절감의 이점을 누릴 수 있다. 
* 항상 **책임** 에 대한 생각을 잊지말고 코드를 작성하라.

####  1.2 적용 방법 

> 리팩토링에서 소개하는 대부분의 위험상황에 대한 해결방법은 직/간접적으로 SRP원리와 관련이 있다. 이는 항상 코드를 최상으로 유지한다는 리팩토링의 근본정신도 항상 객체들의 책임을 최상의 상태로 분배한다는 것에서 비롯되기 때문이다. 

1. 여러 원인에 의한 변경 (Divergent Change)

   * extract class를 통해 혼재된 각 책임을 각각의 개별 클래스로 분할하여 클래스 당 하나의 책임만을 맡도록 하게 한다. 
   * 여기서 관건은 책임만 분리하는 것이 아니라 분리된 두 클래스간의 관계의 복잡도를 줄이도록 설계하는 것이다. 

   > extract class : 두 개의 클래스가 해야 할 일을 하나의 클래스가 하고 있는 경우 새로운 클래스를 만들어서 관련있는 필드와 메소드를 예전의 클래스에서 새로운 클래스로 옮기는 것 

   * 만약 extract class된 각각의 클래스들이 유사하고 비슷한 책임을 중복해서 갖고 있다면, super class를 사용할 수 있다. extract된 각각의 class들의 공유되는 요소를 부모 클래스로 정의하여 부모 클래스에 위임하는 기법. 

2. 산탄총 수술 (Shotgun Surgery)

   * move field와 move method를 통해 책임을 기존의 어떤 클래스로 모으거나, 이럴만한 클래스가 없다면 새로운 클래스를 만들어 해결한다. 

   **주의사항** : 클래스는 자신의 이름이 나타내는 일을 해야 한다. 올바른 클래스 이름은 해당 클래스의 책임을 나타낼 수 있는 가장 좋은 방법이다. 각 클래스는 하나의 개념을 나타내야 한다. 

#### 1.3 예제

#### Original Code 

```java
public class SettingUserInfo {
    public void changeEmail(User user) {
       //전달 받은 user를 통해 user의 email을 변경한다.  
    }
    public void checkAccess(User user) {
       //전달 받은 user를 통해 user의 접근 권한을 확인한다.    
    }
}
```

> 위 SettingUserInfo에서 두 가지 메소드가 씌이고 있다. 하지만 유저의 이메일을 변경하는 것과 유저의 접근을 확인하는 것은 엄연히 다른 기능이다. 그러므로 SRP 원칙에 따라 하나의 클래스는 하나의 책임을 할 수 있도록 분리해주는 것이 좋다. 

#### Changed Code

```java
public class SettingUserInfo {
    public void changeEmail(User user) {
        //전달 받은 user를 통해 user의 email을 변경한다.
    }
}

public class CheckUserInfo {
    public void checkAccess(User user) {
        //전달 받은 user를 통해 user의 접근 권한을 확인한다.
    }
}
```

> 이렇게 두 가지 클래스로 나누어 각자의 책임을 분배하는 것이 좋다. 

#### 1.4 결론

* 무조건 책임을 분리한다고 SRP가 적용된 것은 아니다. 각 개체간의 응집력이 있다면 병합이 순 작용의 수단이 되고, 결합력이 있다면 분리가 순 작용의 수단이 되는 것이다. 



### 2. OCP ( Open Close Principle )

#### 2.1 정리 

* 소프트웨어의 구성요소 ( 컴포넌트, 클래스, 모듈, 함수)는 확장에는 열려있고, 변경에는 닫혀있어야 한다는 원리.
* 요구사항의 변경이나 추가사항이 발생하더라도 기존 구성요소는 수정이 일어나지 말아야 하며, 기존 구성요소를 쉽게 확장해서 재사용할 수 있어야 한다는 뜻이다. 
* OCP는 관리가 가능하고 재사용이 가능한 코드를 만드는 기반이며, OCP를 가능케 하는 중요 메커니즘은 추상화와 다형성이라고 설명하고 있다. 

#### 2.2 적용 방법 

1. 변경될 것과 변경되지 않을 것을 엄격히 구분한다. 
2. 두 모듈이 만나는 지점에 인터페이스를 정의한다. 
3. 구현에 의존하기보다 정의한 인터페이스에 의존하도록 코드를 작성해야 한다. 

#### 2.3 예제 

#### Original Code

```java
// 핸드폰을 컴퓨터에 연결을 시도하면 연결을 시켜주는 소프트웨어 설계 

public class BootStrap {
    public static void main(String[] args){
        Computer computer = new Computer();			
        computer.boot();
    }
}

public class Computer {
    
    private final KakaoPhone kakaoPhone = new KakaoPhone();
    
    public void boot() {
    	System.out.println("핸드폰 연결중");
        kakaoPhone.connect();
    }
}

public class KakaoPhone {
    public void connect() {
        // 핸드폰을 컴퓨터에 연결하는 메소드 
    }
}
```

#### 문제점

위의 코드는 Computer class에서 KakaoPhone의 객체를 생성하여 핸드폰을 컴퓨터에 연결하고 있다. 하지만 만약 KakaoPhone이외에 다른 핸드폰을 연결하려고 한다면? 

그러면 새로운 핸드폰을 위한 클래스를 생성해야 하고 그에 맞는 코드를 다시 수정하여 작성해야 한다. 

여기서 우리는 핸드폰 연결을 위한 **interface Phone**을 만들어 보는 것에 대해 생각할 수 있다.

#### Changed Code

##### Phone 인터페이스 

```java
public interface Phone{
    public void connect() {
        // 핸드폰가 컴퓨터를 연결하는 메소드 
    }
}
```



##### 실행 관련 class들 

```java
public class BootStrap {
 
    private Computer computer = new Computer(new KakaoPhone);
    
    System.out.println("컴퓨터를 부팅합니다.");
    computer.boot();
}

public class Computer {
    Phone phone;
    
    Computer(Phone phone){
        this.phone = phone;
    }
   	System.out.println("핸드폰을 연결합니다.")
    phone.connect();
}

public class KakaoPhone implements Phone {
    public void connect() {
        // KakaoPhone에 맞는 메소드로 수정
    }
}
```

#### 변경사항 

1. KakaoPhone을 일반 클래스가 아닌 인터페이스를 상속받는 클래스로 만들었다. 
2. BootStrap 클래스에서 Computer 클래스를 사용할 때 원하는 기기의 객체를 만들 수 있도록 하였다. 

결과적으로 보자면, 클래스를 확장 가능하게 만들고 클래스를 변경하지 못하도록 만들었다. 

KakaoPhone 클래스는 Phone이라는 인터페이스를 상속받으면서 이제 Phone이라는 인터페이스만 이용하면 KakaoPhone 뿐만 아니라 SamsungPhone, Iphone등 여러 기기들을 쉽게 만들 수 있는 Phone을 확장가능하게 만들었다. 

동시에 Computer 생성자 메소드의 매개변수에는  `Phone phone`으로 지정해놓았지만 객체를 생성하려고 생성자 메소드를 사용할 때는 `new KakaoPhone`을 사용했다. 이것은 객체의 다형성을 이용한 것이다. 

이제 새로운 핸드폰 기기가 생겨나면, 다른 코드는 변경하지 않고  Phone을 상속한 클래스를 만들어 사용만 하면 되는 것이다. 

####  