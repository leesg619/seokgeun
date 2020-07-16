#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
typedef int num; //int자료형을 num으로데이터형이름변경
num add(num, num);
num mul(num, num);
num min(num, num);
num div(num, num);
num per(num, num);
int main(void) {
	char op;
	num n1, n2;

	num(*oper)(num, num); //이제oper사용가능
	oper = NULL;

	while (oper == NULL) {
		printf("\n계산연산\n");
		printf("n1 : n2\n");
		scanf("%d %c %d", &n1,&op, &n2);
	
		switch (op) {
		case '+': oper = add; break;
		case '*': oper = mul; break;
		case '-': oper = min; break;
		case '/': oper = div; break;
		case '%': oper = per; break;
		default:while (getchar() != '\n');//입력버퍼비워다시받아
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