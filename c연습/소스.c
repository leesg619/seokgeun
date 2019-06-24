#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i;
	int M[5];
	int N[3];
	int *p = M;
	int *q = N;
	printf("1. 5개의 정수 입력: \n");
	for (i = 0; i<5; i++)
	{
		printf("%d 번째 숫자 : ", i + 1);
		scanf("%d", p);
		p++;
	}

	printf("\n");
	
	p = M;
	printf("2. 입력된 값을 저장한 배열1의 값 출력\n");
	for (i = 0; i<5; i++)
	{
		printf("%d번째 값 :%d\n", i + 1, *p);
		p++;
	}
	return 0;
}