// linked_list 구현하기 


#include <stdio.h>
#include <stdlib.h>


struct node {

		int data;
		struct node *next;

};
// node struct 안에는 노드 하나가 가지는 int data와 다음 노드의 주소 값을 담고 있다. 


struct node *head = NULL;	
// 일단 node * 로 head node를 하나 만들어 준다. 

// 이제 head를 만들었으니 새로운 리스트를 하나씩 만들어 가면서 서로 연결을 시켜줘야 한다. 

void add_front (int data) {

		struct node *temp = malloc(sizeof(struct node));
		// temp라는 임시 구조체를 만들어 새로 들어올 노드들을 일시 저장시켜 놓는다. 

		temp->data = data;
		temp->next = NULL;

		if (head == NULL) {

				head = temp;
				// head는 아까 처음으로 NULL값으로 초기화 해놓은 node
				// temp는 일시적으로 데이터를 넣어 놓을 임시 노드 

		}
		else {

				temp->next = head;
				// 두번 째 루핑을 할 때 head는 temp로 NULL이 아니므로 
				// temp->next = head; 문을 실행한다. 
				// 그러면 새로운 temp는 다시 head의 주소 값을 가리킨다. 
				// 결과적으로 새로 할당되는 temp들은 계속해서 head의 주소 값만 가리키게 된다. 
				// 우리가 의도하는 것은 리스트끼리 연결이 되야 한다. 
				// 하지만 우리가 간과한 것이 있다. .
				// 그것은 바로 
				head = temp;
				
		}

}	

void print_list() {

		struct node *current = head;
		// 프린트를 위해서 currnet라는 새로운 struct node *로 새롭게 선언했다.

		system("clear");


		printf("<head>");
		while(current) {

				printf(" -> [%d]", current->data );
				current = current -> next;
		}

		getchar();
}

int main() {

		int i;
		for ( i = 0; i<10; ++i ){

				add_front(i+1);
				print_list();
		}

		return 0;
}

