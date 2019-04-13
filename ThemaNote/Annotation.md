# Annotation 정리 



## 1. java annotation 이란? 

---

* AOP (Aspect Oriented Programming: 관심 지향 프로그래밍)을 편리하게 구성할 수 있다. 

* annotation을 이용하면 코드를 좀 더 선언적으로 표현할 수 있다. 

* #### An *annotation* is a marker which associates information with a program construct, but has no effect at run time.

> <https://dzone.com/articles/what-are-meta-annotations-in-java>

## 2. annotation과 comment의 차이 

---

* 사전적 의미로 둘 다 **주석** 이라는 의미를 가지고 있다.

* #### annotation의 특징 

  * 코드에 영향을 준다. 
  * 컴파일 타임, 런타임에 영향을 준다. 
  * 커스텀해서 사용할 수 있다. 

* #### comment의 특징 

  * 코드에 영향을 주지 않고 가독성을 위하여 존재한다. 



## 3. Annotation 종류  

---

* #### Built-in Annotation  (한글)

| 문법                 | 설명                                                         |
| -------------------- | ------------------------------------------------------------ |
| @Override            | 메소드가 오버라이드 됐는지 검증한다. 만약 부모 클래스 또는 구현해야 할 인터페이스에서 해당 메소드를 찾을 수 없다면 컴파일 오류가 난다. |
| @Deprecated          | 메소드를 사용하지 말도록 유도한다. 만약 사용한다면 컴파일 경고를 일으킨다. |
| @SuppressWarnings    | 컴파일 경고를 무시하도록 한다.                               |
| @SafeVarargs         | 제네릭 같은 가변인자 매개변수를 사용할 때 경고를 무시한다.   |
| @FunctionalInterface | 람다 함수 등을 위한 인터페이스를 지정한다. 메소드가 없거나 두 개 이상 되면 컴파일 오류가 난다. |

* #### Built-in Annotation (영문)

| Syntax               | contents                                                     |
| -------------------- | ------------------------------------------------------------ |
| @Override            | Checks that the method is an override. Causes a compile error if the method is not found in one of the parent classes or implemented interfaces. |
| @Deprecated          | Marks the method as obsolete. Causes a compile warning if the method is used. |
| @SuppressWarnings    | Instructs the compiler to suppress the compile time warnings specified in the annotation parameters. |
| @SafeVarargs         | Suppress warnings for all callers of a method or constructor with a generics varargs parameter, since Java 7. |
| @FunctionalInterface | Specifies that the type declaration is intended to be a functional interface, since Java 8. |

* #### Meta Annotation  (한글)

Meta Annotation을 활용해 Custom Annotation을 만들 수 있다. 

| 문법        | 설명                                          |
| ----------- | --------------------------------------------- |
| @Retention  | annotation의 Life Time이다.                   |
| @Documented | 문서에도 annotation 정보가 표현된다.          |
| @Target     | 적용할 위치를 결정한다.                       |
| @Inherited  | 자식 클래스가 annotation을 상속 받을 수 있다. |
| @Repeatable | 반복적으로 annotation을 선언할 수 있다.       |

* #### Meta Annotation (English)

| Syntax      | Contents                                                     |
| ----------- | ------------------------------------------------------------ |
| @Retention  | Specifies how the marked annotation is stored—Whether in code only, compiled into the class, or available at runtime through reflection. |
| @Documented | Marks another annotation for inclusion in the documentation. |
| @Target     | Marks another annotation to restrict what kind of Java elements the annotation may be applied to. |
| @Inherited  | Marks another annotation to be inherited to subclasses of annotated class (by default annotations are not inherited to subclasses). |
| @Repeatable | Specifies that the annotation can be applied more than once to the same declaration, since Java 8. |

## 4. Declare Custom Annotation

---

* Annotation 은 사용자가 원하는 대로 커스터마이징하여 사용할 수 있다. 

```java
public @interface MyAnnotation {} 
```



