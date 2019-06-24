#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

double sum_array(double *p, int size);
	int main(void)
	{
		char str[40];
		int count;
		count = 0;
		printf("문자열 입력 : ");
		scanf("%s", str);
		while (str[count] != '\0')
		{
			count++;
		}
		printf("%d", count-1);
		return 0;
	}
