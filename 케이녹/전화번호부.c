#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
 typedef struct phone {
    char name[15];
    char phonenum[20];
} phone;

 void main() {
    phone p1; //ù��° ����� �����͸� �����ϴ� ����ü ����
    phone p2; //�ι�° ����� �����͸� �����ϴ� ����ü ����
    char input_data[30]; //����ڰ� �Է��� ���ڿ��� �����ϴ� ������
	int num=0; //���� ���α׷��� ����� �����͸� �Է¹޾Ҵ��� ������ ����
   //while loop������ �����غý��ϴ� �� ȿ������ ��� �����غ�����!
	while (1) {
		printf("\n�̸� : ");
		scanf("%s", input_data) ; //�̸� �Է¹���

		if (strlen(input_data) > 15) { 
			printf("==������ �Է�==\n");
			printf("�Է� ������ ���� ���� �ʰ�\n");
			continue; //�ٽ� �ݺ��� ó������~!
		}//���� ó�� (���ڼ� �ʰ�

		if (num == 0) //���� �Է¹��� ����� �����Ͱ� 0�� ��
			strcpy(p1.name, input_data); //p1.name�� �Է¹��� ������ ����.

		if (num == 1) //���� �Է¹��� ����� �����Ͱ� 1�� �� (�̹� �Ѹ� �޾�����)
			strcpy(p2.name ,input_data);//p2.name�� �Է¹��� ������ ����.

		printf("\n��ȭ��ȣ : "); //�̸��� ������ �޾����� ��ȭ��ȣ�� �޾ƾ���
		scanf("%s", input_data);

		if (!(strcmp(input_data, p1.phonenum))) {//���� �Է� ������ p1�� ��ȭ��ȣ�� ���ٸ�?
												//( p1�� ���� �Է� ���ߴ��� p1.phonenum�� �ƹ��͵� �����״� ���ǹ� ������ �����ǰ�������
			printf("==������ �Է�==\n");
			printf("�����Ͱ� �ߺ��Ǿ����ϴ�.\n");
			continue; //�ٽ� ó������ ���ư��� �̸����� ��������
		}//���� ó��
		if (num == 0) { //���� �Է¹��� ����� �����Ͱ� 0�� ��
			strcpy(p1.phonenum , input_data);//p1.phonenum�� �Է¹��� ������ ����.
			num=num + 1; //���� p1�� �̸��� ��ȭ��ȣ�� ��� �ԷµǾ�����  num 1����
			continue; //ó�����ΰ�
		}	
		if (num == 1) {		//���� �Է¹��� ����� �����Ͱ� 0�� ��
			strcpy(p2.phonenum , input_data); //p2.phonenum�� �Է¹��� ������ ����.
			break; //p1,p2��� ���������� �Է�. �ݺ� �� loopŻ��
		}
	}
	printf("\n\n ==��ȭ��ȣ�� ==\n"); //���
	printf("%s \t%s\n\n", p1.name, p1.phonenum);
	printf("%s \t%s\n", p2.name, p2.phonenum);
}