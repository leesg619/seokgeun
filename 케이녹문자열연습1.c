#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main(void) {
	char str1[10] = "LBS";
	char str2[10] = "LSS";
	if(strncmp(str1, str2, 1) == 0)
		printf("�� ���ڿ��� ���� ù���ڴ� ����.");
}

/*ar str[50] = { '\0' }; //����� �ι��� �ʱ�ȭ
char str[50] = { 0 }; //�ι����� �ƽ�Ű �ڵ尪���� �ʱ�ȭ
char str[50] = ""; //ū����ǥ �ȿ� �ƹ��͵� �����Ƿ� �ι��ڸ� �ʱ�ȭ
str[0] = '\0'; //ù��° �迭 ��Ҹ� ������ �ʱ�ȭ
}*/