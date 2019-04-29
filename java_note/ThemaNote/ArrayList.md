## ArrayList 



## 1. ArrayList란? 

---

* ArrayList java에서 제공하는 class이다. 
* ArrayList는 배열에서 발전된 형태라고 보면 된다. 

일반적인 배열을 선언해서 사용하게 된다면 인덱스를 다 채우거나 인덱스를 다 못채울 수도 있는데 이러한 경우 인덱스가 가득찼다면 더 이상 값을 넣지 못할 것이다. 인덱스가 남는다면 메모리가 낭비되는 현상이 일어난다. 

이러한 문제를 해결하기 위해 java에서는 ArrayList class를 제공하고 있다. 

#### 기본 배열은 처음에 객체를 생성할 때 개수를 정해야 한다. 하지만 개수를 정하게 되면 이후의 유지,보수에 문제점이 발생할 수 있다. 그렇기 때문에 java에서는 ArrayList를 통해 이 문제를 해결하고 있는 것이다. 

## 2. ArrayList 객체생성 

---

* ArrayList class로 리스트를 만들기 위해서는 리스트에 저장할 데이터의 타입을 정해야 한다.  또한 ArrayList class를 포함한 모든 자료구조 클래스는 레퍼런스 타입의 데이터만 저장할 수 있다. 

```java
ArrayList<TYPE> list = new ArrayList<TYPE>();
```

## 3. ArrayList Method

---

| 용도 | 문법        | 설명                              |
| ---- | ----------- | --------------------------------- |
| 삽입 | list.add    | list 타입에 맞는 항목을 추가한다. |
| 수정 | list.set    | list 타입에 맞는 항목을 수정한다. |
| 삭제 | list.remove | list 타입에 맞는 항목을 제거한다. |

## 4. 예제

```java
public class Main {

  public static void main (String[] args){
    ArrayList<Stirng> list = new ArrayList<Stirng>;
    
    list.add("hi");
    list.add("hello");
    list.add("안녕");
    
    for(int i = 0; i < list.size(); i++){
      System.out.println(list.get(i));
    }
  }
}
```

| 용도                    | 문법        | 설명                                |
| ----------------------- | ----------- | ----------------------------------- |
| 리스트의 값 반환        | list.get(i) | list의 해당 인덱스의 값을 반환한다. |
| 리스트의 전체 길이 반환 | list.size() | list의 전체 길이의 값을 반환한다.   |



> <https://docs.oracle.com/javase/8/docs/api/> _ api 공식 홈페이지   