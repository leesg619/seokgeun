#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//C ����� ǥ�� ���̺귯�� �Լ��� ��ũ�� ����, ���, ���� ���� ����� �Լ��� ���Ե� ��� �����̴�
#include<stdlib.h>
void main() {
	int n, temp;//�迭 ũ�⸦ �޴� ���� n����,�� ��ȯ�� �ӽ������Ҷ��ʿ��� temp����
	int **str; //���� �迭�� ���� �޸� �Ҵ��� ���� �����͸� ����Ű�� ���� ������ ��������
	
	int num[100];
	printf("�迭 ũ�� n�� �Է��Ͻÿ� ");
	scanf("%d", &n);
	printf("���� n^2���� �������� �Է��Ͻÿ�");
	for (int i = 0; i < n*n; i++)
		scanf("%d", &num[i]); 
	
	str = (int **)calloc(n, sizeof(int*)); //(int ������ ũ�� x n)�� �Ҵ� , �迭�� ����ũ�⸸ŭ�ݺ�
	for (int i = 0; i < n; i++) //n�� ��ŭ �ݺ�
		str[i] = (int*)calloc(n, sizeof(int)); //int ũ�� x n ��ŭ ���� �޸� �Ҵ�. �迭�� ������
	for (int i = 0, k = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			str[i][j] = num[k++];
	
	//������������ ��������
	for (int k = 0; k < n*n; k++) {
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++) {
				if (str[i][j] > str[i][j + 1])
				{
					temp = str[i][j + 1];
					str[i][j + 1] = str[i][j];
					str[i][j] = temp;
				}
				if (i != n - 1) {
					if (str[i][n - 1] > str[i + 1][0])
					{
						temp = str[i][n - 1];
						str[i][n - 1] = str[i + 1][0];
						str[i + 1][0] = temp;
					}
				}
			}

		}
	}
	for (int i = 0; i < n; i++) // ���� for������ ���� ������. 
		for (int j = 0; j < n; j++) {
			if (i % 2 == 1) { //���� �Ƿ��� i�� Ȧ���� �κи� �Ųٷ� �������ָ� ��.
				if (j + 1 <= (n / 2)) { //��� �������� ������ �ٲ��ش� �����ϸ� ��.
					temp = str[i][j];
					str[i][j] = str[i][n - 1 - j];
					str[i][n - 1 - j] = temp;
				}
			}
		}
	for (int i = 0, k = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf("%d\t", str[i][j]);
		printf("\n");
	}//���� �迭 ���!
	free(str);//�޸� �ݳ�!
}

/*
int numArr[3][4] = {    // ���� ũ�� 3, ���� ũ�� 4�� int�� 2���� �迭 ����
	{ 11, 22, 33, 44 },
	{ 55, 66, 77, 88 },
	{ 99, 110, 121, 132 }
}; for (int i = 0; i < n*n - 1; i++) {  //n-1= 9�� �ݺ�(�ǵ��ε����� �������̹Ƿ� �����ʰ� �񱳺Ұ�)
	for (int j = 0; j < n*n - 1 - i; j++) { // (���������� �ǵ� �ε��� ���� ������ �����ε����� �����Ƿ� n-1-i���ݺ�)
		if (num[j] > num[j + 1]) { //������ ������ ũ�� ��ȯ
			temp = num[j];
			num[j] = num[j + 1];
			num[j + 1] = temp;
		}
	}
}*/ //�տ��� ������ �������Ļ���Ͽ� �����������ĿϷ�!