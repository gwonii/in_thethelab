

## gcc option

* -o : gcc에서 만들 실행 파일명을 정하는 것. 지정하지 않으면 a.out
	ex) $ gcc -o fliter filter_driver.c 

* -c : 컴파일을 하지만, 링크는 하지않도록 하는 명령어 
	ex) $ gcc -c main.c

* -D : 소스코드의 #define 문과 같다. 심볼에 대한 값을 지정 
	ex) $ -c DDOC="info" -DUSE_POLL main.c
> 첫번째 -D 옵션은 DOC_FILE을 info라는 문자열로 대치한다는 것 
> 두번째 -D 옵션은 USE_POLL	심볼을 정의한다. 

* -U : 외부에서 #undef 한다는 것 
	ex) -UDEBUG

* -L : 라이브러리 폴더를 찾아서 지정
	ex) $ gcc -c -L../foldername1

* -l : 라이브러리를 지정. 파일명과 함께 붙여 쓴다. 
	ex) $ gcc -o main.c -ladd -L.

* -E : 전처리, 프로그램을 컴파일 하는 대신 전처리된 코드를 표준출력으로 내보냄

* -S : 컴파일, 어셈블리 언어로 나온 결과를 저장 .c 대신 .s가 붙는 파일을 만든다. 

* -c : 어셈블, .o로 끝나는 오브젝트 파일을 만든다. 













