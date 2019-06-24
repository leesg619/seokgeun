//과제 6-> 학번 : 201611830		학년 : 1학년	이름 : 이석근
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


enum genre { cartoon, novel, classic, others };	//열거형 genre 선언


struct bookmanage {
	char title[200];	//제목 문자열 변수 선언
	char author[200];	//작가 문자열 변수 선언
	int position;	//책의 위치 변수 선언
	enum genre ss;	//열거형 genre변수 선언
};
typedef struct bookmanage BOOK;	//BOOK형으로 재정의

void Addbook(BOOK *p, int *n);	//책 추가 함수를 선언
void Printbook(BOOK *p, int *n);	//책 출력 함수를 선언
void Searchbook(BOOK *p, int *n);	//책 검색 함수를 선언

int main(void)
{
	BOOK list[200];	//책의 정보를 저장하는 변수 선언
	int menu;	//메뉴의 번호를 저장할 변수 선언
	int book_count = 0;	//총 저장된 책의수 (0으로 초기화)

	while (1)
	{
		printf("=================\n");	//메뉴 함수 출력
		printf("1.추가\n2.출력\n3.검색\n4.종료\n");
		printf("=================\n");

		printf("정수값을 입력하시오:");
		scanf("%d", &menu);	//메뉴의 번호 입력받음
		while (getchar() != '\n');	//버퍼에 남아있는 개행문자를 제거

		switch (menu)	//switch를 이용하여 메뉴 번호에 따라 함수 호출 
		{
		case 1:
			Addbook(&list[book_count], &book_count);
			break;
		case 2:
			Printbook(list, &book_count);
			break;
		case 3:
			Searchbook(list, &book_count);
			break;
		case 4:
			return;		
			/*  메뉴번호가 1일 때: 책 추가 함수 호출
			메뉴번호가 2일 때: 책 출력 함수 호출
			메뉴번호가 3일 때: 책 검색 함수 호출
			메뉴번호가 4일 때: 프로그램 종료
			*/
		}
	}
	return 0;
}


void Addbook(BOOK *p, int *n)	//책 추가 함수의 정의
{

	printf("제목:");
	gets(&p->title);	//gets를 사용하여 제목 입력

	printf("저자:");
	gets(&p->author);	//gets를 사용하여 작가 입력
	
	printf("위치:");
	scanf("%d", &p->position);	//책의 위치 입력(정수)
	while (getchar() != '\n');

	printf("장르(0: 만화, 1:소설, 2:고전, 3:기타):");
	scanf("%d", &p->ss);	//장르 입력
	while (getchar() != '\n');

	++(*n);	//총 책의 수 1증가
}

void Printbook(BOOK *p, int *n)		//책 출력 함수를 정의
{
	int i;
	for (i = 0; i < (*n); i++)		//지금까지 메뉴 1을 통해 저장된 총 책의 수 만큼 반복
	{
		printf("제목: %s\n저자: %s\n위치: %d\n", (p + i)->title, (p + i)->author, (p + i)->position);
		switch ((p + i)->ss)	//switch를 이용하여 열거형 처리
		{
		case cartoon:
			printf("장르: 만화\n");
			break;
		case novel:
			printf("장르: 소설\n");
			break;
		case classic:
			printf("장르: 고전\n");
			break;
		case others:
			printf("장르: 기타\n");
			break;
		}
	}
}

void Searchbook(BOOK *p, int *n)	//책 검색 함수의 정의
{
	int i;
	char book_name[100];
	printf("제목:");
	gets(book_name);	//gets를 이용하여 제목 입력

	for (i = 0; i < (*n); i++)	// strcmp를 사용해서 일치하는 제목을 찾고, 일치한다면 저장된 위치를 출력
	{
		if (strcmp(book_name, (p + i)->title) == 0)
			printf("저장된 위치는 %d\n", (p + i)->position);
	}
}



/*'완성' 프로그래밍 숙제를 하면서 가장 많은 줄의 프로그램이 아닌가 싶다. 구조체와 포인터를 이용하여 나중에도
	짜임새 있는 프로그램을 짤 수 있을것 같아서 기분이 좋았다.*/