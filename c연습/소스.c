#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int i;
	int M[5];
	int N[3];
	int *p = M;
	int *q = N;
	printf("1. 5���� ���� �Է�: \n");
	for (i = 0; i<5; i++)
	{
		printf("%d ��° ���� : ", i + 1);
		scanf("%d", p);
		p++;
	}

	printf("\n");
	
	p = M;
	printf("2. �Էµ� ���� ������ �迭1�� �� ���\n");
	for (i = 0; i<5; i++)
	{
		printf("%d��° �� :%d\n", i + 1, *p);
		p++;
	}
	return 0;
}