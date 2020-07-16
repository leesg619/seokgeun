#include <stdio.h>
void array_print(int(*ptr)[4], int a);//함수가 이차원 배열을 넘겨받을때 인자를 주목
void main() // 배열 포인터의 사용
{
	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
	int arr2[3][4] = { {1},{2},{3} };

	array_print(arr1, 2);
	array_print(arr2, 3);
}
void array_print(int(*ptr)[4], int a) {
	int i, j;

	printf("배열안의 값을 출력하자\n");

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d  ", ptr[i][j]); //이차원배열을 잘 사용하는것을 확인
		printf("\n");
	}
	
}