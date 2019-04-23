// linked_list 구현하기 


#include <stdio.h>
#include <stdlib.h>

// 이전 Llist.c 의 메인 이슈 !!
// head가 포인터 이기 때문에 특정한 노드 뒤에 삽입하는 로직과 다르다. 
// 계속 노드가 temp로 위치를 이동하므로 문제가 있음!! 
// 해결방법: head를 포인터 처리하지 말고, node로 처리하자




struct node {

		int data;
		struct node *next;

};
// node struct 안에는 노드 하나가 가지는 int data와 다음 노드의 주소 값을 담고 있다. 


struct node head;	

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

