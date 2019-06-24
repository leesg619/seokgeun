#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phone {
	char name[15];
	char phonenum[20];
} phone;

phone* user_data(phone *, int);

int main() {
	phone *p; //구조체 포인터 선언
	 //사용자가 입력한 문자열을 저장하는 데이터
	int i = 0;
	int size = 2;
	int menu=0;
	p = (phone*)calloc( size, sizeof(phone*));// 최소 2개입력

	for (i = 0; i < size; i++) {
		user_data(p	, i);
	}
	while (!menu) {
		printf("\n추가입력 0, 종료 1\t");
		scanf("%d", &menu);
		if(menu==0){
			size += 1;
			p = (phone*)realloc(p, size);
			user_data(p, size-1);
		}
		else continue;
	}
	printf("\n\n ==전화번호부 ==\n\n"); //출력
	for (i = 0; i < size; i++) {
		printf("%s\t%s\n", p[i].name, p[i].phonenum);
	}printf("\n=================");
	free(p);
	return 0;
}


phone* user_data(phone *p, int i) {
	char input_name[30];
	char input_phonenum[30];
	while (1) {
		printf("이름 : ");
		scanf("%s", input_name); //이름 입력받음

		if (strlen(input_name) > 15) {
			printf("==비정상 입력==\n");
			printf("입력 가능한 글자 수를 초과\n");
			continue; //다시 반복문 처음으로~!
		}//예외 처리 (글자수 초과
		if (!(strcmp("", p[i].name)))
			strcpy(p[i].name, input_name);

		//이것도문제네 밑에서 중복뜨면 ㅈㅈ시발
		printf("\n전화번호 : "); //이름을 무사히 받았으니 전화번호를 받아야쥬
		getchar();
		scanf("%s", input_phonenum);

		if (i != 0) {
			if (!(strcmp(input_phonenum, p[i - 1].phonenum))) {//만약 입력 받은게 p1의 전화번호와 같다면?
				printf("==비정상 입력==\n");
				printf("데이터가 중복되었습니다.\n");
				continue; //다시 처음으로 돌아가서 이름부터 받으세용
			}//예외 처리
		}

		
			strcpy(p[i].phonenum, input_phonenum);//p1.phonenum에 입력받은 데이터 저장.
			break; 		

	}
	

}
