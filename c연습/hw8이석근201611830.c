/*과제 8 -> 학번 : 201611830  학년 : 1학년  이름 : 이석근 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

struct student {
	int year;			//구조체 멤버 (학년) 선언
	char name[10];		//구조체 멤버 (이름) 문자열 선언

};			//구조체를 선언한다.

int main(void)
{
	FILE *fp;			//파일 포인터 선언
	int num,i;
	struct student *list;		//구조체 포인터 변수 선언

	printf("입력할 학생수를 입력하시오 : "); 
	scanf("%d", &num);		//변수 num에 학생수 저장

	fp = fopen("c:\\temp\\student_information.txt", "w");			//텍스트파일을 쓰기모드로 open
	list = (struct student *)malloc(50 * sizeof(struct student));		//malloc 함수를 이용해 전체 저장 공간 동적 할당

	if (list == NULL)		  //NULL값인 경우
	{
		printf("메모리가 부족합니다.\n"); 
		return 1;
	}

	for (i = 0; i<num; i++)			//학생 수 만큼 반복문을 이용하여 동적 메모리의 구조체에 이름과 학년 저장
	{
		printf("이름과 학년 입력 : ");
		scanf("%s %d", (list + i)->name, &(list + i)->year);
	}

	if (fp == NULL)			 //NULL값인 경우
	{
		printf("파일 열기 실패 \n");
		return 1;
	}
	
	for (i = 0; i < num; i++)		//학생 수만큼 반복문 이용
		fprintf(fp, "이름 : %s, 학년 : %d\n", (list + i)->name, (list + i)->year);  //이름,학년값을 student_information.txt에 파일출력 

	free(list);			 //할당된 동적메모리를 반납
	fclose(fp);			 //파일을 닫는다.

	return 0;
}

/*'완성'  2학기 마지막 과제를 성공적으로 마무리해서 기분이 좋았고, 벌써 1학년 생활이 끝이라는 것을 실감하니 너무 슬프다. 내년엔 더 열심히 공부 해야겠다.*/