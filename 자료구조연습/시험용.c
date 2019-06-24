#include<stdio.h>
void main() {
	int arr[10] = {1,2,3,4,5,6,7,8,9 };
	int *v = arr;
	arr= arr + 1;
	printf("%d\n", *v);
}