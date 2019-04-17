# Git



### 1. 리모트 저장소에서 제거한 폴더를 git에서도 제거하기 

---

1) git bash에서 레포지토리 속에 있는 폴더를  

```
$git rm -r "해당 폴더명"
```

위 명령을 통해 제거한다. 

2) 그리고 이제 제거된 결과를 git remote 저장소에 알려준다. 

```
$git pull
$git add .
$git commit -m "clean push"
$git push
```

그러면 내 저장소에 제거된 것들이 레포지토리에서도 깔끔하게 지워진다. 



---

자주 사용하는 것들 

$git remote remove origin

$git remote remove "name"

$git remote add origin "url주소"



$git clone "url주소"



$git add *

$git add "파일명"

$git commit origin -m "20xx/xx/xx"

$git push origin master



$git status

$git branch



$git rm -r "폴더명"

