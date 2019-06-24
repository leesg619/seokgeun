#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
typedef struct ArrStruct {
	int ** clock;
	int ** butterfly;
	int num;
}ArrStruct;
void create(ArrStruct *arr, int num); //num�� ���߾� ����ü ���� �𷡽ð�, ����迭 ����� 
void print(ArrStruct *arr);			// �𷡽ð� ���     // ���� ���   
void main() {
	int num;
	ArrStruct *arr;
	arr = malloc(sizeof(ArrStruct));
	printf("�迭�� ũ�� �Է�"); //ũ�� �ް� �Լ�ȣ��
	scanf("%d", &num);
	create(arr, num);
	print(arr);
	free(arr->clock); //arr���� free�ϸ� arr->clock��ã�� ��������
	free(arr->butterfly);
	free(arr);
}
void create(ArrStruct *arr, int num) {
	int i,j;
	arr->clock = (int**)malloc(num * sizeof(int*)); //�����迭 ����ϹǷ� ���������� �����Ҵ�
	arr->butterfly = (int**)malloc(num * sizeof(int*));
	arr->num = num;
	for (i = 0; i < num; i++) { //���� �迭 ����ϹǷ� for������ numũ�⸸ŭ �����Ҵ�
		arr->clock[i] = (int*)calloc(num, sizeof(int));
		arr->butterfly[i] = (int*)calloc(num, sizeof(int));
	}
	for (i = 0; i < num; i++) {
		if (i <= num / 2) { //���� ������ ����
			for (j = 0 + i; j < num - i; j++) { //���� �𷡽ð�
				arr->clock[i][j] = 1;
			}
		}
		else { //�Ʒ��� �𷡽ð�
			for (j = num- 1-i; j <= i; j++) {
				arr->clock[i][j] = 1;
			}
		}
	}
	//����� �𷡽ð踦 ������ ������ ���� ����ΰ� �����Ͽ�
	for (j = 0; j < num; j++) {  //i,j�� ������ �ٲ㼭 ����غô��� �ߵǳ׿�
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
void print(ArrStruct *arr) { //���� for������ ȭ�鿡 ���
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