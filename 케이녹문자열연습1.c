#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void main(void) {
	char str1[10] = "LBS";
	char str2[10] = "LSS";
	if(strncmp(str1, str2, 1) == 0)
		printf("두 문자열의 앞의 첫문자는 같다.");
}

/*ar str[50] = { '\0' }; //명시적 널문자 초기화
char str[50] = { 0 }; //널문자의 아스키 코드값으로 초기화
char str[50] = ""; //큰따옴표 안에 아무것도 없으므로 널문자만 초기화
str[0] = '\0'; //첫번째 배열 요소만 별도로 초기화
}*/