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
		// ���� ���� 
		// 10���� ���� ��� Ȯ���ϰ� ���� ���� ���� ���ʺ��� �����ϱ� 
	}
	for (i = 0; i < 10; i++) {
		printf("%d", array[i]);
	}

	return 0;
}