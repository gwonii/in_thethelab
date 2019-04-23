// main.c 


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {

		struct node *prev;
		struct node *next;

};

#define list_entry(ptr,type,member)\
		(type*)((char*)ptr - (unsigned long)&(((type*)0)->member))



enum {

		celldx=1,				//각각 0부터 5까지 정수 대입됨 
		sports,
		sub,
		wagon,
		minivan,
		pickup,
		awd,
		rwd,
};


struct Car {

		char *name;     //포인터로 만들었다는 것은 동적할당으로 해서 사용하겠다는 의미
		unsigned char type;
		int retail_price;
		int dealer_cost;
		double engine_size;
		int weight;
		int width;

		struct node links;			// 연결리스트를 위해서 
};

struct node head = {&head,&head};



// 함수 선언 시작




// 데이터 읽어오는 부분

struct Car* alloc(char *buf);

void print_car (struct node *head);




//링크드 리스트 만들어주는 부분

void add_node(struct node *prev, struct node *next, struct node *new);

void add_next(struct node *s, struct node *new);

void add_front(struct node *s, struct node *new);  // 우리는 add_front를 사용할 것임



//필터 분류 해주는 부분

void filter_sort(struct node *head, struct Car **car_struct); 

// 전체 print 부분

void print_all(struct Car **car_struct);

//compare 부분

int compare_retail_p (const void *a,const void *b);

int compare_dealer_c (const void *a,const void *b);

int compare_engine_s (const void *a,const void *b);

int compare_weight (const void *a,const void *b);

int compare_width (const void *a,const void *b);

// save 부분

void save_data (struct Car **car_struct);


// 전역 변수 선언
int sel_type;
int sel_value;
int sel_sort;
int file_save;
char file_name[40];
int sel_num;
//





int main() {

		struct Car *car_struct[400];
		struct Car *car;

		FILE *fp;
		char buf[1000];
		int i=0;
		char str[100];
		int sel;

		fp = fopen("car_data.csv", "r");

		if(fp == NULL) {

				printf("파일 오픈 오류");

		}

		

		while(fgets(buf, sizeof(buf), fp) != NULL){

				if(i==0) {

						i++;
						continue ;
						
				}

				else {

				
					car = alloc(buf);

					add_front(&head, &car->links);

						i++;		

				}				

		}

		fclose(fp);

		printf("총 %d개의 데이터가 로드되었습니다. \n",i-1);

		while (1) {

				printf("1. 검색\n");
				printf("2. 종료\n");
				printf("선택>");


				scanf("%d", &sel); // 검색, 종류 선택하기 

				if (sel == 1) {

						printf("1. CellDx\n");
						printf("2. Sports Car\n");
						printf("3. SUB\n");
						printf("4. Wagon\n");
						printf("5. Minivan\n");
						printf("6. Pickup\n");
						printf("선택>");
						scanf("%d",&sel_type);		// 타입 선택하기

				}


				else return 0;

				printf("1. Retail Price\n");
				printf("2. Dealer Cost\n");
				printf("3. Engine Size\n");
				printf("4. Weight\n");
				printf("5. Width\n");
				printf("선택>");
				scanf("%d", &sel_value);			// 값들 선택하기

				printf("1. 오름차순 정렬\n");
				printf("2. 내림차순 정렬\n");
				printf("선택>");
				scanf("%d",&sel_sort);				// 오름차순/내림차순 선택하기 


				filter_sort(&head, car_struct);



				printf("파일을 저장하시겠습니까?\n");
				printf("1. 예\n");
				printf("2. 아니오\n");
				scanf("%d",&file_save);
				

				if(file_save == 1) {
						
						printf("파일 이름");
						scanf("%s", file_name);

						save_data(car_struct);
				}
		
				
		
		}
		
		return 0;
}

struct Car* alloc(char *buf){

		char *p;
		int i;
		int len;
        struct Car *car;

	   	len = strlen(buf); 	

	    car = (struct Car*)malloc(sizeof(struct Car));

		


			
			for (i=0,p = strtok(buf,","); p !=NULL  ; p = strtok(NULL, ","), i++) {




			switch (i) {

					case 0 : car->name = strdup(p);
							 break;

					case 1 : case 2 : case 3 : case 4 : case 5 : case 6 : case 7 : 
					case 8 : if ( atoi(p) ==  1) {
									 car->type |=  1 << (8-i);
							 } 
							 break;
							
					case 9 : car->retail_price = atoi(p);
							 break;
					case 10 : car->dealer_cost = atoi(p);
					 		 break;
					case 11 : car->engine_size = atof(p);
							 break;
					case 12 : car->weight = atoi(p);
							 break;
					case 13 : car->width = atoi(p);
							 break;

			}

		




			}	
			return car;
}	


void add_node (struct node *prev, struct node *next, struct node *new){

		new -> next = next;
		new -> prev = prev;
		prev -> next = new;
		next -> prev = new;
}

void add_next(struct node *s, struct node *new){

		add_node(s,s->next, new);

}

void add_front (struct node *s, struct node *new){

		add_node(s->prev,s,new);

}


void filter_sort(struct node *head,struct Car **car_struct ) {

		sel_num=0;
		int j;
		int n=0;

		struct node *current = head->next;

		while (current != head) {

				struct Car *car = list_entry(current, struct Car, links);


				if (  (car->type) & (1 << (8-(sel_type))) ) {

						car_struct[sel_num++] = car;//0


				}

				

				current = current->next;
		}


		if (sel_value == 1 ) {

			qsort(car_struct,sel_num,sizeof(struct Car *),compare_retail_p);

		}
	
		else if (sel_value == 2 ) {

			qsort(car_struct,sel_num,sizeof(struct Car *),compare_dealer_c);

		}	
	
		else if (sel_value == 3 ) {

			qsort(car_struct,sel_num,sizeof(struct Car *),compare_engine_s);

		}	

		else if (sel_value == 4 ) {

			qsort(car_struct,sel_num,sizeof(struct Car *),compare_weight);

		}

		else  {

			qsort(car_struct,sel_num,sizeof(struct Car *),compare_width);

		}

		print_all(car_struct);

}



int compare_retail_p (const void *a,const void *b){

		


		
		struct Car *car1 = *(struct Car **)a;

		struct Car *car2 = *(struct Car **)b;

		
		
		if (sel_sort == 1) {

				return (car1->retail_price) - (car2->retail_price);
		}
		else {

				return (car2->retail_price) - (car1->retail_price);
		}
}


int compare_dealer_c (const void *a,const void *b){

		


		
		struct Car *car1 = *(struct Car **)a;

		struct Car *car2 = *(struct Car **)b;

		if (sel_sort == 2) {

				return (car1->dealer_cost) - (car2->dealer_cost);
		}
		else {

				return (car2->dealer_cost) - (car1->dealer_cost);
		}
	
		
		 

}

int compare_engine_s (const void *a,const void *b){

		


		
		struct Car *car1 = *(struct Car **)a;

		struct Car *car2 = *(struct Car **)b;

		if (sel_sort == 3) {

				if(car2->engine_size < car1->engine_size){
				
						return -1;

				}
				else 
						return 1;
		}
		else {

				if(car2->engine_size < car1->engine_size){
				
						return -1;
				}
				else 
						return 1;
		}
	
}

int compare_weight (const void *a,const void *b){

		


		
		struct Car *car1 = *(struct Car **)a;

		struct Car *car2 = *(struct Car **)b;

		if (sel_sort == 4) {

				return (car1->weight) - (car2->weight);
		}
		else {

				return (car2->weight) - (car1->weight);
		}


}

int compare_width (const void *a,const void *b){

		


		
		struct Car *car1 = *(struct Car **)a;

		struct Car *car2 = *(struct Car **)b;
		
		
		if (sel_sort == 5) {

				return (car1->width) - (car2->width);
		}
		else {

				return (car2->width) - (car1->width);
		}

		
}

void print_all (struct Car **car_struct){

		int j=0;

		for (j=0; j<sel_num; j++) {


				printf("%-46s", car_struct[j]->name );
				if (car_struct[j]->type & 1 << 7 )			printf("CellDx    ");
				else if (car_struct[j]->type & 1 << 6)		printf("Sports Car");
				else if (car_struct[j]->type & 1 << 5) 		printf("SUV       ");
				else if (car_struct[j]->type & 1 << 4) 		printf("Wagon     ");
				else if (car_struct[j]->type & 1 << 3) 		printf("Minivan   ");
				else if (car_struct[j]->type & 1 << 2) 		printf("Pickup    ");

				if (car_struct[j]->type & 1 << 1) 			printf("AWD  ");
				else if (car_struct[j]->type & 1 << 0) 		printf("RWD  ");
				else 									 		printf("NONE ");

				printf("%8d", car_struct[j]->retail_price);
				printf("%8d", car_struct[j]->dealer_cost);
				printf("%5.1f", car_struct[j]->engine_size);
				printf("%8d", car_struct[j]->weight);
				printf("%8d", car_struct[j]->width);
				printf("\n");


		}
}

void save_data (struct Car **car_struct){

		int j=0;

		FILE *fpp = fopen(file_name,"w");

		

		for (j=0; j<sel_num; j++) {


				fprintf(fpp,"%-46s", car_struct[j]->name);
				
				
				if (car_struct[j]->type & 1 << 7 )			fputs("CellDx    ",fpp);
				else if (car_struct[j]->type & 1 << 6)		fputs("Sports Car",fpp);
				else if (car_struct[j]->type & 1 << 5) 		fputs("SUV       ",fpp);
				else if (car_struct[j]->type & 1 << 4) 		fputs("Wagon     ",fpp);
				else if (car_struct[j]->type & 1 << 3) 		fputs("Minivan   ",fpp);
				else if (car_struct[j]->type & 1 << 2) 		fputs("Pickup    ",fpp);

				if (car_struct[j]->type & 1 << 1) 			fputs("AWD  ",fpp);
				else if (car_struct[j]->type & 1 << 0) 		fputs("RWD  ",fpp);
				else 									 	fputs("NONE ",fpp);

			
				fprintf(fpp,"%8d", car_struct[j]->retail_price);
				fprintf(fpp,"%8d", car_struct[j]->dealer_cost);
				fprintf(fpp,"%5.1f", car_struct[j]->engine_size);
				fprintf(fpp,"%8d", car_struct[j]->weight);
				fprintf(fpp,"%8d", car_struct[j]->width);
				fprintf(fpp,"\n");


		}

		fclose(fpp);
}


