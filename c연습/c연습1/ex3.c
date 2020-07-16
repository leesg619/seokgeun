//���� 4> �й� : 201611830	�г� : 1�г�	�̸� : �̼���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swapArrary(int *pa, int *pb, int size);
void sumAvg(int *pa, int size, int *sum, double *average);
int main(void)
{
	int a[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int b[10] = { 100,200,300,400,500,600,700,800,900,1000 };
	int i, size, sum;
	double average;					// �ʿ��� ���� ����

	printf("��ȯ�� �迭�� ũ�⸦ �Է��ϼ���<1~10 ������ �� �� �Ѱ��� �� �Է�>");
	scanf("%d", &size);
	if ((size<1) || (size>10))		//1~10�̿��� �� �Է½� ����
	{
		printf("�迭�� ũ�Ⱑ �߸� �ԷµǾ� ���α׷��� ����˴ϴ�.\n");
		return;
	}

	printf("\n1. �Լ� ȣ�� ��\n");

	for (i = 0; i < size; i++)						//�ݺ����� ���� �迭 �� ���
		printf("a[%d��°]=%d  ", i + 1, a[i]);
	printf("\n");
	for (i = 0; i < size; i++)						//�ݺ����� ���� �迭 �� ���
		printf("b[%d]��°=%d  ", i + 1, b[i]);

	printf("\n\n2. �Լ� ȣ�� ��\n");

	swapArrary(a, b, size);		// �迭a , �迭b �� �迭������ ���� �ٲ� (swapArray �Լ� ȣ��)

	for (i = 0; i < size; i++)						//�ݺ����� ���� �迭 �� ���
		printf("a[%d��°]=%d  ", i + 1, a[i]);
	printf("\n");
	for (i = 0; i < size; i++)						//�ݺ����� ���� �迭 �� ���
		printf("b[%d]��°=%d  ", i + 1, b[i]);

	sumAvg(a, size, &sum, &average);			//�迭 a�� �հ�� ��հ��� �����(sumAvg �Լ� ȣ��)
	printf("\n\n3. �迭 a�� �հ� = %d, ��� : %lf\n",sum , average);		// �迭 a�� �հ�� ��� ���� ȭ�鿡 ���

	sumAvg(b, size, &sum, &average);			//�迭 b�� �հ�� ��հ��� �����(sumAvg �Լ� ȣ��)
	printf("\n4. �迭 b�� �հ� = %d, ��� : %lf\n", sum, average);		// �迭 b�� �հ�� ��� ���� ȭ�鿡 ���
	
	return 0;
}

void swapArrary(int *pa, int *pb, int size)
{
	int changer, i;
	for (i = 0; i < size; i++)		// �� �迭�� ���� ���� �ٲٴ� �ݺ���
	{
		changer = pa[i];
		pa[i] = pb[i];
		pb[i] = changer;
	}
}

void sumAvg(int *pa, int size, int *sum, double *average)
{
	int i;
	*sum = 0;
	for (i = 0; i < size; i++)		//�ݺ����� ���� �迭�� ũ�⸸ŭ ���� ���Ѵ�.
		*sum += pa[i];
	*average = *sum / (double)size;		//���� �迭�� ũ�⸸ŭ ���� ��հ��� ���Ѵ�.
}
