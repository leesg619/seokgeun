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
	printf("arr2에서 arr1의 문자열 복사 : %s\n" ,arr1);
	my_strcat(arr3, arr4);
	printf("arr4의 문자열을 arr3의 뒤에 문자열 덧붙임 : %s\n", arr3);*/
	if (my_strcmp(arr5, arr6)==0)
		printf("arr5와 arr6문자열이 서로 같습니다. %d\n",my_strcmp(arr5,arr6));
	else
		printf("arr5와 arr6문자열이 서로 다릅니다. %d\n",my_strcmp(arr5,arr6)); 
	
}
int my_strcmp(const char* s1, const char* s2) {
	int result;
	int i = 0;
	while (s1[i] != '\0' || s2[i] != '\0') { //s1,s2중 먼저 널값이 나오는 문자열까지 계산 
		if (s1[i] > s2[i]) {				// (이 아니고 null값이 둘다 아니면^^)★
			result = 1;//s1>s2면 양수 리턴
			return result;
		}
		else if (s1[i] < s2[i]) {
			result = -1; //s1<s2면 음수 리턴
			return result;
		}

		i++; //널 찾을때까지 계속 i를 1씩 더함
	}

	result = 0;
	return result;       // arr1 == arr2 이면 0
}

char *my_strcpy(char* s1, const char* s2){
	
	char*cp = s1;
	if (s2 == NULL) {
		printf("복사할 문자열을 찾지 못했습니다\n");
		return cp;
	}
	int i;
	for (i = 0; s2[i] != '\0'; i++)
		cp[i] = s2[i];

	cp[i] = '\0'; //복사후 마지막에 널로 문자열의 끝을 알려줌

	return cp;
}

char* my_strcat(char* s1, const char* s2){
	char* cp = s1;
	if (s2 == NULL) {
		printf("덧붙일 문자열을 찾지 못했습니다\n");
		return cp;
	}
	int i = 0, j;
	int s2_length = 1; //(널문자 생각해서 1로 시작)
	for (j = 0; s2[j] != '\0'; j++)
		s2_length += 1; //문자열 s2의 길이 저장

	while (cp[i] != '\0') //문자열 s1의 널문자 찾기
		i++;

	for (j = 0; j < s2_length; i++, j++) { //널문자 쪽부터 s2문자열 채우기
		cp[i] = s2[j];
	}

	return cp;
}
