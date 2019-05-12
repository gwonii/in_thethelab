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



### 4. Formating 

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
* 블럭 들여쓰기는 기본적으로 2번 이상의 스페이스를 이용한다. (일반적은 nextline에서 사용)

## 4.3 One statement per line

* 하나의 문장은 한 라인에 표기해라. (두 줄에 나눠서 표현하지 말고)

## 4.4 Column limit: 100

* 한 라인의 100자 이상을 사용하지 말아라 (unicode에 한해서), 만약 100자를 넘기게 된다면 line-wrapping할 수 있도록 

## 4.5 Line-wrapping

* 용어 정리 : When code that might otherwise legally occupy a single line is divided into multiple lines, this activity is called *line-wrapping*

  Expression이  한 줄에 들어가지 않는 경우, 다음과 같은 일반적인 원칙에 다라 두 줄로 분리한다.

#### 4.5.1 Where to break

* The prime directive of line-wrapping is: prefer to break at a **higher syntactic level**

  line-wrapping을 하는 주된 목적은 더 높은 문법적 수준을 깨는 것이다. 

  1. non-assignment operator에 의해 라인이 끊어질때는 symbol 전에 끊어라
     * the dot separator ( . )
     * the two colons of a method reference ( :: )
     * an ampersand in a type bound ( <T extends Foo & Bar >)
     * a pipe in a catch block ( catch (FooException | BarException e) )
  2. When a line is broken at an *assignment* operator the break typically comes *after* the symbol, but either way is acceptable

  ```java
  longName1 = longName2 * (longName3 + longName4 - longName5) 
          + 4 * longname6; 	
  		// 될 수 있으면 이 방법을 사용한다.
                  
  longName1 = longName2 * (longName3 + longName4 
          - longName5) + 4 * longname6;    
  		// 될 수 있으면 피한다.
  
  ```

  3. A method or constructor name stays attached to the open parenthesis (`(`) that follows it.
  4. A comma (`,`) stays attached to the token that precedes it.

  ```java
  someMethod(longExpression1, longExpression2, longExpression3, 	
          longExpression4, longExpression5);
  
  ```

  

  5. A line is never broken adjacent to the arrow in a lambda, except that a break may come immediately after the arrow if the body of the lambda consists of a single unbraced expression. Examples:

#### 4.5.2 Indent continuation lines at least +4 space 

* When line-wrapping, each line after the first (each *continuation line*) is indented at least +4 from the original line.

  한 줄의 코드를 line-wrapping 하는 경우 기본적으로 4칸의 space를 해줄 것 

## 4.6 Whitespace

* 한 줄의 blank line은 아래와 같은 상황에서 사용된다. 

  1. *Between* consecutive members or initializers of a class: fields, constructors, methods, nested classes, static initializers, and instance initializers.

     기본적은 맴버 사이에서 blank line을 사용한다. (ex. 필드, 생성자, 메소드, 중첩 클래스 등등)

     * **Exception** : 연속된 필드 값에 의해서는 사용자의 선택에 따라 blank line을 사용하기도 하고 사용하지 않기도 한다. (기준: logical grouping )
     * **Exception** : 연속된 enum 변수들 사이에는 blank line을 사용하지 않는다. 

  2. As required by other sections of this document

     source file 또는 import문을 사용하는데 있어서는 blank line을 사용해준다. 

* 그 외에도 더 좋은 readability 또는 logical grouping을 위하여 blank line이 사용될 수 있다. 작성자의 판단에 따라 blank line을 적절히 사용할 수 있도록. ( 주의 : 의미 없는 blank line은 그저 코드의 길이만 길게 만들 뿐!)

#### 4.6.2 Horizontal whitespace

* 일단 패스 (들여쓰기라도 먼저 잘 알아두자)

#### 4.6.3  Horizontal alignment: never required



## 4.8 Specific constructs 

#### 4.8.1 Enum classes

#### 4.8.2 Variable declarations

* 변수 선언은 한 줄에 하나씩 선언을 해준다. 

  ```java
  int a,b; 			// deprecated
  
  int a;
  int b;
  ```

* Local variables are **not** habitually declared at the start of their containing block or block-like construct. Instead, local variables are declared close to the point they are first used (within reason), to minimize their scope. Local variable declarations typically have initializers, or are initialized immediately after declaration.

  지역 변수의 선언은 습관적으로 도입 부에 할 것이 아니라, 해당 지역변수가 필요한 부분에 가깝게 선언해준다. 

  

#### 4.8.3 Arrays

* 배열의 선언은 "block-like" 하게 선언해준다. 

  ```java
  new int[] {           new int[] {
    0, 1, 2, 3            0,
  }                       1,
                          2,
  new int[] {             3,
    0, 1,               }
    2, 3
  }                     new int[]
                            {0, 1, 2, 3}
  ```

* c style의 배열 선언을 하지 않는다. 

  ```java
  String args[] 				// deprecated
  
  String[] args
  ```

  

#### 4.8.4 Switch statements

##### 	4.8.4.1 Indentation

* swtich에서 label을 선언한 후 line break 해주고,  +2 space를 이용하여 indent 해준다. 

  ```java
  switch (input) {
    case 1:							// case: 1, case 2: 로 작성하지 않는다.
    case 2:
      prepareOneOrTwo();
      // fall through
    case 3:
      handleOneTwoOrThree();
      break;
    default:
      handleLargeNumber(input);
  }
  ```

#### 4.8.5 Annotation

#### 4.8.6 Commnet

* block 주석 

  ```java
  /*
  ~~~
  */
  ```

* line 주석 

  ```java
  // ~~~
  ```



#### 4.8.7 Modifiers(제어자)

* 용어 정리 : 
  * Access Modifer : public, protected, default, private
  * ect. Modifer : static, final, abstractr, native ...

### 5. Naming

---

## 5.1 Rules common to all indentifiers

* Indentifier은 무조건 문자 또는 숫자만을 사용한다. 
* 특별한 prefixs, suffixes를 사용하지 않는다. (ex. "name_", "mName", "s_name", "KName" 등등)



## 5.2 Rules by indentifier type

#### 5.2.1 Package names

* 패키지 identifier은 소문자만을 사용한다.  (no underscores) 

  ```java
  com.example.deppSpace				// deprecated
  
  com.example.deep_space				// deprecated
      
  com.example.deepspace
  ```

#### 5.2.2 Class names

* 클래스 identifier은 UpperCamelCase를 사용한다. 

  ```java
  class Character {}					// 하나의 단어는 첫 글자를 대문자로 사용한다.
  
  class ImmutableList {}				// 두 단어 사용시 
  
  ```

#### 5.2.3 Method names

* 메소드 identifier은 lowerCamelCase를 사용한다. 

  ```java
  void stop() {...}					// 한 단어시 그냥 소문자로 작성
  
  void sendMessage() {...}			// 두 단어시 클래스와 달리 소문자로 시작
  
  ```

#### 5.2.4 Constant names

* Constant identifier은 all uppercase letter로 작성해준다.

  ```java
  static final int NUMBER = 5;
  static final ImmutableList<String> NAMES = ImmutableList.of("Ed", "Ann");
  static final ImmutableMap<String, Integer> AGES = ImmutableMap.of("Ed", 35, "Ann", 32);
  static final Joiner COMMA_JOINER = Joiner.on(','); // because Joiner is immutable
  static final SomeMutableType[] EMPTY_ARRAY = {};
  enum SomeEnum { ENUM_CONSTANT }
  
  
  ```

#### 5.2.5 Non-constant field names

* 상수가 아닌 변수는 lowerCamelCase를 사용한다. 

#### 5.2.6 Parameter names

* 매개변수는 lowerCamelCase를 사용한다. 

#### 5.2.7 Local variable names

* 지역변수는 lowerCamelCase를 사용한다. 

#### 5.2.8 Type variable names

* A single capital letter , optionally followed by a single numeral  (ex. E, T, X ,T2 등)
* A name in the form used for classes, followed by the capital letter T (ex. RequestT, FooBarT)

## 5.3 Camel case : defined 

* 아직 사용할 일 없을 것 같으니 일단 패스 나중에 천천히 쓰게되면 배우자. 

### 6. Programming Practices

---

## 6.1 @Overried : always uesd

* 오버라이드를 한 부분에 있어서는 @Override 어노테이션을 항상 쓸 수 있도록 해라. 

## 6.2 Caught exceptions : not ignored

* 예외처리는 필수적으로 하라는 얘기겠지..? 

## 6.3 Static members : qualified using class 

* When a reference to a static class member must be qualified, it is qualified with that class's name, not with a reference or expression of that class's type.

* 클래스 맴버로 정적 변수를 사용할 때, 그 변수를 사용할 때 객체의 이름이 아닌 클래스의 이름을 사용하라.  변수와 함께 메소드도 마찬가지 이다. 

  ```java
  Foo aFoo = ...;
  Foo.aStaticMethod(); // good
  aFoo.aStaticMethod(); // bad
  somethingThatYieldsAFoo().aStaticMethod(); // very bad
  ```

## 6.4 클래스 변수와 인스턴스에 대한 접근을 제공한다. 

* 인스턴스 또는 클래스의 변수를 합당한 이유 없이 public 으로 선언하지 말아라. 

  > 인스턴스 변수가 public으로 선언되는 것이 적절한 경우는 클래스가 본래 behavior를 가지지 않는 data structure 일 경우이다. 

## 6.5 괄호 

* 연산자 우선순위 문제를 가질 수 있는 expression의 경우, 괄호를 사용할 것을 권장한다. 다른 개발자가 오해를 할 수 있도 있다. 

## 6.6 리턴 값 

* 프로그램의 구조와 목적이 일치해야 한다. 

  ```java
  if (booleanExpression) {
   return true;
  } else {
   return false;
  } 									// 이렇게 사용하는 것 보다 
  
  
  return booleanExpression; 			// 리턴값의 의미를 알 수 있도록 만드는 것이 좋다. 
  
  ```

  

### 7. Javadoc

---

