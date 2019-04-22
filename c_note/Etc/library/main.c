// headfile 만드는 법...


//헤더파일을 만들 때 주의할 점 
//--> 중복 포함을 방지해야 한다. 

#include <stdio.h>

//#include "add.h"

int main () {

	int n = add(10,20);
	printf("%d \n",n);

	return 0;


}
