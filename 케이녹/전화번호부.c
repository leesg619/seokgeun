#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
 typedef struct phone {
    char name[15];
    char phonenum[20];
} phone;

 void main() {
    phone p1; //첫번째 사람의 데이터를 저장하는 구조체 선언
    phone p2; //두번째 사람의 데이터를 저장하는 구조체 선언
    char input_data[30]; //사용자가 입력한 문자열을 저장하는 데이터
	int num=0; //현재 프로그램이 몇명의 데이터를 입력받았는지 저장할 변수
   //while loop문으로 구현해봤습니다 더 효율적인 방법 생각해볼께요!
	while (1) {
		printf("\n이름 : ");
		scanf("%s", input_data) ; //이름 입력받음

		if (strlen(input_data) > 15) { 
			printf("==비정상 입력==\n");
			printf("입력 가능한 글자 수를 초과\n");
			continue; //다시 반복문 처음으로~!
		}//예외 처리 (글자수 초과

		if (num == 0) //현재 입력받은 사람의 데이터가 0일 때
			strcpy(p1.name, input_data); //p1.name에 입력받은 데이터 저장.

		if (num == 1) //현재 입력받은 사람의 데이터가 1일 때 (이미 한명 받았으면)
			strcpy(p2.name ,input_data);//p2.name에 입력받은 데이터 저장.

		printf("\n전화번호 : "); //이름을 무사히 받았으니 전화번호를 받아야쥬
		scanf("%s", input_data);

		if (!(strcmp(input_data, p1.phonenum))) {//만약 입력 받은게 p1의 전화번호와 같다면?
												//( p1을 아직 입력 안했더라도 p1.phonenum엔 아무것도 없을테니 조건문 연산이 어차피가능해짐
			printf("==비정상 입력==\n");
			printf("데이터가 중복되었습니다.\n");
			continue; //다시 처음으로 돌아가서 이름부터 받으세용
		}//예외 처리
		if (num == 0) { //현재 입력받은 사람의 데이터가 0일 때
			strcpy(p1.phonenum , input_data);//p1.phonenum에 입력받은 데이터 저장.
			num=num + 1; //이제 p1의 이름과 전화번호가 모두 입력되었으니  num 1증가
			continue; //처음으로가
		}	
		if (num == 1) {		//현재 입력받은 사람의 데이터가 0일 때
			strcpy(p2.phonenum , input_data); //p2.phonenum에 입력받은 데이터 저장.
			break; //p1,p2모두 성공적으로 입력. 반복 끝 loop탈출
		}
	}
	printf("\n\n ==전화번호부 ==\n"); //출력
	printf("%s \t%s\n\n", p1.name, p1.phonenum);
	printf("%s \t%s\n", p2.name, p2.phonenum);
}