#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct phone {
	char name[15];
	char phonenum[20];
} phone;

phone* user_data(phone *, int);

int main() {
	phone *p; //����ü ������ ����
	 //����ڰ� �Է��� ���ڿ��� �����ϴ� ������
	int i = 0;
	int size = 2;
	int menu=0;
	p = (phone*)calloc( size, sizeof(phone*));// �ּ� 2���Է�

	for (i = 0; i < size; i++) {
		user_data(p	, i);
	}
	while (!menu) {
		printf("\n�߰��Է� 0, ���� 1\t");
		scanf("%d", &menu);
		if(menu==0){
			size += 1;
			p = (phone*)realloc(p, size);
			user_data(p, size-1);
		}
		else continue;
	}
	printf("\n\n ==��ȭ��ȣ�� ==\n\n"); //���
	for (i = 0; i < size; i++) {
		printf("%s\t%s\n", p[i].name, p[i].phonenum);
	}printf("\n=================");
	free(p);
	return 0;
}


phone* user_data(phone *p, int i) {
	char input_name[30];
	char input_phonenum[30];
	while (1) {
		printf("�̸� : ");
		scanf("%s", input_name); //�̸� �Է¹���

		if (strlen(input_name) > 15) {
			printf("==������ �Է�==\n");
			printf("�Է� ������ ���� ���� �ʰ�\n");
			continue; //�ٽ� �ݺ��� ó������~!
		}//���� ó�� (���ڼ� �ʰ�
		if (!(strcmp("", p[i].name)))
			strcpy(p[i].name, input_name);

		//�̰͵������� �ؿ��� �ߺ��߸� �����ù�
		printf("\n��ȭ��ȣ : "); //�̸��� ������ �޾����� ��ȭ��ȣ�� �޾ƾ���
		getchar();
		scanf("%s", input_phonenum);

		if (i != 0) {
			if (!(strcmp(input_phonenum, p[i - 1].phonenum))) {//���� �Է� ������ p1�� ��ȭ��ȣ�� ���ٸ�?
				printf("==������ �Է�==\n");
				printf("�����Ͱ� �ߺ��Ǿ����ϴ�.\n");
				continue; //�ٽ� ó������ ���ư��� �̸����� ��������
			}//���� ó��
		}

		
			strcpy(p[i].phonenum, input_phonenum);//p1.phonenum�� �Է¹��� ������ ����.
			break; 		

	}
	

}
