#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct phone {
	char name[15];
	char phonenum[20];
} phone;
void main() {    //첫실행 두번째실행 이하 나눠서해봐도 괜찮을듯
	phone *p = (phone*)malloc(2 * sizeof(phone)); //2개먼저 할당
	char input_data[30]; //사용자가 입력한 문자열을 저장하는 데이터
	int size = 2; //총 몇개의 데이터를 저장할지 저장할변수 
	int num = 0; //현재 프로그램이 몇명의 데이터를 입력받았는지 저장할 변수
	int menu = 0; //입력메뉴
	FILE *ifp = fopen("phonebook.txt", "r+"); //첫실행이면 null이니까 ★행으로

	if (ifp != NULL) { //첫실행 아니면 파일 r+모드로 읽기완료
		printf("자동으로 연락처를 복구합니다\n");
		fscanf(ifp, "%d", &num);
		size = num; 
		p = (phone*)realloc(p, num * sizeof(phone));
		for (int i = 0; i < num; i++) 
			fscanf(ifp, "%s%s", p[i].name, p[i].phonenum); //백업한거 불러오기 완료
	}
	if (ifp == NULL) { //첫실행★
		while (1) {
			ifp = fopen("phonebook.txt", "w"); //w모드로 열면 파일생성함
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
			}

			break; //p1,p2모두 성공적으로 입력. 반복 끝 loop탈출
		}
		fprintf(ifp, "%d\n", size); //파일에 저장
		for (int i = 0; i < size; i++)
			fprintf(ifp, "%s  %s\n", p[i].name, p[i].phonenum);
	}
	if (menu == 0)	{	//변수선언시 menu=0로했으니 일단 무조건 실행
		while (1) {
			printf("추가입력 0  종료 1 : ");
			scanf("%d", &menu);		if (menu == 1) break;
			size += 1;
			p = (phone*)realloc(p, sizeof(phone)*size);
			while (1) {
				printf("\n이름 : ");
				scanf("%s", input_data); //이름 입력받음
				if (strlen(input_data) > 15) {
					printf("==비정상 입력==\n");
					printf("입력 가능한 글자 수를 초과\n");
					continue; //다시 반복문 처음으로~!
				}
				strcpy(p[num].name, input_data); //이름 입력
				printf("\n전화번호 : "); //이름을 무사히 받았으니 전화번호를 받아야쥬
				scanf("%s", input_data);

				if (!(strcmp(input_data, p[num - 1].phonenum))) {//만약 입력 받은게 직전의 전화번호와 같다면?
					printf("==비정상 입력==\n");
					printf("데이터가 중복되었습니다.\n");
					continue; //다시 처음으로 돌아가서 이름부터 받으세용
				}//예외 처리
				strcpy(p[num].phonenum, input_data);
				num += 1; //num도 1더해놔야 또 반복할시 바로 인덱스로넣음
				rewind(ifp);
				fprintf(ifp, "%d\n", size);
				for(int i=0;i<size;i++)
					fprintf(ifp, "%s  %s\n", p[i].name, p[i].phonenum);
				break;
			}
		}
	}
	printf("\n\n ==전화번호부 ==\n"); //출력
	for (int i = 0; i<size; i++)
		printf("%s   %s\n", p[i].name, p[i].phonenum);
	printf("================\n");
	free(p);
	fclose(ifp);
}