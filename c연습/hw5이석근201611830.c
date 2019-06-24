// 과제 5>	학번 : 201611830  학년 : 1학년  이름 : 이석근
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void TextChanger(const char str[101], const char searchword[101], const char changeword[101], char tempdata[101]);		//'찾아 바꾸기' 함수를 선언한다.
int main(void)
{
	char str[101];		//조건에서 최대 길이가 100이라 하였으므로, 널 문자를 생각하여 101로 함.
	char searchword[101];		//찾을 문자열을 선언한다.
	char changeword[101];	//바꿀 문자열을 선언한다.
	char tempdata[101] = { 0, };		//결과 문자열을 선언한다.
	
	printf("문자열을 입력하세요: ");
	gets(str);		//원본 문자열을 입력한다. (조건에서 scanf함수를 사용하지 말라 했다.)
	printf("찾을 문자열: ");
	gets(searchword);		//찾을 문자열을 입력한다.
	printf("바꿀 문자열: ");
	gets(changeword);		//바꿀 문자열을 입력한다.

	TextChanger(str, searchword, changeword, tempdata);		//'찾아 바꾸기' 함수를 호출한다.
	printf("결과:%s\n", tempdata);		//'찾아 바꾸기' 함수를 통해 문자열을 바꾼 뒤 얻은 출력 문자열을 화면에 출력한다.
	return 0;
}
void TextChanger(const char str[101], const char searchword[101], const char changeword[101], char tempdata[101])		//'찾아 바꾸기' 함수 정의
{
	char *pstr;		
	int length;
	int num;

	length = strlen(searchword);		//strlen을 이용하여 찾을 문자열의 길이를 구한다.
	pstr = strstr(str, searchword);		//strstr을 이용하여 문장열에서 내가 찾고자 할 문자열을 찾는다.
	num = (int)(pstr - str);			//찾은 문자열의 위치를 계산한다.

	strncpy(tempdata, str, num);		//strncpy를 이용하여 내가 찾는 문자열 앞에 있는 문자열을 뽑아와서 추가한다.
	tempdata[num] = NULL;		//문자열은 끝에 NULL문자가 있어야 한다.

	strcat(tempdata, changeword);		//strcat를 이용하여 바꿀 문자열을 추가한다.

	strcat(tempdata, str + num + length);		//strcat를 이용하여 내가 찾는 문자열의 뒤에 있는 문자열을 뽑아와서 추가한다.

}

/*	'완성' 느낀점: 문자열을 이용한 프로그램을 처음 해보았는데, 아직 라이브러리 함수들이 익숙하지 않아서 걱정이다.
그래도 열심히 복습을 하면서 꾸준히 연습할 것이다.*/