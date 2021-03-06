// list3.c

#include <stdio.h>
#include <stdlib.h>




struct node {

		int data;
		struct node *next;

};

struct node head;

// 현재 코드의 문제점! 
// head가 포인터이기 때문에, 특정한 노드의 뒤에 삽입하는 로직과 다르다. 
// 해결법: head를 포인터로 처리하지 말고, node로 처리하자. 

void print_list(struct node *head);
void insert_data(struct node *s, int data );
int main() {

		int i;
		for (i=0; i<10; i++){

				insert_data(&head, i+1);
				print_list(&head);
		}

		return 0;
}


// 특정 노드에 새로운 노드를 삽입하는 코드

void insert_data(struct node *s, int data){

		struct node *temp = malloc(sizeof(struct node));
		temp->data = data;

		temp->next = s->next;
		s->next = temp;
}

void print_list(struct node *head) {

		struct node *current = head->next;
		// list2 와 다른 부분

		system("clear");
		printf("<head1>");

		while(current) {

				printf("-> [%d]", current->data);
				current = current->next;

		}

		getchar();
}
