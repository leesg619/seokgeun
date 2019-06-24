/* 과제 1 > 학번 : 201611830  학년 : 1학년 이름 : 이석근 */
#define _CRT_SECURE_NO_WARNINGS
#define PLAYER 4	//기호상수 정의
#define GAME 3		//기호상수 정의
#include <stdio.h>

void main(void)
{
	int score[PLAYER][GAME];	//2차원 배열 정의
	int i, j, tot, max_score;	//정수형 변수 정의 ( tot : 총점을 저장, max_score : 최고점수를 저장)
	double avg;		//실수형 변수 정의 (평균을 저장)

	for (i = 0; i < PLAYER; i++)		// 2차원 배열에 점수를 저장하는 반복문
	{
		for (j = 0; j < GAME; j++)
		{
			printf("선수 %d의 %d번째 종목 점수 : ", i +1,j+1);
			scanf("%d", &score[i][j]);	
		}
	}

	printf("\n");
	printf("<선수별 분석>\n");
	
	for (i = 0; i < PLAYER; i++)		// 선수별 평균을 구하는 반복문
	{
		tot = 0;	// 선수가 바뀔 때마다 다시 총점 = 0 으로 초기화 해준다.
		for (j = 0; j < GAME; j++)
		{
			tot += score[i][j];
		}
		avg = tot / 3.0;
		printf("선수 %d의 평균 점수 = %lf\n", i+1 , avg);
	}

	printf("\n");
	printf("<종목별 분석>\n");

	for (j = 0; j < GAME; j++)		// 종목별로 최고점수와,평균점수를 구하는 반복문
	{
		max_score = 0;		//종목이 바뀔때마다 다시 0으로 초기화
		tot = 0;
		for (i = 0; i < PLAYER; i++)
		{
			tot += score[i][j];
			if (max_score < score[i][j])		//if문을 이용하여 최고점수를 판단하여 저장
				max_score = score[i][j];
		}
		avg = tot / 4.0;
		printf("%d번째 종목 경기를 치른 모든 선수들 중 최고점수 = %d\n", j+1 , max_score);
		printf("%d번째 종목 경기를 치른 모든 선수들에 대한 평균점수 = %lf\n\n", j+1 , avg);
	}


}

/* '완성' 느낀점 : 교수님이 내주신 과제를 하니, 1학기 때 컴퓨터과학개론 수업 생각도 나고 기분이 아주 좋았다. 
					2학기 때도 교수님의 수업을 열심히 들어서 과제를 모두 성공적으로 완성하고 싶다. */