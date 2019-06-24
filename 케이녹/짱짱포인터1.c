#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int iValue[10] = { 10, 20,30,40,50,60,70,80,90,100 }; //int형 배열 초기화
	int *p = &iValue[7]; //int형 포인터 p는 80의 주소값을 가리킴.

	printf("\n\n ***** program start ***** \n\n");

	printf("*p = %d\n", *p); //p가 가리키는 주소가 저장한 값 : 80
	printf("*p + 1 = %d \n", *p + 1); //p가 가리키는 주소가 저장한 값에 1더한값 81
	printf("*(p+1)=%d \n", *(p + 1));	//1은 size of int 즉 4바이트만큼 뛰어넘어라. 즉 ivalue[7] 다음 배열에 저장된 값 ivalue[8] = 90 출력 

	printf("*p++ = %d \n", *p++);	//후위 연산으로 일단 *p 출력하고 p 에 p+1 저장해주고 넘어가시오
	printf("*++p = %d \n", *++p); //지금 앞에 연산으로 인해 p는 ivalue[9]의 주소를 가리키는데 , 전위 연산으로 바로 p에 p+1 해주면 p가 가리키는 주소는 ivalue[9]가 되니까 100이 출력

	printf("\n ***** program end ***** \n\n");
}