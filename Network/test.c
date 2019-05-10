

#include <stdio.h>
#include <stdint.h>



int main() {

  char mychar;
	char *pchar;

	int myint;
	int *pint;

	pchar = &mychar;
	pint = &myint;

	printf("%ld, %ld \n", (intptr_t)pchar, (intptr_t)pint);

	pchar ++;
	pint ++;


	printf("%ld, %ld \n", (intptr_t)pchar, (intptr_t)pint);
	//printf("%p, %p \n", pchar, pint);

}
