/* ���� 1 > �й� : 201611830  �г� : 1�г� �̸� : �̼��� */
#define _CRT_SECURE_NO_WARNINGS
#define PLAYER 4	//��ȣ��� ����
#define GAME 3		//��ȣ��� ����
#include <stdio.h>

void main(void)
{
	int score[PLAYER][GAME];	//2���� �迭 ����
	int i, j, tot, max_score;	//������ ���� ���� ( tot : ������ ����, max_score : �ְ������� ����)
	double avg;		//�Ǽ��� ���� ���� (����� ����)

	for (i = 0; i < PLAYER; i++)		// 2���� �迭�� ������ �����ϴ� �ݺ���
	{
		for (j = 0; j < GAME; j++)
		{
			printf("���� %d�� %d��° ���� ���� : ", i +1,j+1);
			scanf("%d", &score[i][j]);	
		}
	}

	printf("\n");
	printf("<������ �м�>\n");
	
	for (i = 0; i < PLAYER; i++)		// ������ ����� ���ϴ� �ݺ���
	{
		tot = 0;	// ������ �ٲ� ������ �ٽ� ���� = 0 ���� �ʱ�ȭ ���ش�.
		for (j = 0; j < GAME; j++)
		{
			tot += score[i][j];
		}
		avg = tot / 3.0;
		printf("���� %d�� ��� ���� = %lf\n", i+1 , avg);
	}

	printf("\n");
	printf("<���� �м�>\n");

	for (j = 0; j < GAME; j++)		// ���񺰷� �ְ�������,��������� ���ϴ� �ݺ���
	{
		max_score = 0;		//������ �ٲ𶧸��� �ٽ� 0���� �ʱ�ȭ
		tot = 0;
		for (i = 0; i < PLAYER; i++)
		{
			tot += score[i][j];
			if (max_score < score[i][j])		//if���� �̿��Ͽ� �ְ������� �Ǵ��Ͽ� ����
				max_score = score[i][j];
		}
		avg = tot / 4.0;
		printf("%d��° ���� ��⸦ ġ�� ��� ������ �� �ְ����� = %d\n", j+1 , max_score);
		printf("%d��° ���� ��⸦ ġ�� ��� �����鿡 ���� ������� = %lf\n\n", j+1 , avg);
	}


}
