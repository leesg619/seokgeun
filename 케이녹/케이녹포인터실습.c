#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef int num; //int�ڷ����� num���ε��������̸�����
num add(num, num);
num mul(num, num);
num min(num, num);
num div(num, num);
num per(num, num);
int main(void) {
	char op;
	num n1, n2;

	num(*oper)(num, num); //����oper��밡��
	oper = NULL;

	while (oper == NULL) {
		printf("\n��꿬��\n");
		printf("n1 : n2\n");
		scanf("%d %c %d", &n1,&op, &n2);
	
		switch (op) {
		case '+': oper = add; break;
		case '*': oper = mul; break;
		case '-': oper = min; break;
		case '/': oper = div; break;
		case '%': oper = per; break;
		default:while (getchar() != '\n');//�Է¹��ۺ���ٽù޾�
		}
	}
	printf("\nresult : %d\n",oper(n1,n2));
	return 0;
}
num add(num n1, num n2) { return n1 + n2; }
num mul(num n1, num n2) { return n1*n2; }
num min(num n1, num n2) { return n1-n2; }
num div(num n1, num n2) { return n1/n2; }
num per(num n1, num n2) { return n1%n2; }