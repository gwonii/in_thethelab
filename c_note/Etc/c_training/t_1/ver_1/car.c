

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_HCAT 14
#define MAX_HLINE 1000
#define MAX_VLINE 398
#define ONE_WORD 100

/*
struct *file {

		char vehicle_name[ONE_WORD];
		char celldx;
		char sportcar;
		char suv;
		char wagon;
		char minivan;
		char pickup;
		char awd;
		char rwd;
		int retail_price;
		int dealer_cost;
		float engine_size;
		int weight;
		int width;

};
*/


/*

struct Car {

		char car_name[];
		int car_attr[];		// car의 속성 값들을 가지고 있는 int형 배열


		//리스트와 내용 연결
		struct node links;
}; // car 구조체






struct node {

		struct node *prev;
		struct node *next;

}; //연결리스트

#define list_entry(ptr,type,member)\
		(type*)((char*)ptr-(size_t)&(((type*)0)-member))


// 전역 변수 선언

struct node head = {&head,&head };
struct Car car[400];

*/




//함수 선언
void csv_read ();



int main (void) {

		//첫번째로 csv에 있는 파일을 삽입해야 한다. 

		csv_read();
		

		return 0;

}

//csv 파일 읽어오기 

void csv_read () {

		FILE *fp = fopen("./car_data.csv","r");
		
		
		int i,j;
		char buf[1000];
 		
		char *file[398][14];
		//char *sefile[MAX_VLINE][MAX_HCAT];	
		
		
		
		while(fp != NULL){
				
			for(i=0; i<398; i++){
			
				
				//p = (char *)malloc(sizeof(char)*1000);	
				tok = (char *)malloc(sizeof(char)*1000);	
				file[i][14] =(char*)malloc(sizeof(char)*1000);
				fgets(buf,sizeof(char)*1000,fp);

				

				while (tok != NULL){	

						for(j=0; j<14; j++){

								strcpy(file[i][j],tok);

								tok = strtok(NULL,",");
						}
							
				}

			} 

		}
				//tok = strtok(file," ,");
			
				/*
				for(i=0; i<14; i++){

						tok[i]= strtok(file,",");

				}

				printf("%d", *tok[3]);

				*/
	
}


#if 0

// 연결리스트 관련 코드

void add_node(struct node *prev, struct node *next, struct node *new){

		new->next = next;
		new->prev = prev;
		prev->next = new;
		next->prev = new;

}

void add_next(struct node *s, struct node *new){

		add_node(s,s->next,new);

}

void add_front(struct node *s, struct node *new){

		add_node(s->prev, s, new);

}

// 여기 까지

#endif









