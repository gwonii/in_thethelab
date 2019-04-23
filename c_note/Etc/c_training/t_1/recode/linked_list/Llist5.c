// linked_list 구현하기 


#include <stdio.h>
#include <stdlib.h>

// 무한 루프의 문제를 해결하기 위해 환형 연결리스트를 사용한다. 


struct node {

		int data;
		struct node *prev;
		struct node *next;
		//prev, next를 만들어서 앞뒤의 구분을 할 수 있도록 만든다. 

};
// node struct 안에는 노드 하나가 가지는 int data와 다음 노드의 주소 값을 담고 있다. 

//struct node tail = {0,&tail };

// 이전 환형 연결리스트도 계속 head를 만나는 문제가 있었음.... 


struct node head = {0,&head };


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

