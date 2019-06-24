#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct ArrStruct {
	int ** clock;
	int ** butterfly;
	int num;
}ArrStruct;
void create(ArrStruct *arr, int num); //num에 맞추어 구조체 내에 모래시계, 나비배열 만들기 
void print(ArrStruct *arr);			// 모래시계 출력     // 나비 출력   
void main() {
	int num;
	ArrStruct *arr;
	arr = malloc(sizeof(ArrStruct));
	printf("배열의 크기 입력"); //크기 받고 함수호출
	scanf("%d", &num);
	create(arr, num);
	print(arr);
	free(arr->clock); //arr부터 free하면 arr->clock못찾음 순서주의
	free(arr->butterfly);
	free(arr);
}
void create(ArrStruct *arr, int num) {
	int i,j;
	arr->clock = (int**)malloc(num * sizeof(int*)); //이차배열 써야하므로 이중포인터 동적할당
	arr->butterfly = (int**)malloc(num * sizeof(int*));
	arr->num = num;
	for (i = 0; i < num; i++) { //이차 배열 써야하므로 for문으로 num크기만큼 동적할당
		arr->clock[i] = (int*)calloc(num, sizeof(int));
		arr->butterfly[i] = (int*)calloc(num, sizeof(int));
	}
	for (i = 0; i < num; i++) {
		if (i <= num / 2) { //절반 나눠서 생각
			for (j = 0 + i; j < num - i; j++) { //위쪽 모래시계
				arr->clock[i][j] = 1;
			}
		}
		else { //아래쪽 모래시계
			for (j = num- 1-i; j <= i; j++) {
				arr->clock[i][j] = 1;
			}
		}
	}
	//나비는 모래시계를 옆으로 돌리면 나비 모양인걸 참고하여
	for (j = 0; j < num; j++) {  //i,j의 순서만 바꿔서 출력해봤더니 잘되네요
		if (j <= num / 2) {
			for (i = 0 + j; i < num - j; i++) {
				arr->butterfly[i][j] = 1;
			}
		}
		else {
			for (i = num - 1 - j; i <= j; i++) {
				arr->butterfly[i][j] = 1;
			}
		}
	}
}
void print(ArrStruct *arr) { //이중 for문으로 화면에 출력
	for (int i = 0; i < arr->num; i++) {
		for (int j = 0; j < arr->num; j++)
			printf("[%d]",arr->clock[i][j]);
		printf("\n");
	}
	printf("\n\n");
	for (int i = 0; i < arr->num; i++) {
		for (int j = 0; j < arr->num; j++)
			printf("[%d]", arr->butterfly[i][j]);
		printf("\n");
	}
}