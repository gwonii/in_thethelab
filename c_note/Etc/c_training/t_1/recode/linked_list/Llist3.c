// linked_list 구현하기 


#include <stdio.h>
#include <stdlib.h>

// head를 함수에서 바로 접근해서 처리하도록 만들면, 
// -> 프로그램 안에서 오직 한 개의 리스트만 만들 수 있다.

// 연결리스트의 끝을 NULL로 표현한다. .
// 문제점 : NullPointer 참조로 인해 프로그램이 비정상적으로 종료할 수 있다. 

struct node {

		int data;
		struct node *next;

};
// node struct 안에는 노드 하나가 가지는 int data와 다음 노드의 주소 값을 담고 있다. 

struct node tail = {0,&tail };
struct node head = {0,&tail };

// 이렇게 되면 계속 헤드와 꼬리가 서로 무는 리스트가 생겨 무한 루프에 빠진다. 


void insert_data(struct node *s, int data) {

		struct node *temp = malloc(sizeof(struct node));

		temp->data = data;
		// 새로 할당된 struct node 공간에 data 값을 넣어준다. 
		
		temp->next = s->next;
		// 새로 만들어진 temp의 next에 매개변수로 받은 head의 next를 대입시킨다 . 
		s->next = temp;
}

void print_list(struct node *head) {

		struct node *current = head->next;
		// head에는 data값이 없다. 그래서 head의 다음 next부터 data값을 출력한다. .
				
		system("clear");
		printf("<head>");

		while (current) {

				printf(" -> [%d]", current->data);
				current = current->next;
		}
		getchar();

}



int main() {

		int i;
		for (i=0; i <10; ++i) {

				insert_data(&head,i);
				// 새로운 리스트를 만들면서 리스트에 데이터를 저장시켜놓고 

				print_list(&head);
				// 만들어진 리스트를 돌면서 리스트에 들어있는 내용들을 프린트 한다. 

		}
}

