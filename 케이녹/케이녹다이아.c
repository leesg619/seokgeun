#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int size; //(다이아몬드의 크기를 저장할 변수 선언)
	printf("size를 입력하세요\n");
	scanf("%d", &size);
	int column = size;//행 변수 선언
	int row = column; // 열 변수 선언 (둘다 size 수만큼 초기화)
	//4분할로 나눠서 만들어본다..
	//위쪽 삼각형
	for (int i = 1; i <= column; i++)
	{
		//1번 부분
		for (int j = row - i; j > 0; j--)
		{
			printf("0");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		if (size % 2 == 0)	//왼쪽 부분이 끝나고,size가 짝수면 미리 별 하나를 출력하고 시작한다. 
			printf("*");

		//2번 부분
		for (int k = 0; k < i - 1; k++)
		{
			printf("*");
		}
		for (int j = (row - i); j > 0; j--)
		{
			printf("0");
		}

		printf("\n"); //다음 행 출력을 위해 줄 바꿔준다.
	}

	//아래쪽 삼각형
	for (int i = 1; i <= column - 1; i++)
	{
		//3번 부분
			for (int j = 0; j < i; j++)
			{
				printf("0");
			}
			for (int k = (row - i); k > 1; k--)
			{
				printf("*");
			}
			if (size % 2 == 0) //왼쪽 부분이 끝나고,size가 짝수면 미리 별 하나를 출력하고 오른쪽 부분을시작한다. 
				printf("*"); //홀수 짝수 둘다 넣어도 잘돌아가는 것을 해보고싶었으나 실패ㅠ
			//4번 부분
			for (int k = i; k < row; k++)
			{
				printf("*");
			}
			for (int j = 0; j < i; j++)
			{
				printf("0");
			}

			printf("\n"); //다음 행 출력을 위해 줄 바꿔준다.
		}

		return 0;
		//내 멍청한 두뇌를 확인할  수 있었던 프로그램이었다
	}
