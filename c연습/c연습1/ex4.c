// ���� 5>	�й� : 201611830  �г� : 1�г�  �̸� : �̼���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void TextChanger(const char str[101], const char searchword[101], const char changeword[101], char tempdata[101]);		//'ã�� �ٲٱ�' �Լ��� �����Ѵ�.
int main(void)
{
	char str[101];		//���ǿ��� �ִ� ���̰� 100�̶� �Ͽ����Ƿ�, �� ���ڸ� �����Ͽ� 101�� ��.
	char searchword[101];		//ã�� ���ڿ��� �����Ѵ�.
	char changeword[101];	//�ٲ� ���ڿ��� �����Ѵ�.
	char tempdata[101] = { 0, };		//��� ���ڿ��� �����Ѵ�.
	
	printf("���ڿ��� �Է��ϼ���: ");
	gets(str);		//���� ���ڿ��� �Է��Ѵ�. (���ǿ��� scanf�Լ��� ������� ���� �ߴ�.)
	printf("ã�� ���ڿ�: ");
	gets(searchword);		//ã�� ���ڿ��� �Է��Ѵ�.
	printf("�ٲ� ���ڿ�: ");
	gets(changeword);		//�ٲ� ���ڿ��� �Է��Ѵ�.

	TextChanger(str, searchword, changeword, tempdata);		//'ã�� �ٲٱ�' �Լ��� ȣ���Ѵ�.
	printf("���:%s\n", tempdata);		//'ã�� �ٲٱ�' �Լ��� ���� ���ڿ��� �ٲ� �� ���� ��� ���ڿ��� ȭ�鿡 ����Ѵ�.
	return 0;
}
void TextChanger(const char str[101], const char searchword[101], const char changeword[101], char tempdata[101])		//'ã�� �ٲٱ�' �Լ� ����
{
	char *pstr;		
	int length;
	int num;

	length = strlen(searchword);		//strlen�� �̿��Ͽ� ã�� ���ڿ��� ���̸� ���Ѵ�.
	pstr = strstr(str, searchword);		//strstr�� �̿��Ͽ� ���忭���� ���� ã���� �� ���ڿ��� ã�´�.
	num = (int)(pstr - str);			//ã�� ���ڿ��� ��ġ�� ����Ѵ�.

	strncpy(tempdata, str, num);		//strncpy�� �̿��Ͽ� ���� ã�� ���ڿ� �տ� �ִ� ���ڿ��� �̾ƿͼ� �߰��Ѵ�.
	tempdata[num] = NULL;		//���ڿ��� ���� NULL���ڰ� �־�� �Ѵ�.

	strcat(tempdata, changeword);		//strcat�� �̿��Ͽ� �ٲ� ���ڿ��� �߰��Ѵ�.

	strcat(tempdata, str + num + length);		//strcat�� �̿��Ͽ� ���� ã�� ���ڿ��� �ڿ� �ִ� ���ڿ��� �̾ƿͼ� �߰��Ѵ�.

}
