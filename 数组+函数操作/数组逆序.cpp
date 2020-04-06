#include <stdio.h>

int main(void) {

	int a[6] = { 1,2,3,4,5,6 };
	int len = 6;
	int i;
	int temp;
	for (i = 0; i < len / 2; i++) {
		temp = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = temp;
	}
	
	for (i = 0; i < len;i++) {
		printf("%d ",a[i]);
	}

	return 0;
}
