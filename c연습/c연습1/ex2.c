//���� 2 > �й� : 201611830		�г� : 1�г�	�̸� : �̼���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void)
{
	int ary1[5], ary2[5];	//1���� �迭 2�� ����
	int *pa = ary1;			//������ ���� �� �迭1 ����	
	int *pb = ary2;			//������ ���� �� �迭2 ����
	int i, size, max, min;

	printf("1. 5���� ���� �Է� :\n");
	for (i = 0; i < 5; i++)					// 5���� �������� �޾�	�迭1�� �����ϴ� �ݺ���
	{
		printf("%d��° ���� : ", i + 1);
		scanf("%d", pa++);
	}

	pa = ary1;	//(���� ���ǻ��� ������)�ݺ����� ���� �� ���� �迭�� ó���ּҷ� �ٲ��ش�. 

	printf("\n2. �Էµ� ���� ������ �迭1�� �� ���\n");

	for (i = 0; i < 5; i++)			// �迭 1�� ������ ȭ�鿡 ����Ѵ�.
	{
		printf("%d��° �� : %d\n", i + 1, *pa++);
	}

	printf("\n3. �ִ밪�� �ּҰ��� ������ ���� ������ �迭2�� �� ���\n");

	pa = ary1;
	max = *pa;
	min = *pa;		//max, min �� ���� ���� �迭1�� ù��° ������ �ʱ�ȭ ���ش�.

	for (i = 0; i < 5; i++)			// max , min ������ �ݺ���,���ǹ��� �̿��Ͽ� �ִ�,�ּҰ��� ���Ѵ�.
	{
		if (max < *pa)
			max = *pa;
		if (min > *pa)
			min = *pa;
		pa++;
	}

	pa = ary1;
	size = 0;		//size�� �迭 2�� ũ�⸦ �����ϴ� ������.

	for (i = 0; i < 5; i++)		//���� ���ǿ� ���� �迭 2�� �����ϴ� ����. 
	{
		if (max == *pa)
			pa++;

		else if (min == *pa)
			pa++;

		else					//�̺κ��� ���� �߿��ϴ�. �ּҰ� �Ǵ� �ִ밪�� �ƴѰ�� size�� ���� �ø���	�迭2�� ���� �������ش�.
		{
			*pb = *pa;
			size++;
			pa++;
			pb++;
		}
	}

	pb = ary2;

	switch (size)			//switch���� �̿��Ͽ� �迭2 ���
	{

	case 0:
		printf("�迭2�� ���� �����ϴ�.\n");
		break;

	default:
		for (i = 0; i < size; i++)
		{
			printf("%d��° �� : %d\n", i + 1, *pb++);
		}
		break;

	}
}
