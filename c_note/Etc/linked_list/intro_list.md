// instruction linked list


* 배열 

	-연속적인 메모리 

**장점**: 임의접근이 용이하다. 
**단점**: 중간 삽입과 삭제시 처리가 힘들다. 

* 연결리스트 

	-연속적인 메모리가 아닌 논리적으로 연속적인 형태

**장점**: 삽입, 삭제시 시간이 동일하다. 
**단점**: 임의 접근이 불가능하다. 

* 단일연결 리스트 

> 예제 list1.c

* 단일연결 리스트 코드 과정

1. 빈 노드를 하나 선언한다. 이 노드에는 int data, struct node *next (연결 될 다음 주소 값이 저장되어 있다.)

2. 새로운 노드를 하나 씩 만들어준다. 먼저 temp라는 노드를 사용할 것이다.( 이 노드는 새로 들어온 data값을 잠시 저장시켜 놓는 역할을 한다. )

3. temp->data = data;를 통해 현재 할당해 놓은 빈 temp 노드에 매개변수로 받은 data값을 저장시킨다. 

4. temp->next = NULL;를 통해 next를 비워둔다. 

5. head에 현재 데이터 값이 있는지 없는지 확인한다. if ~ else 구문으로 

6. 만약 head가 비어있다면 head에다가 temp를 대입시킨다. 

7. 현재 사용되고 있는 head가 존재하지 않기 때문에 data 1값을 가진 temp는 head에 대입된다. 
8. printf()에서 struct node *current = head;로 초기화 선언을 한다. 

9. while(current)를 이용해서 current->data 값을 출력시킨다. 

10. 그리고 current = current->next; 를 이용하여 한번 current를 출력했다면 current를 null값으로 만들어 루프문을 빠져나오게 한다. 

11. 다시 add_front로 돌아와서 node *temp 새로운 메모리를 할당해준다. 

12. temp->data = data;를 이용하여 새로 매개변수로 들어온 2값을 temp->data에 대입시킨다. 

13. 그리고 temp->next = NULL;로 temp의 next를 NULL값으로 초기화시킨다. 

14. 다시 if ~ else 구문을 통해 head가 비어있는지 확인한다. 

15. 이전에 head가 사용되었으므로 head는 비어있지 않다 그러므로 else

16. else에서 temp->next = head; 새로운 temp의 next 주소를 head로 대입시킨다. 

17. head에 temp를 대입시켜 데이터가 값 2를 가진 temp가 head가 되도록 만든다. 

18. 그런다음 다시 print()로 돌아가서 node *current에 현재 head를 대입시킨다. 

19. 그러면 현재 head에는 데이터 값 2가 들어있고 print()에서는 current->data값인 2값을 출력시킨다. 

20. 그리고 다시 current = current->next를 이용해서 current를 NULL값으로 만들어준다. 

21. 이렇게 계속 temp와 head를 이용해서 linked list를 만들어낸다. 




