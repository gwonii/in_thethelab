#include <stdio.h>


int main() {

	int i, j, temp;
	int array[11] = { 5,4,3,2,1,10,9,8,7,6,11};

	for (i = 0; i < 11; i++) {

		for (j = 0; j < 9 - i; j++) {
			if (array[j] > array[j + 1]) {
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}

	for (i = 0; i < 11; i++) {
		printf("%d", array[i]);
	}
	return 0;
}