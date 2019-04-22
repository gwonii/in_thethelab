
// car 과제 복습하기 


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 구조체 설정 

typedef struct Car {

		char *name;					// 자동차의 이름을 char * 이용해 담는다. 
									// 포인터를 이용했으므로 동적할당을 사용한다는 것 
		int type[8];
		int retail_price;
		int dealer_cost;
		double engine_size;
		int weight;
		int width;


}Car;

#define MAX_TYPE_COUNT = 8;
#define unsigned char [MAX_TYPE_COUNT / sizeof(unsigned char)*8];

를 이용해서 비트연산자를 활용할 것이다. 




Car *carAlloc (char *buf);



int main () {

		
	int i=0; 

	Car *car; 					// 구조체 포인터를 이용해서 접근할 수 있도록 선언한다. 

	

	char buf[1000]; 			// 한 줄을 담을 캐릭터 배열 
	
	

	FILE *fp = fopen("./car_data.csv", "r");	// 파일 오픈하고 

	if (fp == NULL) {

			printf("파일을 읽는데 문제가 발생했습니다");
			return 1;
	}



	// 파일 읽는 부분
	while(fgets(buf,sizeof(buf),fp) != NULL ) {

			if( i == 0 ) {

					i++;
					continue ;
			}

			else {

					  car = carAlloc(buf); 		// 한 줄 전체 읽은 다음에 ',' 기준으로 쪼개고 
											// 저장시킬 것이다. 

					printf("%s ", car->name);


					printf("%d ", car->type[2]);
					printf("%d ", car->type[3]);
					printf("%d \n", car->dealer_cost);
			}

	}	
	



	


	return 0;

}


// ,를 기준으로 글들을 잘라서 구조체에 저장시는 함수 

Car *carAlloc (char *buf) {
// 여기서 만약에 리턴 타입으로 구조체를 보내지 않았다면 main 함수에서 제대로 된 정보를 받을 수 없다. 

		//strtok 이용해서 ',' 기준으로 잘라준다. 
		// 그러면 내가 필요한 변수는 뭐가 있을까? 

	

		char *p;
		int i;
		Car *car;

		//struct Car *car;

		car  = malloc(sizeof(Car));

		

		p = buf;

		//p = strtok(buf,",");			// 이 구문을 통해 첫번째 ','를 찾아 끊기는 문자열의 끝을 찾고 콤마에서 끝나는 buf 시작 지점의 주소 값을 p에 반환한다 . 그리고 콤마를 NULL로 바꾸고 끝난다. 그리고 나서 뒤에 strtok(NULL,",")을 통해서 NULL부터 시작하는 주소값을 시작으로 다시 ,를 찾기 시작한다. 그리고 찾으면 거기까지 문자열의 첫 주소 값을 다시 반환하여 문자를 만들고 다시 콤마를 NULL값으로 바꾼다. 

// 결국 strtok(buf, ","); 는 한 번만 시행되어야 한다. 

		// p = strtok(buf,","); 는 결국 한 번만 실행하면 되니까 

		for (i=0, p = strtok(buf,","); p != NULL; p = strtok(NULL,","), i++) {

				
				

				switch (i) {

						case 0 : car->name = (p);
								 break;

						case 1 : case 2: case 3: case 4:
						case 5 : case 6: case 7: case 8:
								 car->type[i] = atoi(p);
								 break;

						case 9 : car->retail_price = atoi(p);
								 break;

						case 10: car->dealer_cost = atoi(p);
								 break;

						case 11: car->engine_size = atof(p);
								 break;

						case 12: car->weight = atoi(p);
								 break;

						case 13: car->width = atoi(p);
								 break;
				}
				//p = strtok(NULL,","); 그리고 이건 루핑이 끝날 때 마다 한 번씩 실행이 되야 하므로 i++ 옆에 넣어줄 수 있다. 
		}
		return car;
}	





		


