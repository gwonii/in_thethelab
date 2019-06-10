#include <stdio.h>

int main2() {

	const int MAX_SIZE = 9999;

	int i, j, min, temp, index;

	int array[10] = { 1,4,5,6,2,3,7,8,9,10 };

	
	for (i = 0; i < 10; i++) {
		min = MAX_SIZE;

		for (j = i; j < 10; j++) {

			if (min > array[j]) {
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
		// 선택 정렬 
		// 10개의 값을 모두 확인하고 가장 작은 값을 왼쪽부터 정렬하기 
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
	}

	return 0;
}