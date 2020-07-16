#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
int main(void)
{
	FILE *ifp, *ofp;  char name[20];
	int sub1, sub2, sub3; int tot; double avg; int res;
	ifp = fopen("input.txt", "r");
	if (ifp == NULL) {
		printf("입력 파일을 열지 못했습니다.");
		return 1; }
	ofp = fopen("output.txt", "w");
	if (ofp == NULL) {
		printf("출력 파일을 열지 못했습니다.");
		return 1; }
	while (1) {
		res = fscanf(ifp, "%s%d%d%d", name, &sub1, &sub2, &sub3); //input.txt파일에서 이름,각 세과목 점수를 받아와 각 변수에 저장한다.
		if (res == EOF)  break; //EOF 리턴시 탈출
		tot = sub1 + sub2 + sub3; //받아온 변수들로 총점 계산
		avg = tot / 3.0; //평균계산
		fprintf(ofp, "%s %5d %5.1lf\n", name, tot, avg); //output.txt파일에 내 이름, 총점 , 평균 출력
	}
	fclose(ifp);   fclose(ofp);
	return 0;
}