#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
typedef struct phone {
	char name[15];
	char phonenum[20];
} phone;
void main() {    //ù���� �ι�°���� ���� �������غ��� ��������
	phone *p = (phone*)malloc(2 * sizeof(phone)); //2������ �Ҵ�
	char input_data[30]; //����ڰ� �Է��� ���ڿ��� �����ϴ� ������
	int size = 2; //�� ��� �����͸� �������� �����Һ��� 
	int num = 0; //���� ���α׷��� ����� �����͸� �Է¹޾Ҵ��� ������ ����
	int menu = 0; //�Է¸޴�
	FILE *ifp = fopen("phonebook.txt", "r+"); //ù�����̸� null�̴ϱ� ��������

	if (ifp != NULL) { //ù���� �ƴϸ� ���� r+���� �б�Ϸ�
		printf("�ڵ����� ����ó�� �����մϴ�\n");
		fscanf(ifp, "%d", &num);
		size = num; 
		p = (phone*)realloc(p, num * sizeof(phone));
		for (int i = 0; i < num; i++) 
			fscanf(ifp, "%s%s", p[i].name, p[i].phonenum); //����Ѱ� �ҷ����� �Ϸ�
	}
	if (ifp == NULL) { //ù�����
		while (1) {
			ifp = fopen("phonebook.txt", "w"); //w���� ���� ���ϻ�����
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
			}

			break; //p1,p2��� ���������� �Է�. �ݺ� �� loopŻ��
		}
		fprintf(ifp, "%d\n", size); //���Ͽ� ����
		for (int i = 0; i < size; i++)
			fprintf(ifp, "%s  %s\n", p[i].name, p[i].phonenum);
	}
	if (menu == 0)	{	//��������� menu=0�������� �ϴ� ������ ����
		while (1) {
			printf("�߰��Է� 0  ���� 1 : ");
			scanf("%d", &menu);		if (menu == 1) break;
			size += 1;
			p = (phone*)realloc(p, sizeof(phone)*size);
			while (1) {
				printf("\n�̸� : ");
				scanf("%s", input_data); //�̸� �Է¹���
				if (strlen(input_data) > 15) {
					printf("==������ �Է�==\n");
					printf("�Է� ������ ���� ���� �ʰ�\n");
					continue; //�ٽ� �ݺ��� ó������~!
				}
				strcpy(p[num].name, input_data); //�̸� �Է�
				printf("\n��ȭ��ȣ : "); //�̸��� ������ �޾����� ��ȭ��ȣ�� �޾ƾ���
				scanf("%s", input_data);

				if (!(strcmp(input_data, p[num - 1].phonenum))) {//���� �Է� ������ ������ ��ȭ��ȣ�� ���ٸ�?
					printf("==������ �Է�==\n");
					printf("�����Ͱ� �ߺ��Ǿ����ϴ�.\n");
					continue; //�ٽ� ó������ ���ư��� �̸����� ��������
				}//���� ó��
				strcpy(p[num].phonenum, input_data);
				num += 1; //num�� 1���س��� �� �ݺ��ҽ� �ٷ� �ε����γ���
				rewind(ifp);
				fprintf(ifp, "%d\n", size);
				for(int i=0;i<size;i++)
					fprintf(ifp, "%s  %s\n", p[i].name, p[i].phonenum);
				break;
			}
		}
	}
	printf("\n\n ==��ȭ��ȣ�� ==\n"); //���
	for (int i = 0; i<size; i++)
		printf("%s   %s\n", p[i].name, p[i].phonenum);
	printf("================\n");
	free(p);
	fclose(ifp);
}