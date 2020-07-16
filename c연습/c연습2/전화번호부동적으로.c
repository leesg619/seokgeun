#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct phone {
	char name[15];
	char phonenum[20];
} phone;
void main() {
	phone *p = (phone*)malloc(2 * sizeof(phone));
	char input_data[30]; //사용자가 입력한 문자열을 저장하는 데이터
	int size = 2;
	int num = 0; //현재 프로그램이 몇명의 데이터를 입력받았는지 저장할 변수
	int menu=0;
	while (1) {
		printf("\n이름 : ");
		scanf("%s", input_data); //이름 입력받음
		if (strlen(input_data) > 15) {
			printf("==비정상 입력==\n");
			printf("입력 가능한 글자 수를 초과\n");
			continue; //다시 반복문 처음으로~!
		}//예외 처리 (글자수 초과

		if (num == 0) //현재 입력받은 사람의 데이터가 0일 때
			strcpy(p[0].name, input_data); //p1.name에 입력받은 데이터 저장.
		if (num == 1) //현재 입력받은 사람의 데이터가 1일 때 (이미 한명 받았으면)
			strcpy(p[1].name, input_data);//p2.name에 입력받은 데이터 저장.

		printf("\n전화번호 : "); //이름을 무사히 받았으니 전화번호를 받아야쥬
		scanf("%s", input_data);

		if (!(strcmp(input_data, p[0].phonenum))) {//만약 입력 받은게 p1의 전화번호와 같다면?
												 //( p1을 아직 입력 안했더라도 p1.phonenum엔 아무것도 없을테니 조건문 연산이 어차피가능해짐
			printf("==비정상 입력==\n");
			printf("데이터가 중복되었습니다.\n");
			continue; //다시 처음으로 돌아가서 이름부터 받으세용
		}//예외 처리
		if (num == 0) { //현재 입력받은 사람의 데이터가 0일 때
			strcpy(p[0].phonenum, input_data);//p1.phonenum에 입력받은 데이터 저장.
			num = num + 1; //이제 p1의 이름과 전화번호가 모두 입력되었으니  num 1증가
			continue; //처음으로가
		}
		if (num == 1) {		//현재 입력받은 사람의 데이터가 0일 때
			strcpy(p[1].phonenum, input_data); //p2.phonenum에 입력받은 데이터 저장.
			num += 1;
			break; //p1,p2모두 성공적으로 입력. 반복 끝 loop탈출
		}
	}
	while (1) {
		printf("추가입력 0  종료 1 : ");
		scanf("%d", &menu);
		if (menu ==1) break;
		else if (menu == 0)
		{
			size += 1;
			p = (phone*)realloc(p, sizeof(phone)*size);
			if (p == NULL)
				exit(1);
			while (1) {
				printf("\n이름 : ");
				scanf("%s", input_data); //이름 입력받음
				
				if (strlen(input_data) > 15) {
					printf("==비정상 입력==\n");
					printf("입력 가능한 글자 수를 초과\n");
					continue; //다시 반복문 처음으로~!
				}
				strcpy(p[num].name, input_data);
				printf("\n전화번호 : "); //이름을 무사히 받았으니 전화번호를 받아야쥬
				scanf("%s", input_data);
				if (!(strcmp(input_data, p[num-1].phonenum))) {//만약 입력 받은게 직전의 전화번호와 같다면?
					printf("==비정상 입력==\n");
					printf("데이터가 중복되었습니다.\n");
					continue; //다시 처음으로 돌아가서 이름부터 받으세용
				}//예외 처리
				strcpy(p[num].phonenum, input_data);
				num += 1;
				break;
			}
		}
	}
	printf("\n\n ==전화번호부 ==\n"); //출력
	for(int i=0;i<size;i++)
		printf("%s   %s\n", p[i].name, p[i].phonenum);
	printf("================\n");
	free(p);	
}