#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> //C 언어의 표준 라이브러리 함수의 매크로 정의, 상수, 여러 형의 입출력 함수가 포함된 헤더 파일이다. 
//아스키코드 표를 통해 대문자는 'A'~'Z' : 65~90, 소문자는 'a'~'z' : 97~122 의 값을 가지는 것을 활용한다.
	int main()
	{		
		char str[50]; //문자열 저장할 배열 선언
		printf("영어로 된 문자열을 입력하시오.\n");
		gets_s(str,50); //공백 포함한 문자열을 입력받고 저장함
		for (int i = 0; i < 50; i++)
		{
			if (str[i] >= 'A' && str[i] <= 'Z')	//현재 인덱스에 저장된 값이 대문자면?
				str[i] += 32; //32를 더해줘서 소문자로 바꾼당
			else if (str[i] >= 'a' && str[i] <= 'z') //현재 인덱스에 저장된 값이 소문자면?
				str[i] -= 32; //32를 빼줘서 대문자로 바꾼당
		}

		printf("대소문자 변경 결과 : %s\n", str); 
		
		return 0;
	}
