#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main() {
	int iValue[10] = { 10, 20,30,40,50,60,70,80,90,100 }; //int�� �迭 �ʱ�ȭ
	int *p = &iValue[7]; //int�� ������ p�� 80�� �ּҰ��� ����Ŵ.

	printf("\n\n ***** program start ***** \n\n");

	printf("*p = %d\n", *p); //p�� ����Ű�� �ּҰ� ������ �� : 80
	printf("*p + 1 = %d \n", *p + 1); //p�� ����Ű�� �ּҰ� ������ ���� 1���Ѱ� 81
	printf("*(p+1)=%d \n", *(p + 1));	//1�� size of int �� 4����Ʈ��ŭ �پ�Ѿ��. �� ivalue[7] ���� �迭�� ����� �� ivalue[8] = 90 ��� 

	printf("*p++ = %d \n", *p++);	//���� �������� �ϴ� *p ����ϰ� p �� p+1 �������ְ� �Ѿ�ÿ�
	printf("*++p = %d \n", *++p); //���� �տ� �������� ���� p�� ivalue[9]�� �ּҸ� ����Ű�µ� , ���� �������� �ٷ� p�� p+1 ���ָ� p�� ����Ű�� �ּҴ� ivalue[9]�� �Ǵϱ� 100�� ���

	printf("\n ***** program end ***** \n\n");
}