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
	char input_data[30]; //����ڰ� �Է��� ���ڿ��� �����ϴ� ������
	int size = 2;
	int num = 0; //���� ���α׷��� ����� �����͸� �Է¹޾Ҵ��� ������ ����
	int menu=0;
	while (1) {
		printf("\n�̸� : ");
		scanf("%s", input_data); //�̸� �Է¹���
		if (strlen(input_data) > 15) {
			printf("==������ �Է�==\n");
			printf("�Է� ������ ���� ���� �ʰ�\n");
			continue; //�ٽ� �ݺ��� ó������~!
		}//���� ó�� (���ڼ� �ʰ�

		if (num == 0) //���� �Է¹��� ����� �����Ͱ� 0�� ��
			strcpy(p[0].name, input_data); //p1.name�� �Է¹��� ������ ����.
		if (num == 1) //���� �Է¹��� ����� �����Ͱ� 1�� �� (�̹� �Ѹ� �޾�����)
			strcpy(p[1].name, input_data);//p2.name�� �Է¹��� ������ ����.

		printf("\n��ȭ��ȣ : "); //�̸��� ������ �޾����� ��ȭ��ȣ�� �޾ƾ���
		scanf("%s", input_data);

		if (!(strcmp(input_data, p[0].phonenum))) {//���� �Է� ������ p1�� ��ȭ��ȣ�� ���ٸ�?
												 //( p1�� ���� �Է� ���ߴ��� p1.phonenum�� �ƹ��͵� �����״� ���ǹ� ������ �����ǰ�������
			printf("==������ �Է�==\n");
			printf("�����Ͱ� �ߺ��Ǿ����ϴ�.\n");
			continue; //�ٽ� ó������ ���ư��� �̸����� ��������
		}//���� ó��
		if (num == 0) { //���� �Է¹��� ����� �����Ͱ� 0�� ��
			strcpy(p[0].phonenum, input_data);//p1.phonenum�� �Է¹��� ������ ����.
			num = num + 1; //���� p1�� �̸��� ��ȭ��ȣ�� ��� �ԷµǾ�����  num 1����
			continue; //ó�����ΰ�
		}
		if (num == 1) {		//���� �Է¹��� ����� �����Ͱ� 0�� ��
			strcpy(p[1].phonenum, input_data); //p2.phonenum�� �Է¹��� ������ ����.
			num += 1;
			break; //p1,p2��� ���������� �Է�. �ݺ� �� loopŻ��
		}
	}
	while (1) {
		printf("�߰��Է� 0  ���� 1 : ");
		scanf("%d", &menu);
		if (menu ==1) break;
		else if (menu == 0)
		{
			size += 1;
			p = (phone*)realloc(p, sizeof(phone)*size);
			if (p == NULL)
				exit(1);
			while (1) {
				printf("\n�̸� : ");
				scanf("%s", input_data); //�̸� �Է¹���
				
				if (strlen(input_data) > 15) {
					printf("==������ �Է�==\n");
					printf("�Է� ������ ���� ���� �ʰ�\n");
					continue; //�ٽ� �ݺ��� ó������~!
				}
				strcpy(p[num].name, input_data);
				printf("\n��ȭ��ȣ : "); //�̸��� ������ �޾����� ��ȭ��ȣ�� �޾ƾ���
				scanf("%s", input_data);
				if (!(strcmp(input_data, p[num-1].phonenum))) {//���� �Է� ������ ������ ��ȭ��ȣ�� ���ٸ�?
					printf("==������ �Է�==\n");
					printf("�����Ͱ� �ߺ��Ǿ����ϴ�.\n");
					continue; //�ٽ� ó������ ���ư��� �̸����� ��������
				}//���� ó��
				strcpy(p[num].phonenum, input_data);
				num += 1;
				break;
			}
		}
	}
	printf("\n\n ==��ȭ��ȣ�� ==\n"); //���
	for(int i=0;i<size;i++)
		printf("%s   %s\n", p[i].name, p[i].phonenum);
	printf("================\n");
	free(p);	
}