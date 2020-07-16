//���� 6-> �й� : 201611830		�г� : 1�г�	�̸� : �̼���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


enum genre { cartoon, novel, classic, others };	//������ genre ����


struct bookmanage {
	char title[200];	//���� ���ڿ� ���� ����
	char author[200];	//�۰� ���ڿ� ���� ����
	int position;	//å�� ��ġ ���� ����
	enum genre ss;	//������ genre���� ����
};
typedef struct bookmanage BOOK;	//BOOK������ ������

void Addbook(BOOK *p, int *n);	//å �߰� �Լ��� ����
void Printbook(BOOK *p, int *n);	//å ��� �Լ��� ����
void Searchbook(BOOK *p, int *n);	//å �˻� �Լ��� ����

int main(void)
{
	BOOK list[200];	//å�� ������ �����ϴ� ���� ����
	int menu;	//�޴��� ��ȣ�� ������ ���� ����
	int book_count = 0;	//�� ����� å�Ǽ� (0���� �ʱ�ȭ)

	while (1)
	{
		printf("=================\n");	//�޴� �Լ� ���
		printf("1.�߰�\n2.���\n3.�˻�\n4.����\n");
		printf("=================\n");

		printf("�������� �Է��Ͻÿ�:");
		scanf("%d", &menu);	//�޴��� ��ȣ �Է¹���
		while (getchar() != '\n');	//���ۿ� �����ִ� ���๮�ڸ� ����

		switch (menu)	//switch�� �̿��Ͽ� �޴� ��ȣ�� ���� �Լ� ȣ�� 
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
			/*  �޴���ȣ�� 1�� ��: å �߰� �Լ� ȣ��
			�޴���ȣ�� 2�� ��: å ��� �Լ� ȣ��
			�޴���ȣ�� 3�� ��: å �˻� �Լ� ȣ��
			�޴���ȣ�� 4�� ��: ���α׷� ����
			*/
		}
	}
	return 0;
}


void Addbook(BOOK *p, int *n)	//å �߰� �Լ��� ����
{

	printf("����:");
	gets(&p->title);	//gets�� ����Ͽ� ���� �Է�

	printf("����:");
	gets(&p->author);	//gets�� ����Ͽ� �۰� �Է�
	
	printf("��ġ:");
	scanf("%d", &p->position);	//å�� ��ġ �Է�(����)
	while (getchar() != '\n');

	printf("�帣(0: ��ȭ, 1:�Ҽ�, 2:����, 3:��Ÿ):");
	scanf("%d", &p->ss);	//�帣 �Է�
	while (getchar() != '\n');

	++(*n);	//�� å�� �� 1����
}

void Printbook(BOOK *p, int *n)		//å ��� �Լ��� ����
{
	int i;
	for (i = 0; i < (*n); i++)		//���ݱ��� �޴� 1�� ���� ����� �� å�� �� ��ŭ �ݺ�
	{
		printf("����: %s\n����: %s\n��ġ: %d\n", (p + i)->title, (p + i)->author, (p + i)->position);
		switch ((p + i)->ss)	//switch�� �̿��Ͽ� ������ ó��
		{
		case cartoon:
			printf("�帣: ��ȭ\n");
			break;
		case novel:
			printf("�帣: �Ҽ�\n");
			break;
		case classic:
			printf("�帣: ����\n");
			break;
		case others:
			printf("�帣: ��Ÿ\n");
			break;
		}
	}
}

void Searchbook(BOOK *p, int *n)	//å �˻� �Լ��� ����
{
	int i;
	char book_name[100];
	printf("����:");
	gets(book_name);	//gets�� �̿��Ͽ� ���� �Է�

	for (i = 0; i < (*n); i++)	// strcmp�� ����ؼ� ��ġ�ϴ� ������ ã��, ��ġ�Ѵٸ� ����� ��ġ�� ���
	{
		if (strcmp(book_name, (p + i)->title) == 0)
			printf("����� ��ġ�� %d\n", (p + i)->position);
	}
}

