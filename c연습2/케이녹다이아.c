#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int size; //(���̾Ƹ���� ũ�⸦ ������ ���� ����)
	printf("size�� �Է��ϼ���\n");
	scanf("%d", &size);
	int column = size;//�� ���� ����
	int row = column; // �� ���� ���� (�Ѵ� size ����ŭ �ʱ�ȭ)
	//4���ҷ� ������ ������..
	//���� �ﰢ��
	for (int i = 1; i <= column; i++)
	{
		//1�� �κ�
		for (int j = row - i; j > 0; j--)
		{
			printf("0");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		if (size % 2 == 0)	//���� �κ��� ������,size�� ¦���� �̸� �� �ϳ��� ����ϰ� �����Ѵ�. 
			printf("*");

		//2�� �κ�
		for (int k = 0; k < i - 1; k++)
		{
			printf("*");
		}
		for (int j = (row - i); j > 0; j--)
		{
			printf("0");
		}

		printf("\n"); //���� �� ����� ���� �� �ٲ��ش�.
	}

	//�Ʒ��� �ﰢ��
	for (int i = 1; i <= column - 1; i++)
	{
		//3�� �κ�
			for (int j = 0; j < i; j++)
			{
				printf("0");
			}
			for (int k = (row - i); k > 1; k--)
			{
				printf("*");
			}
			if (size % 2 == 0) //���� �κ��� ������,size�� ¦���� �̸� �� �ϳ��� ����ϰ� ������ �κ��������Ѵ�. 
				printf("*"); //Ȧ�� ¦�� �Ѵ� �־ �ߵ��ư��� ���� �غ���;����� ���Ф�
			//4�� �κ�
			for (int k = i; k < row; k++)
			{
				printf("*");
			}
			for (int j = 0; j < i; j++)
			{
				printf("0");
			}

			printf("\n"); //���� �� ����� ���� �� �ٲ��ش�.
		}

		return 0;
		//�� ��û�� �γ��� Ȯ����  �� �־��� ���α׷��̾���
	}
