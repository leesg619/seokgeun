//과제 4> 학번 : 201611830	학년 : 1학년	이름 : 이석근
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void swapArrary(int *pa, int *pb, int size);
void sumAvg(int *pa, int size, int *sum, double *average);
int main(void)
{
	int a[10] = { 10,20,30,40,50,60,70,80,90,100 };
	int b[10] = { 100,200,300,400,500,600,700,800,900,1000 };
	int i, size, sum;
	double average;					// 필요한 변수 선언

	printf("교환할 배열의 크기를 입력하세요<1~10 사이의 값 중 한개의 값 입력>");
	scanf("%d", &size);
	if ((size<1) || (size>10))		//1~10이외의 값 입력시 종료
	{
		printf("배열의 크기가 잘못 입력되어 프로그램이 종료됩니다.\n");
		return;
	}

	printf("\n1. 함수 호출 전\n");

	for (i = 0; i < size; i++)						//반복문을 통해 배열 값 출력
		printf("a[%d번째]=%d  ", i + 1, a[i]);
	printf("\n");
	for (i = 0; i < size; i++)						//반복문을 통해 배열 값 출력
		printf("b[%d]번째=%d  ", i + 1, b[i]);

	printf("\n\n2. 함수 호출 후\n");

	swapArrary(a, b, size);		// 배열a , 배열b 의 배열값들을 서로 바꿈 (swapArray 함수 호출)

	for (i = 0; i < size; i++)						//반복문을 통해 배열 값 출력
		printf("a[%d번째]=%d  ", i + 1, a[i]);
	printf("\n");
	for (i = 0; i < size; i++)						//반복문을 통해 배열 값 출력
		printf("b[%d]번째=%d  ", i + 1, b[i]);

	sumAvg(a, size, &sum, &average);			//배열 a의 합계와 평균값을 계산함(sumAvg 함수 호출)
	printf("\n\n3. 배열 a의 합계 = %d, 평균 : %lf\n",sum , average);		// 배열 a의 합계와 평균 값을 화면에 출력

	sumAvg(b, size, &sum, &average);			//배열 b의 합계와 평균값을 계산함(sumAvg 함수 호출)
	printf("\n4. 배열 b의 합계 = %d, 평균 : %lf\n", sum, average);		// 배열 b의 합계와 평균 값을 화면에 출력
	
	return 0;
}

void swapArrary(int *pa, int *pb, int size)
{
	int changer, i;
	for (i = 0; i < size; i++)		// 두 배열의 값을 서로 바꾸는 반복문
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
	for (i = 0; i < size; i++)		//반복문을 통해 배열의 크기만큼 합을 구한다.
		*sum += pa[i];
	*average = *sum / (double)size;		//합을 배열의 크기만큼 나눠 평균값을 구한다.
}

/*'완성' 주소에 의한 호출이 아직 낯설지만, 여러 개의 값을 리턴하는 경우 매우 편리하여 나중에도 유용할 것 같고,
			포인터도 많이 연습하여 내 것으로 만들고싶다. 아주 재밌다. */