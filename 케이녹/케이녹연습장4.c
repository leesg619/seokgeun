#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <string.h> 
int main(void)
{
	FILE *ifp, *ofp;  char name[20];
	int sub1, sub2, sub3; int tot; double avg; int res;
	ifp = fopen("input.txt", "r");
	if (ifp == NULL) {
		printf("�Է� ������ ���� ���߽��ϴ�.");
		return 1; }
	ofp = fopen("output.txt", "w");
	if (ofp == NULL) {
		printf("��� ������ ���� ���߽��ϴ�.");
		return 1; }
	while (1) {
		res = fscanf(ifp, "%s%d%d%d", name, &sub1, &sub2, &sub3); //input.txt���Ͽ��� �̸�,�� ������ ������ �޾ƿ� �� ������ �����Ѵ�.
		if (res == EOF)  break; //EOF ���Ͻ� Ż��
		tot = sub1 + sub2 + sub3; //�޾ƿ� ������� ���� ���
		avg = tot / 3.0; //��հ��
		fprintf(ofp, "%s %5d %5.1lf\n", name, tot, avg); //output.txt���Ͽ� �� �̸�, ���� , ��� ���
	}
	fclose(ifp);   fclose(ofp);
	return 0;
}