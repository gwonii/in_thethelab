# Git branch



# 1. Git branch란? 

* 개발을 하다 보면 코드를 여러 개로 복사해야 하는 일이 자주 생긴다. 코드를 통째로 복사하고 나서 원래 코드와는 상관없이 독립적으로 개발을 진행할 수 있는데, 이렇게 독립적으로 개발하는 것이 브랜치다.

## 1.1 Git의 데이터 저장방식 

* git branch를 이해하기 전에 git의 데이터 저장방식에 대해 정확히 이해할 필요가 있다. 

  * git은 데이터를 change set하거나 변경사항으로 기록하지 않고 일련의 스냅샷으로 기록을 한다. 
  * git에서 commit을 하면 현 staging area에 있는 데이터의 스냅샷에 대한 포인터, 저자나 커밋 메시지 같은 메타 데이터, 이전 커밋에 대한 포인터 등을 포함하는 커밋 객체를 저장한다. 
  * 이전 커밋 포인터가 존재하기 때문에, 현재 커밋이 무엇을 기준으로 바뀌었는지 알 수 있다. 
  * 커밋을 실시하면, 총 5개의 파일이 생성된다.  (ex. 파일 3개를 commit한 상태로 가정한다.)
    1. 메타데이터와 루트 트리를 가리키는 포인터가 담긴 커밋 객체
    2. 파일과 디렉토리 구조가 들어 있는 트리 객체
    3. 파일 정보를 담은 객체 1
    4. 파일 정보를 담은 객체 2
    5. 파일 정보를 담은 객체 3
  * git의 branch는 커밋 사이를 가볍게 이동할 수 있는 어떤 포인터 같은 것이다. 
  * 기본적으로 git은 master branch를 만들고, 처음 커밋하면 이 master branch가 생성된 커밋 포인터를 가리킨다. 이 후 커밋을 만들면 master branch는 자동으로 가장 마지막 커밋을 가리킨다. 

  

## 1.2 New Branch

* 새로운 브런치를 하나 만들어 보자. 

  ```c
  $git branch testBranch
  ```

* 기본적으로 새롭게 branch를 만들면 master가 가리키고 있는 지금 작업하고 있던 마지막 커밋을 가리킨다. 

* git에는 HEAD라는 특수한 포인터가 있다. 피 HEAD는 지금 작업하고 있는 로컬 브랜치를 가리킨다. 브랜치를 새로 만들었지만, git은 아직 master 브랜치를 가리키고 있다. ( 위의 명령어는 branch를 생성하기만 했을 뿐 HEAD의 포인터 값은 변경시키지 않는다.)

### 1.2.1 현재 작업중인 브랜치가 가리키는 HEAD 파악하기

* 명령어 : git log를 통해 파악할 수 있다.

  ```
  $git log --oneline --decorate
  ```

> $git log를 사용하면 branch의 상태도 알 수 있긴 하지만 지금까지의 로그가 다 뜨기 때문에 
>
> --oneline 명령어도 함께 써주자. 

#### 1.2.2 브랜치 변경하기 

* 명령어 : git checkout 명령으로 다른 브랜치로 이동할 수 있다. 

  ```
  $git checkout testBranch
  ```

* 이 명령을 사용하면 이제서야 HEAD가 testBranch를 가리키기 시작한다.

#### 1.2.3 브랜치 변경 후  commit 하기 

* 브랜치가 testBranch로 바뀌었으니 새롭게 파일을 변경하고 커밋을 해보자 . .

  ```
  $vi test.c					// test.c 파일 수정하기 
  $git commit -a -m "change a variable name"
  ```

* 이렇게 되면 변경 후 커밋을 했으므로 새로운 스냅샷이 생겨나고 testBranch는 새롭게 커밋된 스냅샷을 가리키고 있다. 하지만 master는 그 이전에 가리키고 있었던 스냅샷을 변화없이 가리키고 있다. 

  ![](C:\Users\hoho\Desktop\캡처1.PNG)

* 이제 다시 master로 branch를 옮겨보자 

* 그러면 branch는 다시 master로 돌아오게 되고, 그 후 다시 파일을 변경하고 커밋을 한다고 가정해보자. 

  ```
  $vi test.c
  $git commit -a -m "master change a fileName"
  ```

* 이렇게 되면 master branch로 새롭게 커밋을 한 것이기 때문에 이전에 testBranch가 커밋한 것과는 다른 새로운 커밋이 생기는 것이다. 

  ![](C:\Users\hoho\Desktop\캡처.PNG)

* 그러면 하나의 파일을 가지고 여러 branch를 이용해서 독립적으로 프로젝트를 진행할 수 있다. 
* 이 후 이렇게 갈라진 커밋 자료들을 merge를 통해 합칠 수 있다. 

#### 1.2.4 브랜치 history 파악하기 

* 여러 브랜치를 사용하다보면, 어떻게 브랜치가 변화했는지 파악이 힘들 수 있다. 

  ```
  $git log --oneline -- decorate --graph --all
  ```

* 위 명령어를 이용해서 지금까지 brach가 무엇을 가리키고 어떻게 갈라져 왔는지 파악할 수 있다. 



> 출처 [https://git-scm.com/book/ko/v2/Git-%EB%B8%8C%EB%9E%9C%EC%B9%98-%EB%B8%8C%EB%9E%9C%EC%B9%98%EB%9E%80-%EB%AC%B4%EC%97%87%EC%9D%B8%EA%B0%80](https://git-scm.com/book/ko/v2/Git-브랜치-브랜치란-무엇인가)

