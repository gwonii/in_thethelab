# Google Java Style Guide



### 1. Introduction 

---

## 1.1 Terminology notes (용어 노트)

1. The term *class* is used inclusively to mean an "ordinary" class, enum class, interface or annotation type 
2. The term *member* (of a class) is used inclusively to mean a nested class, field, method, *or constructor*; that is, all top-level contents of a class except initializers and comments.
3. The term *comment* always refers to *implementation* comments. We do not use the phrase "documentation comments", instead using the common term "Javadoc."

## 1.2 Guide notes (가이드 노트)

1. 구글의 code style이 무조건적인 것은 아니며 다른 방법으로도 표현이 가능하다! (하지만 구글 스타일을 따를 것....)



### 2. Source file basics

---

## 2.1 File name

* java 소스 파일의 이름은 최상위 클래스의 이름을 따라 대소문자를 구분하여 작성한다. 

## 2.3 Special characters

#### 2.3.1  Whitespace characters

* 공백문자는 "스페이스바"를 이용한다. 탭을 이용하는 것을 권장하지 않는다. 

#### 2.3.2 Special escape sequences

* 특수문자의 경우 대응하는 8진법이나 유니코드를 사용하지 않는다. 
* '\b' , '\n', '\\\'  등으로 특수문자 수식을 이용한다. 

#### 2.3.3 Non-ASCII characters 

* 아식스코드가 아닌 문자들의 경우 가독성을 기준으로 작성한다. 

> 이런 코드를 사용할 때는 설명적 주석을 달아주는 것이 좋다. 그것이 무엇인지에 대해서 

### 3. Source file structure

---

* 소스 파일의  순서에 맞게 작성되어야 한다. 

1. License or copyright information , if present 
2. Package statement 
   * 패키지문의 경우 아무리 길어도 한 문장으로 써야 한다. 
3. Import statements
   * import 문에는 *을 쓰지 않는다. Package 문과 동일하게 한 문장에 작성한다.
   * import 문은 그룹핑을 해서 순서에 맞춰 작성한다. 
4. Exactly one top-level class
   * 하나의 자바 파일에는 하나의 class만 존재해야 한다. 
   * 클래스 멤버의 순서는 논리적이여야 한다. 
   * 동일한 메소드 명(생성자들, 오버라이딩된 메소드들)을 가진 것들은 한 곳에 모아둬야 한다.  

#### 빈 줄을 통해 섹션을 분리해줘야 한다. 

### 4. Formatiing 

---

## 4.1 Braces

#### 4.1.1 Braces are used where optional

* if, else, for, do, while 등에는 무조건 중괄호를 붙여야 한다. (생략이 가능하지만)

#### 4.1.2 Nonempty block

* 여는 중괄호 뒤에는 코드가 없어야 한다. 
* 닫는 중괄호 앞에는 다른 코드가 없어야 한다. 
* 문장에 닫는 중괄호만 있는 경우는 함수가 끝나거나 제어문이 끝날 때이다. 

#### 4.1.3 Empty blocks: may be concise

* 빈 블럭의 닫는 중괄호는 다음 라인으로 넘기지 않는다. (그게 더 깔끔 하니까)

  ```java
  void doNothing() {}
  ```

## 4.2 Block indentation: +2 space

* Each time a new block or block-like construct is opened, the indent increases by two spaces. When the block ends, the indent returns to the previous indent level. The indent level applies to both code and comments throughout the block
* 블럭 들여쓰기는 기본적으로 2번 이상의 스페이스를 이용한다. 

## 4.3 One statement per line

* 하나의 문장은 한 라인에 표기해라. (두 줄에 나눠서 표현하지 말고)

## 4.4 Column limit: 100

* 



### 5. Naming

---



### 6. Programming Practices

---



### 7. Javadoc

---

