#include <stdio.h>
void array_print(int(*ptr)[4], int a);//�Լ��� ������ �迭�� �Ѱܹ����� ���ڸ� �ָ�
void main() // �迭 �������� ���
{
	int arr1[2][4] = { 1,2,3,4,5,6,7,8 };
	int arr2[3][4] = { {1},{2},{3} };

	array_print(arr1, 2);
	array_print(arr2, 3);
}
void array_print(int(*ptr)[4], int a) {
	int i, j;

	printf("�迭���� ���� �������\n");

	for (i = 0; i < a; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d  ", ptr[i][j]); //�������迭�� �� ����ϴ°��� Ȯ��
		printf("\n");
	}
	
}