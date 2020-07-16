/*���� 8 -> �й� : 201611830  �г� : 1�г�  �̸� : �̼��� */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 

struct student {
	int year;			//����ü ��� (�г�) ����
	char name[10];		//����ü ��� (�̸�) ���ڿ� ����

};			//����ü�� �����Ѵ�.

int main(void)
{
	FILE *fp;			//���� ������ ����
	int num,i;
	struct student *list;		//����ü ������ ���� ����

	printf("�Է��� �л����� �Է��Ͻÿ� : "); 
	scanf("%d", &num);		//���� num�� �л��� ����

	fp = fopen("c:\\temp\\student_information.txt", "w");			//�ؽ�Ʈ������ ������� open
	list = (struct student *)malloc(50 * sizeof(struct student));		//malloc �Լ��� �̿��� ��ü ���� ���� ���� �Ҵ�

	if (list == NULL)		  //NULL���� ���
	{
		printf("�޸𸮰� �����մϴ�.\n"); 
		return 1;
	}

	for (i = 0; i<num; i++)			//�л� �� ��ŭ �ݺ����� �̿��Ͽ� ���� �޸��� ����ü�� �̸��� �г� ����
	{
		printf("�̸��� �г� �Է� : ");
		scanf("%s %d", (list + i)->name, &(list + i)->year);
	}

	if (fp == NULL)			 //NULL���� ���
	{
		printf("���� ���� ���� \n");
		return 1;
	}
	
	for (i = 0; i < num; i++)		//�л� ����ŭ �ݺ��� �̿�
		fprintf(fp, "�̸� : %s, �г� : %d\n", (list + i)->name, (list + i)->year);  //�̸�,�гⰪ�� student_information.txt�� ������� 

	free(list);			 //�Ҵ�� �����޸𸮸� �ݳ�
	fclose(fp);			 //������ �ݴ´�.

	return 0;
}