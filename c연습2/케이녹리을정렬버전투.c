#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>//C 언어의 표준 라이브러리 함수의 매크로 정의, 상수, 여러 형의 입출력 함수가 포함된 헤더 파일이다
#include<stdlib.h>
void main() {
	int n, temp;//배열 크기를 받는 변수 n선언,값 교환시 임시저장할때필요한 temp선언
	int **str; //이차 배열의 동적 메모리 할당을 위해 포인터를 가리키는 이중 포인터 변수선언
	
	int num[100];
	printf("배열 크기 n을 입력하시오 ");
	scanf("%d", &n);
	printf("정수 n^2개를 순서없이 입력하시오");
	for (int i = 0; i < n*n; i++)
		scanf("%d", &num[i]); 
	
	str = (int **)calloc(n, sizeof(int*)); //(int 포인터 크기 x n)를 할당 , 배열의 세로크기만큼반복
	for (int i = 0; i < n; i++) //n개 만큼 반복
		str[i] = (int*)calloc(n, sizeof(int)); //int 크기 x n 만큼 동적 메모리 할당. 배열의 가로임
	for (int i = 0, k = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			str[i][j] = num[k++];
	
	//이차원정렬의 버블정렬
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
	for (int i = 0; i < n; i++) // 이중 for문으로 ㄹ자 만들어보자. 
		for (int j = 0; j < n; j++) {
			if (i % 2 == 1) { //ㄹ자 되려면 i는 홀수인 부분만 거꾸로 정렬해주면 됨.
				if (j + 1 <= (n / 2)) { //가운데 기준으로 양쪽을 바꿔준다 생각하면 됨.
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
	}//ㄹ자 배열 출력!
	free(str);//메모리 반납!
}

/*
int numArr[3][4] = {    // 세로 크기 3, 가로 크기 4인 int형 2차원 배열 선언
	{ 11, 22, 33, 44 },
	{ 55, 66, 77, 88 },
	{ 99, 110, 121, 132 }
}; for (int i = 0; i < n*n - 1; i++) {  //n-1= 9번 반복(맨뒤인덱스는 마지막이므로 오른쪽과 비교불가)
	for (int j = 0; j < n*n - 1 - i; j++) { // (마찬가지로 맨뒤 인덱스 까지 갔을때 다음인덱스가 없으므로 n-1-i번반복)
		if (num[j] > num[j + 1]) { //오른쪽 값보다 크면 교환
			temp = num[j];
			num[j] = num[j + 1];
			num[j + 1] = temp;
		}
	}
}*/ //앞에서 조사한 버블정렬사용하여 오름차순정렬완료!