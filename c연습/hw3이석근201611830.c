//과제 2 > 학번 : 201611830		학년 : 1학년	이름 : 이석근
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main(void)
{
	int ary1[5], ary2[5];	//1차원 배열 2개 선언
	int *pa = ary1;			//포인터 선언 후 배열1 저장	
	int *pb = ary2;			//포인터 선언 후 배열2 저장
	int i, size, max, min;

	printf("1. 5개의 정수 입력 :\n");
	for (i = 0; i < 5; i++)					// 5개의 정수값을 받아	배열1에 저장하는 반복문
	{
		printf("%d번째 숫자 : ", i + 1);
		scanf("%d", pa++);
	}

	pa = ary1;	//(과제 주의사항 참고함)반복문이 끝날 때 마다 배열의 처음주소로 바꿔준다. 

	printf("\n2. 입력된 값을 저장한 배열1의 값 출력\n");

	for (i = 0; i < 5; i++)			// 배열 1의 값들을 화면에 출력한다.
	{
		printf("%d번째 값 : %d\n", i + 1, *pa++);
	}

	printf("\n3. 최대값과 최소값을 제외한 값을 저장한 배열2의 값 출력\n");

	pa = ary1;
	max = *pa;
	min = *pa;		//max, min 의 값을 먼저 배열1의 첫번째 값으로 초기화 해준다.

	for (i = 0; i < 5; i++)			// max , min 변수로 반복문,조건문을 이용하여 최대,최소값을 구한다.
	{
		if (max < *pa)
			max = *pa;
		if (min > *pa)
			min = *pa;
		pa++;
	}

	pa = ary1;
	size = 0;		//size는 배열 2의 크기를 결정하는 변수다.

	for (i = 0; i < 5; i++)		//과제 조건에 따라 배열 2를 저장하는 과정. 
	{
		if (max == *pa)
			pa++;

		else if (min == *pa)
			pa++;

		else					//이부분이 가장 중요하다. 최소값 또는 최대값이 아닌경우 size의 값도 올리고	배열2에 값도 저장해준다.
		{
			*pb = *pa;
			size++;
			pa++;
			pb++;
		}
	}

	pb = ary2;

	switch (size)			//switch문을 이용하여 배열2 출력
	{

	case 0:
		printf("배열2의 값은 없습니다.\n");
		break;

	default:
		for (i = 0; i < size; i++)
		{
			printf("%d번째 값 : %d\n", i + 1, *pb++);
		}
		break;

	}
}

/*'완성' 처음엔 배열2의 값을 저장하는 방법이 까다롭고 생각이 안났는데, 다시 복습하고
			실습하다보니 바로 영감을 얻어서 빠르게 완성했고 뿌듯했다. 중간고사때 이렇게 생각이 잘나면 좋겠다.*/