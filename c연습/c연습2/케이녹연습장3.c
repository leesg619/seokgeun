#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct MyStruct1
{
	char ch1;     // 1Byte
	int i1;       // 4Byte
	float f1;     // 4Byte	
	short s1;     // 2Byte
}p1;

typedef struct MyStruct2
{
	char ch2;     // 1Byte
	short s2;     // 2Byte
	int i2;       // 4Byte
	float f2;     // 4Byte
}p2;

typedef struct Mystruct3 {
	char ch3; //1Byte짜리
	int	i3; //4Byte짜리
}p3;

//char = 1byte,  = 8bytes
typedef struct test_s
{
	char a;
	long long b;
} test;


void main() {
	test test;
	printf("%d\n",&test.a);
	printf("%d\n", &test.b);
	printf("%d\n", sizeof(test));
	p1 p1;
	p2 p2;
	printf("%d\n", &p1.ch1);
	printf("%d\n", &p1.i1);
	printf("%d\n", &p1.f1);
	printf("%d\n", &p1.s1);

	printf("MyStruct1의 크기 : %d\n\n", sizeof(p1));
	
	printf("%d\n", &p2.ch2);
	printf("%d\n", &p2.s2);
	printf("%d\n", &p2.i2);
	printf("%d\n", &p2.f2);
	printf("MyStruct2 의 크기 : %d\n", sizeof(p2));
	
}