// list2.c
#include <stdio.h>
#include <stdlib.h>



void print ();
void insert_data(int data);

struct node {

		int data;
		struct node *next;

};

struct node *head = NULL;

// 현재 코드의 문제점! 
// head가 포인터이기 때문에, 특정한 노드의 뒤에 삽입하는 로직과 다르다. 
// 해결법: head를 포인터로 처리하지 말고, node로 처리하자. 

int main(void) {

		int i;
		for (i=0;i<10;i++){

				insert_data(i+1);
				print();
		}

		return 0;
}


void insert_data(int data) {

		struct node *temp = malloc(sizeof(struct node));

		temp->data = data;
		temp->next = head;
		head = temp;
		
		//차이 발생 
		//원래 temp->next = NULL;에서 temp->next = head; 바꿔주었다. 
		//그리고 head = temp; 추가 

		
}
// 추가적으로 특정 노드 뒤에 새로운 노드를  삽입하는 코드 
#if 0
void insert_data2(struct node *s, int data){

		struct node *temp = malloc(sizeof(struct node));
		temp->data = data;

		temp->next = s->next;
		s->next = temp;
}

#endif

void print () {

		struct node *current = head;
		system("clear");

		printf("<head>");
		while(current) {

				printf("-> [%d]", current->data);
				current = current->next;

		}

		getchar();
}
