// list1.c
#include <stdio.h>
#include <stdlib.h>



void print ();
void add_front(int data);

struct node {

		int data;
		struct node *next;

};

struct node *head = NULL;

int main(void) {

		int i;
		for (i=0;i<10;i++){

				add_front(i+1);
				print();
		}

		return 0;
}


void add_front(int data) {

		struct node *temp = malloc(sizeof(struct node));

		temp->data = data;
		temp->next = NULL;
		if (head == NULL ) {

				head =temp;
		}

		else{

				temp->next = head;
				head = temp;
		}
}

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
