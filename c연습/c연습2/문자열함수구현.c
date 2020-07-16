#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
char* my_strcpy(char* s1, const char* s2);
char* my_strcat(char* s1, const char* s2);
int my_strcmp(const char* s1, const char* s2);

void main() {
	char arr1[30] ="LEESEOKGEUN";
	char arr2[30] = "HI";
	char arr3[30] = "K_KNOCK";
	char arr4[30] = "FIGHTING";
	char arr5[30] = "ABCf";
	char arr6[30] = "ABC";
	/*char *ptr = NULL;
	my_strcpy(arr1, arr2);
	printf("arr2���� arr1�� ���ڿ� ���� : %s\n" ,arr1);
	my_strcat(arr3, arr4);
	printf("arr4�� ���ڿ��� arr3�� �ڿ� ���ڿ� ������ : %s\n", arr3);*/
	if (my_strcmp(arr5, arr6)==0)
		printf("arr5�� arr6���ڿ��� ���� �����ϴ�. %d\n",my_strcmp(arr5,arr6));
	else
		printf("arr5�� arr6���ڿ��� ���� �ٸ��ϴ�. %d\n",my_strcmp(arr5,arr6)); 
	
}
int my_strcmp(const char* s1, const char* s2) {
	int result;
	int i = 0;
	while (s1[i] != '\0' || s2[i] != '\0') { //s1,s2�� ���� �ΰ��� ������ ���ڿ����� ��� 
		if (s1[i] > s2[i]) {				// (�� �ƴϰ� null���� �Ѵ� �ƴϸ�^^)��
			result = 1;//s1>s2�� ��� ����
			return result;
		}
		else if (s1[i] < s2[i]) {
			result = -1; //s1<s2�� ���� ����
			return result;
		}

		i++; //�� ã�������� ��� i�� 1�� ����
	}

	result = 0;
	return result;       // arr1 == arr2 �̸� 0
}

char *my_strcpy(char* s1, const char* s2){
	
	char*cp = s1;
	if (s2 == NULL) {
		printf("������ ���ڿ��� ã�� ���߽��ϴ�\n");
		return cp;
	}
	int i;
	for (i = 0; s2[i] != '\0'; i++)
		cp[i] = s2[i];

	cp[i] = '\0'; //������ �������� �η� ���ڿ��� ���� �˷���

	return cp;
}

char* my_strcat(char* s1, const char* s2){
	char* cp = s1;
	if (s2 == NULL) {
		printf("������ ���ڿ��� ã�� ���߽��ϴ�\n");
		return cp;
	}
	int i = 0, j;
	int s2_length = 1; //(�ι��� �����ؼ� 1�� ����)
	for (j = 0; s2[j] != '\0'; j++)
		s2_length += 1; //���ڿ� s2�� ���� ����

	while (cp[i] != '\0') //���ڿ� s1�� �ι��� ã��
		i++;

	for (j = 0; j < s2_length; i++, j++) { //�ι��� �ʺ��� s2���ڿ� ä���
		cp[i] = s2[j];
	}

	return cp;
}
