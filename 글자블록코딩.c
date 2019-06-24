#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char q[100] = { 0 }; // 배열 선언 후 다 0으로초기화
	printf("입력\n");
	scanf("%s", q); //X를 포함한 의문의 문자열을 넣자
	int i = 0, j = 0; //인덱스 설정
	while (q[i] != 0) { // //AAAA를 넣는 while문
		if (q[i] == 'X' && q[i + 1] == 'X' && q[i + 2] == 'X' && q[i + 3] == 'X')
		{
			if (q[i + 4] == 'X' && q[i + 5] != 'X')
			{
				printf("-1\n"); //예외처리
				return 0;
			}
			else { //AAAA채움
				q[i] = 'A', q[i + 1] = 'A', q[i + 2] = 'A', q[i + 3] = 'A';
				i += 4;
				continue; //i 증가시키고 다시반복
			}
		}
		else { //조건 만족하지 않으면 다음인덱스부터 검사
			i += 1;
			continue;
		}
	}
	while (q[j] != 0) { //BB넣는 while문
		if (q[j] == 'X' && q[j + 1] != 'X') {
			printf("-1\n");
			return 0;//예외처리
		}
		if (q[j] == 'X' &&q[j + 1] == 'X') {
			q[j] = 'B', q[j + 1] = 'B'; //BB채움
			j += 2;
			continue;
		}
		else {
			j += 1;
			continue;	}
	}
	printf("%s\n", q); return 0;} //바꾼 문자열 출력후 종료 

/*< 글자 블록 문항> 
용비는 다음과 같은 글자블록 2개(AAAA와 BB)를 무한개만큼 가지고 있다. 
이제 '.'와 'X'로 이루어진 문제블록이 주어졌을 때, 
용비는 겹침없이 문제블록의 'X'를 모두 글자블록으로 덮으려고 한다. 
(이 때, '.'는 글자블록으로 덮으면 안된다.) 
문제블록을 글자블록으로 모두 덮은 블록을 출력하는 프로그램을 작성하시오. 
( 단, 문제블록을 글자 블록으로 변환할 수 없다면 -1을 출력한다.  
문제블록에 덮어씌워지는 글자블록이 겹쳐도 안되고,  
변환 후 X가 남아있어서는 안된다.  
또한 출력할 때 AAAA가 BB보다 먼저 채워져야 합니다.) 

ex)
<입력> 
XXXXXX 
<출력>                                      
AAAABB 
<입력> 
XX.XX 
<출력>                                       
BB.BB 
<입력> 
XXXX....XXX...XX 
<출력>                            
-1 */