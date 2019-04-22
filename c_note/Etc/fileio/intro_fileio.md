// intro_fileio.md


* os linux

	모든 것은 파일이다. 

* 운영체제의 역할

	자원을 관리한다. 

1. 물리적 자원
		cpu, ram, hdd, ssd, network, device

2. 추상적인 자원
		process, thread, page, file

* #incldue <stdio.h>의 기본 요소

1. stdin -> keyboard(0)
2. stdout -> monitor(1)
3. stderr -> monitor(2)

* 버퍼링을 하는 이유
		uesr mode와 kernel mode의 문맥 교환을 자주 일어나지 않도록 하기 위해서

* 버퍼링 정책

1. 풀 버퍼링 - 버퍼가 가득차면, 비운다. -> 일반 파일
2. 라인 버퍼링 - 엔터가 나오거나, 버퍼가 가득차면 비운다. -> stdout, stdin
3. 노 버퍼링 - 버퍼링을 하지 않는다. -> stderr

* 버퍼를 비우는 표준 라이브러리 함수

fflush, fclose : 프로세스가 종료하면, 프로세스가 연 파일을 스스로 정리한다. 

* 입출력을 할 때는 항상 EOF 통해서 입출력 처리를 해야 한다. 


