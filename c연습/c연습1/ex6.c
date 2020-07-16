/*���� 7> �й� : 201611830  �г� : 1�г�  �̸� : �̼���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *fp;
	int num=1;		// �� �� ù�κ� ���� ��ȣ�� ���̱� ���� ������ ����
	char fname[500];		//���� �̸� �Է� ���� char�� �迭 ����
	char str[500];		//������ ���� �����ϱ� ���� char�� �迭 ����

	printf("���� �̸��� �Է��Ͻÿ�: ");
	gets(fname);		//name[1000]�� ���� �Է� 

	fp = fopen(fname, "r");		//�б� ��� ����

	if (fp == NULL)		//������ ���� ���
	{
		printf("������ ������ �ʾҽ��ϴ�.\n");
		return 1;
	}

	while (1)
	{
		printf("%d   ",num++);		//��ȣ�� ����num�� �̿��Ͽ� ���� ó���߽��ϴ�.
		fgets(str, sizeof(str) , fp);		//���Ͽ��� ���ڿ��� ���� �����Ͽ� ���پ� �Է�
		printf("%s", str);
		if (feof(fp)) //feof�Լ��� �̿��Ͽ� ������ ���̸� �ݺ��� Ż��
			break;	
	}

	fclose(fp);		//������ �ݴ´�.
	
	return 0;
}
