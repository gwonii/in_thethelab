# List Class 



## 1. Linked List

### 1.1 개요 

* list클래스를 기반으로 파생한 클래스이다.
* 배열과 같은 선형 자료구조이다.  

### 1.2 장점 

* 특정 위치에 추가, 삭제하는데 비용이 적다. 
* 서로 다른 컬렉션을 하나로 병합하거나 분리하는 비용이 적다. 

### 1.3 단점 

* 인덱스 연산을 하는데 있어서 배열 형태인 vector와 arrayList보다 비용이 높다. 

### 1.4 메소드 

oracle api 참조 

#### 주요 메소드 

| Type              | Description                                                  |
| :---------------- | ------------------------------------------------------------ |
| `boolean`         | `add(E e)`Appends the specified element to the end of this list. |
| `void`            | `add(int index, E element)`Inserts the specified element at the specified position in this list. |
| `void`            | `addFirst(E e)`Inserts the specified element at the beginning of this list. |
| `void`            | `addLast(E e)`Appends the specified element to the end of this list. |
| `boolean`         | `offer(E e)`Adds the specified element as the tail (last element) of this list. |
|                   |                                                              |
| `void`            | `clear()`Removes all of the elements from this list.         |
| `Object`          | `clone()`Returns a shallow copy of this `LinkedList`.        |
| `boolean`         | `contains(Object o)`Returns `true` if this list contains the specified element. |
| `E`               | `element()`Retrieves, but does not remove, the head (first element) of this list. |
| `E`               | `get(int index)`Returns the element at the specified position in this list. |
| `E`               | `getFirst()`Returns the first element in this list.          |
| `E`               | `getLast()`Returns the last element in this list.            |
| `ListIterator<E>` | `listIterator(int index)`Returns a list-iterator of the elements in this list (in proper sequence), starting at the specified position in the list. |
|                   |                                                              |
| `E`               | `peek()`Retrieves, but does not remove, the head (first element) of this list. |
| `E`               | `poll()`Retrieves and removes the head (first element) of this list. |
| `E`               | `pop()`Pops an element from the stack represented by this list. |
| `void`            | `push(E e)`Pushes an element onto the stack represented by this list. |
| `E`               | `remove()`Retrieves and removes the head (first element) of this list. |
| `E`               | `remove(int index)`Removes the element at the specified position in this list. |
| `boolean`         | `remove(Object o)`Removes the first occurrence of the specified element from this list, if it is present. |
| `E`               | `set(int index, E element)`Replaces the element at the specified position in this list with the specified element. |
| `int`             | `size()`Returns the number of elements in this list.         |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |
|                   |                                                              |



## 2. Array List

### 2. 1 개요 

* array 와 list의 형식을 조합 

일반적인 배열을 선언해서 사용하게 된다면 인덱스를 다 채우거나 인덱스를 다 못채울 수도 있는데 이러한 경우 인덱스가 가득찼다면 더 이상 값을 넣지 못할 것이다. 인덱스가 남는다면 메모리가 낭비되는 현상이 일어난다. 

이러한 문제를 해결하기 위해 java에서는 ArrayList class를 제공하고 있다. 

#### 기본 배열은 처음에 객체를 생성할 때 개수를 정해야 한다. 하지만 개수를 정하게 되면 이후의 유지,보수에 문제점이 발생할 수 있다. 그렇기 때문에 java에서는 ArrayList를 통해 이 문제를 해결하고 있는 것이다. 

### 2.2 장점 

* 처음에 크기를 정하지 않고, 동적으로 크기가 변경된다. 
* 특정 위치에 element를 추가/삭제 할 수 있다. 

### 2.3 ArrayList 생성

* ArrayList class로 리스트를 만들기 위해서는 리스트에 저장할 데이터의 타입을 정해야 한다.  또한 ArrayList class를 포함한 모든 자료구조 클래스는 레퍼런스 타입의 데이터만 저장할 수 있다. 

```java
List<TYPE> list = new ArrayList<TYPE>();
```





### 2.3 변환 

#### Array -> ArrayList

* array를 array List로 변환 시킬 수 있다. 
* `Array.asList(array)` 을 이용하면 된다. 

```java
String[] StirngArray = new String[];
StringArray = {"one", "two", "three"};

List<> arrayList = new ArraryList<>(Array.asList(StringArray));

System.out.println(list);
```

> ArrayList를 생성할 때 array를 담아 생성한다. 

#### 그러나 primitive type의 경우는 위 처럼 사용할 수 없다.

*  primitive type을 arraryList로 바꾸고 싶을 때 

```java
int[] intArray = {1,2,3};
List<Intger> intList = new ArrayList<>();

for(int i : array) {
    list.add (i);
}

System.out.println(list);
```

#### 

#### ArrayList -> Array

* 반대로 ArrayList를 Array로 변환시킬 수 있다. 

```java
List<Stirng> stringList = new ArrayList<>();
list.add("one");
list.add("two");

String[] stringArray = new String[list.size()];
list.toArray(list);

for(String i : stringArray){
    System.out.println(i);
}
```

#### 일단 오늘은 ArrayList와 LinkedList 까지 알아보는 것으로 하겠습니당. 





> List 클래스를 기반으로 생겨난 클래스들은 Collection 인터페이스에 약속한 기능을 구현하고 있다. 

### list 사용방법 

```java
List<Stirng> stringList = new ArrayList<>();
list.add("one");
list.add("two");

(1)
Iterator iterator = stringList.iterator();
while(iterator.hasnext()){
    String next = iterator.next();
}

(2)
for(String next : stringList){
    ~~~
}

(3)
for(int i = 0; i < stringList.size(); i++){
    String next = stringList.get(i);
}
```



## 



