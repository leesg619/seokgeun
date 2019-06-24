/*과제 7> 학번 : 201611830  학년 : 1학년  이름 : 이석근*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	int num=1;		// 각 줄 첫부분 마다 번호를 붙이기 위해 선언한 변수
	char fname[500];		//파일 이름 입력 위한 char형 배열 선언
	char str[500];		//파일의 내용 저장하기 위한 char형 배열 선언

	printf("파일 이름을 입력하시오: ");
	gets(fname);		//name[1000]에 파일 입력 

	fp = fopen(fname, "r");		//읽기 모드 개방

	if (fp == NULL)		//파일이 없는 경우
	{
		printf("파일이 열리지 않았습니다.\n");
		return 1;
	}

	while (1)
	{
		printf("%d   ",num++);		//번호는 변수num을 이용하여 따로 처리했습니다.
		fgets(str, sizeof(str) , fp);		//파일에서 문자열을 공백 포함하여 한줄씩 입력
		printf("%s", str);
		if (feof(fp)) //feof함수를 이용하여 파일의 끝이면 반복문 탈출
			break;	
	}

	fclose(fp);		//파일을 닫는다.
	
	return 0;
}

/*'완성' 느낀점 : 파일을 처음 배우고 간단한 과제를 했다. 코드가 짧게 나오고 쉬워서 좋았다.
	왜 교수님이 이 과제를 하면 파일이 더 재밌어질것이라고 하셨는지 알 것 같다. 더 열심히 공부할 것이다.*/