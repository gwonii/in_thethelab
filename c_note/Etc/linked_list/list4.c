// list4.c


#include <stdio.h>
#include <stdlib.h>


struct node {

		int data;
		struct node *next;
};

struct node tail = {0, &tail};
struct node head = {0, &head};

//head를 함수에서 바로 접근해서 처리하도록 하면, 
//=> 프로그램 안에서 오직 한 개의 리스트만 만들 수 있다. 

//하지만 여러 개의 리스트를 만들고 싶다. 

//연결리스트의 끝을 NULL로 표현한다. 
//문제점 : NULLpointer 참조로 인해 프로그램이 비정상적으로 종료될 수 있다. 

void insert_data(struct node *s, int data){

		struct node *temp = malloc(sizeof(struct node));
		temp->data = data;

		temp->next = s->next;
		s->next = temp;
}

void print_list(struct node *head){

		struct node *current = head->next;
		system("clear");

		printf("<head>");

		//변화한 구간 
		while (current != &tail) {

				printf(" -> [%d]", current->data);
				current = current->next;

		}

		getchar();

}

int main() {


		int i;
		for (i=0; i<10; i++) {

				insert_data(&head,i+1);
				print_list(&head);

		}

		return 0;
}
