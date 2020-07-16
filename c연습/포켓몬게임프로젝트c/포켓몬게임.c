#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<windows.h>


typedef struct Pokemon {
	char name[20];
	char nickname[20];
	char type[10];
	int hp;
	int power;
	int min_hp;
	int min_power;
	int max_hp;
	// �̸�, ����, Ÿ��, ü��, ���ݷ�,�ּ�ü��,�ּҰ��ݷ�,�ִ�ü�� ���� ������ �ִ� ���ϸ� ����ü
} Pokemon;

typedef struct mylist_Pokemon {
	Pokemon p[6];
	int length;
}mylist_Pokemon;

typedef struct Bag {
	int monsterball;
	int potion;
	int cash;
}Bag; //���ͺ�,����,�� ���� �������ִ� ���� ����ü

Pokemon* p_list;
mylist_Pokemon my_list; //���� ���� ���ϸ󸮽�Ʈ
Bag my_bag;
Pokemon *a; //�߻������ϸ�
Pokemon *b; //�� �������� ���ϸ� 
int po_num;

void clearBuffer() { //���� ���� �Լ�
	while (getchar() != '\n');
}
void menu_1() {
	printf("===================================\n");
	printf("\t   ���ϸ���\n");
	printf("     press enter key to start\n");
	printf("===================================\n");
	getchar();
}

int menu_2() {
	int choice;
	printf("===================================\n");
	printf("��� ���ϸ��� ���ðڽ��ϱ�?\n\n");
	printf("1. ���̸�  2. �̻��ؾ�  3. ���α�\n>>");
	while (1) {
		scanf("%d", &choice);
		if (choice <= 0 || choice > 3)
			printf("1,2,3 �߿��� �����Ͻÿ�\n>>");
		else break;
	}
	return choice;
}
void menu_3(int choice, Pokemon *pokemon) {
	switch (choice) { //����� ���ÿ� ���� �� ��Ʈ�����ϸ� �ʱ�ȭ
	case 1:
		strcpy(pokemon->name, "���̸�");
		strcpy(pokemon->type, "��");
		break;
	case 2:
		strcpy(pokemon->name, "�̻��ؾ�");
		strcpy(pokemon->type, "Ǯ");
		break;
	case 3:
		strcpy(pokemon->name, "���α�");
		strcpy(pokemon->type, "��");
		break;
	}
	printf("���ϸ��� ������ �Է��ϼ���>>> ");
	scanf("%s", pokemon->nickname);
	srand((unsigned int)time(NULL));
	pokemon->hp = rand() % 501 + 500;// ü���� 500~1000 ���̷�, ���ݷ��� 100~150
	pokemon->power = rand() % 51 + 100;
	pokemon->max_hp = pokemon->hp;
}

int menu_4() {
	int option;
	printf("\n===================================\n");
	printf("    ������ �����ðڽ��ϱ�?\n\n");
	printf("1. ��  2. �ƴϿ� 3. ���� ���� (���ͺ��� ȸ�� ���� ���)\n>>");
	scanf("%d", &option);
	if (option == 1 || option ==3) //5�� or ����
		return option;
	else exit(1); //������ �Է½� ���α׷� ����
	
}
Pokemon* menu_5() {
	printf("\n======================\n");
	printf("  ���� �ȴ���......\n");

	int num = rand() %3001;
	Sleep(num);

	int ran_num= rand() % (po_num-2) + 0;
	a = (Pokemon*)malloc(sizeof(Pokemon)); //�߻������ϸ� �����Ҵ�
	a= &p_list[ran_num];
	a->power = rand() % (201 - a->min_power) + a->min_power;
	a->hp = rand() % (1201 - a->min_hp) + a->min_hp; //�Ҷ����� hp,power�ٲ���
	a->max_hp = a->hp;
	printf("�߻����ϸ� �Ѹ����� ��Ÿ�����ϴ�.\n%s\n%s\n%d\n%d\n", a->name, a->type, a->power, a->hp);
	return a;
}

int menu_6() {
	int choice;
	printf("=============================\n");
	printf("���� �� ���ϸ��� ü�� : %d/%d\n",b->hp,b->max_hp);
	printf("���� �߻� ���ϸ��� ü�� : %d/%d\n",a->hp,a->max_hp);
	
	while (1) {
		printf("==============================\n");
		printf("1. ���� 2. ����ġ�� 3.���� ����\n>>");
		scanf("%d", &choice);
		if (choice == 3) {
			if (my_bag.monsterball == 0 && my_bag.potion == 0) {
				printf("������ ����ֽ��ϴ�.\n");
				continue;
			}
		}
			return choice;
	}
}

int menu_6_1() {
	int motion=1;
	printf("====================\n");
	printf("���� �� ! \n");
	printf("�����ߴ�!\n");
	if (strcmp(b->type, "��") == 0)
	{
		if (strcmp(a->type, "��") == 0) {
			printf("ȿ���� ������ �� �ϴ�.\n");
			a->hp -= (int)((b->power)*0.5);
		}
		if (strcmp(a->type, "��") == 0) {
			a->hp -= b->power;
		}
		if (strcmp(a->type, "Ǯ") == 0) {
			printf("ȿ���� �����ߴ�!\n");
			a->hp -= (int)((b->power)*1.5);
		}
	}
	if (strcmp(b->type, "��") == 0)
	{
		if (strcmp(a->type, "Ǯ") == 0) {
			printf("ȿ���� ������ �� �ϴ�.\n");
			a->hp -= (int)((b->power)*0.5);
		}
		if (strcmp(a->type, "��") == 0) {
			a->hp -= b->power;
		}
		if (strcmp(a->type, "��") == 0) {
			printf("ȿ���� �����ߴ�!\n");
			a->hp -= (int)((b->power)*1.5);
		}
	}
	if (strcmp(b->type, "Ǯ") == 0)
	{
		if (strcmp(a->type, "��") == 0) {
			printf("ȿ���� ������ �� �ϴ�.\n");
			a->hp -= (int)((b->power)*0.5);
		}
		if (strcmp(a->type, "Ǯ") == 0) {
			a->hp -= b->power;
		}
		if (strcmp(a->type, "��") == 0) {
			printf("ȿ���� �����ߴ�!\n");
			a->hp -= (int)((b->power)*1.5);
		}
	}

	printf("=======================\n");
	printf("���� �� ���ϸ��� ü�� : %d/%d\n", b->hp, b->max_hp);
	printf("���� �߻� ���ϸ��� ü�� : %d/%d\n", a->hp, a->max_hp);

	if (a->hp < 0) {
		printf("���ϸ��� ����Ʈ�ȴ�!\n");
		motion = 4;
	}
	if (a->hp == 0) {
		printf("��! ���ϸ��� ���������ȴ�....");
		motion = 4;
	}
	return motion; //hp<=�̸�motion 4 �ƴϸ� �״�� 1 
}
int menu_6_3() {
	int choice;
	printf("====================\n");
	printf("1. ���� ��    x %d\n", my_bag.monsterball);
	printf("2. ȸ�� ����    x %d\n", my_bag.potion);
	printf("� �������� ����Ͻðڽ��ϱ� ? :\n>>");
	scanf("%d", &choice);
	return choice;
}

int menu_6_2() {
	int run,motion=0;
	printf("===================\n");
	printf("������ �ĺ���\n");
	if (a->hp == a->max_hp) {
		run= rand () % 101 ;
		if (run <= 10)
			motion = 1; //��������
	}
	else if (a->hp >= (int)((a->max_hp)*0.5)) {
		run = rand() % 101;
		if (run <= 40)
			motion = 1; //��������
	}
	else if (a->hp >= (int)((a->max_hp)*0.25)) {
		run = rand() % 101;
		if (run <= 70)
			motion = 1; //��������
	}
	else {
		run = rand() % 101;
		if (run <= 90)
			motion = 1; //��������
	}
	if (motion == 0)
		printf("�������⿡ �����Ͽ���!\n");
	if (motion == 1)
		printf("�������⿡ �����Ͽ���!\n");
	return motion;
}

int menu_6_3_1() {
	int motion = 0; int catch,do_replay=0;
	char yes_no;
	if (my_bag.monsterball <= 0) {
		printf("���ͺ��� �����ϴ�.\n���� �����մϴ�.\n");
		return do_replay;
	}
	else {
		printf("����!���ͺ�!!!!\n");
		my_bag.monsterball -= 1;
		clearBuffer();
		getchar();
		if (a->hp >= (int)((a->max_hp)*0.5)) {
			printf("ü���� �� ����ּ���..\n���� �����մϴ�.\n");
			return do_replay;
		}
		else if (a->hp >= (int)((a->max_hp)*0.3)) {
			 catch= rand() % 101;
			if (catch <= 30)
				motion = 1; //����� ���
		}
		else if (a->hp >= (int)((a->max_hp)*0.1)) {
			catch = rand() % 101;
			if (catch <= 60)
				motion = 1; //����� ���
		}
		else{
			catch = rand() % 101;
			if (catch <= 90)
				motion = 1; //����� ���
		}
	}
	//����� ��� ó�� �������� motion �״�� 0
	if (motion == 0) {
		printf("���ϸ��� ���ͺ��� �������Դ�!\n");
		return do_replay;
	}
	if (motion == 1) {
		printf("���ϸ��� ��Ҵ�!\n");
		my_list.p[my_list.length].max_hp = a->max_hp;
		my_list.p[my_list.length].hp = a->hp;
		my_list.p[my_list.length].power = a->power;
		strcpy(my_list.p[my_list.length].name, a->name);
		strcpy(my_list.p[my_list.length].type, a->type);
		clearBuffer();
		printf("�̸��� �Է����ּ���\n>>");
		scanf("%s", my_list.p[my_list.length].nickname);

		my_list.length += 1;
		if (my_list.length < 6)
			do_replay = 2;
		
	}

	if (my_list.length == 6) {
		printf("�� ���� ���ž�!\n");
		printf("������ �� ��������?(Y/N)");
		clearBuffer();
		scanf("%c", &yes_no);

		if (yes_no == 'Y')
		{
			do_replay = 1;
			my_list.length = 0; //�����ϸ󸮽�Ʈ���� 0����
		}
		else
			exit(1);
	}

	return do_replay;
}

void menu_6_3_2() {
	if (my_bag.potion <= 0)
		printf("ȸ�� ������ �����ϴ�.\n���������մϴ�.\n");
	if (my_bag.potion > 0) {
		printf("ȸ������ �� ���� ����մϴ�.\n");
		b->hp =b->hp +  (int)((b->max_hp)*0.3);
		printf("ȸ�� �� ���ϸ��� ü�� : %d\n", b->hp);
		my_bag.potion -= 1;
	}
}

int hit_by_opponent() {
	int po_pick;
	int motion=1;
	printf("======================\n");
	printf("������ �� ! \n");
	printf("���ݹ޾Ҵ�!\n");
	if (strcmp(a->type,"��") == 0)
	{
		if (strcmp(b->type, "��") == 0) {
			printf("ȿ���� ������ �� �ϴ�.\n");
			b->hp -= (int)((a->power)*0.5);
		}
		if (strcmp(b->type, "��") == 0) {
			b->hp -= a->power;
		}
		if (strcmp(b->type, "Ǯ") == 0) {
			printf("ȿ���� �����ߴ�!\n");
			b->hp -= (int)((a->power)*1.5);
		}
	}
	if (strcmp(a->type, "��") == 0)
	{
		if (strcmp(b->type, "Ǯ") == 0) {
			printf("ȿ���� ������ �� �ϴ�.\n");
			b->hp -= (int)((a->power)*0.5);
		}
		if (strcmp(b->type, "��") == 0) {
			b->hp -= a->power;
		}
		if (strcmp(b->type, "��") == 0) {
			printf("ȿ���� �����ߴ�!\n");
			b->hp -= (int)((a->power)*1.5);
		}
	}
	if (strcmp(a->type, "Ǯ") == 0)
	{
		if (strcmp(b->type, "��") == 0) {
			printf("ȿ���� ������ �� �ϴ�.\n");
			b->hp -= (int)((a->power)*0.5);
		}
		if (strcmp(b->type, "Ǯ") == 0) {
			b->hp -= a->power;
		}
		if (strcmp(b->type, "��") == 0) {
			printf("ȿ���� �����ߴ�!\n");
			b->hp -= (int)((a->power)*1.5);
		}
	}
	
	if (b->hp <= 0) {
		b->hp = 0; //ü�� ��������� ������
		printf("�� ���ϸ��� ������ �ް� ��������....\n");
		printf("\n=========================\n");
		for (int i = 0; i < my_list.length; i++) {
			printf("%d. %s  %s   %d/%d\n", i + 1, my_list.p[i].name, my_list.p[i].type, my_list.p[i].hp, my_list.p[i].max_hp);
		}
		printf("\n��� ���ϸ��� �������ðڽ��ϱ�? (0 �Է½� ��������, ������ �ֵ��� ������ ���� �Է�) \n>>");
		while (1) {
			scanf("%d", &po_pick);
			if (po_pick > my_list.length)
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է��Ͻÿ�.\n>>");
			if (po_pick <= my_list.length)
				break;
		}

		if (po_pick == 0) {
			printf("������ �����մϴ�..\n");
			motion = 5;
			for (int i = 0; i < my_list.length; i++) {
				if (my_list.p[i].hp == 0)
					continue;
				b = &my_list.p[i];
			} //�����ϸ鼭 ü�� 0�̾ƴ� ���̸� ��ǥ ���ϸ����� �����ϰ�
			return motion;
		}

		if (po_pick < 0) { 
			printf("���� ����������...\n");
			printf("====================\n");
			printf("�����ϰ� ��� ��� ���ϸ��� ü���� ȸ���Ͽ����ϴ�.\n");
			for (int i = 0; i < my_list.length; i++) 
				my_list.p[i].hp = my_list.p[i].max_hp;
			b = &my_list.p[0]; //��ǥ����
			motion = 4;
			return motion;
		}

		b = &(my_list.p[po_pick - 1]);
		return motion;
	}

	return motion;
}

void store() { //���� �Լ�
	int option, buy_num;
	char yes_no;
	while (1) {
		printf("\n======================================\n");
		printf("\t\t\t���� ���� �ݾ� : %d\n", my_bag.cash);
		printf("\t1. ���ͺ�	1000\n");
		printf("\t2. ȸ������	2500\n\n");
		printf("\t� �������� ��ðڽ��ϱ�? :");
		scanf("%d", &option);
		if (option == 1) {
			printf("\n���ͺ��� �����Ͽ����ϴ�.\n");
			printf("�� ���� ����Դϱ�? >> ");
			scanf("%d", &buy_num);
			if (buy_num * 1000 > my_bag.cash)
			{
				printf("���� �����Ͽ� �� �� ����!\n");
				continue;
			}
			printf("���� �Ͻðڽ��ϱ�? Y/N���� ���Ͻÿ�.>>> ");
			clearBuffer();
			scanf("%c", &yes_no);
			if (yes_no == 'Y')
			{
				printf("���ͺ� %d���� ���������� �����Ͽ���!\n\n", buy_num);
				my_bag.cash -= buy_num * 1000;
				my_bag.monsterball = my_bag.monsterball + buy_num;
				printf("���� ������ �ִ� ���ͺ� : %d\n", my_bag.monsterball);
				continue;
			}
		}

		if (option == 2) {
			printf("\nȸ�� ������ �����Ͽ����ϴ�.\n");
			printf("�� ���� ����Դϱ�? >> ");
			scanf("%d", &buy_num);
			if (buy_num * 2500 >my_bag.cash)
			{
				printf("���� �����Ͽ� �� �� ����!\n");
				continue;
			}
			printf("���� �Ͻðڽ��ϱ�? Y/N���� ���Ͻÿ�.>>> ");
			clearBuffer();
			scanf("%c", &yes_no);
			if (yes_no == 'Y') {
				printf("ȸ������ %d���� ���������� �����Ͽ���!\n\n", buy_num);
				my_bag.cash -= buy_num * 2500;
				my_bag.potion = my_bag.potion + buy_num;
				printf("���� ������ �ִ� ȸ������ : %d\n", my_bag.potion);
				continue;
			}
			else {
				printf("���Ÿ� ����մϴ�.\n");
				continue;
			}
		}


		else if(option!=1 && option!=2) {
			printf("���Ÿ� �����մϴ�...\n");
			printf("���� ������ �ִ� ���ͺ� : %d\n", my_bag.monsterball);
			printf("���� ������ �ִ� ȸ������ : %d\n", my_bag.potion);
			printf("���� �ݾ� : %d\n\n", my_bag.cash);
			break;
		}
	}
}

// ���������� �� �־�� ���ڷ� ���� �ȳѱ��� �����غ���

int main() {
	int line_num;
	int motion, do_replay; //������ ���
	FILE *ofp = fopen("pokemon_list.txt", "r+");
	fscanf(ofp, "%d", &line_num); //��ù�ٰ������� �о���� �� ��
	po_num = line_num / 4;
	p_list = (Pokemon*)malloc((po_num) * sizeof(Pokemon));
	for(int i=0;i<po_num;i++){
			fscanf(ofp, "%s", p_list[i].name);
			fscanf(ofp, "%s", p_list[i].type);
			fscanf(ofp, "%d", &(p_list[i].min_power));
			fscanf(ofp, "%d", &(p_list[i].min_hp));
		}//�߻� ���ϸ� ����Ʈ����⼺��
	srand((unsigned int)time(NULL));
	Pokemon partner_pokemon;
	b = (Pokemon*)malloc(sizeof(Pokemon)); //�� ������ ���ϸ�
	
Replay:

	my_bag.cash = 10000;
	my_bag.monsterball = 0;
	my_bag.potion = 0;
	
	
	menu_1();
	int choice = menu_2();
	menu_3(choice, &partner_pokemon); //��Ʈ�����ϸ� ����ü p[6] �ȿ� �־��ְ� �����غ���
	printf("\n���� ���� ��Ʈ�� ���ϸ��� �����!\n\n���ϸ��� �� ����\n>>>>\n");
	printf("\n�̸� : %s\nŸ�� :%s\n���� : %s\n���ݷ� : %d\nü�� :%d", partner_pokemon.name, partner_pokemon.type, partner_pokemon.nickname, partner_pokemon.power, partner_pokemon.hp);
	my_list.p[0] = partner_pokemon; //�����ϸ� ����Ʈ�� �߰�
	my_list.length = 1; // 1 �߰�
	b = &my_list.p[0]; 
	
	while (1) {
		choice = menu_4();

		if (choice == 3)
			store();


		if (choice == 1)
		{
			menu_5();  //�߻����ϸ� ���� 6���ʿ��� menu5�ΰ����ϸ� �� �����ȵ��� �׾ȿ��� free�ϰ� menu_5�ٽ�ȣ���ϱ�
			while (1) {
				choice = menu_6();
				if (choice == 1) {
					motion = menu_6_1();
					if (motion == 4)
						break;			//����������� �� �־�� if aü�� <=0 break����
				}
				if (choice == 2){
					motion=menu_6_2();
					if (motion == 1)
						break;

			}
				if (choice == 3) {			//����
					motion = menu_6_3();

					if (motion == 1) {
					do_replay=menu_6_3_1();//���
					
					if (do_replay == 1) 
						goto Replay; //�ٽ� �����ϴ� goto�� (�����ѰŴϱ� 1���� ���Կ䤾)	
					if (do_replay == 2) //���ϸ��� ��������
						break;
				}
					if (motion == 2) {
						menu_6_3_2();//���ϸ�ȸ��
						
					}

				}
				clearBuffer();
				getchar();
				motion = hit_by_opponent();
				if (motion == 4) {
					break;
				}
					
				else if (motion == 5) {
					menu_5();
				}
			}

		}


		
		
	}

	free(p_list);
	free(a);
	free(b);
	fclose(ofp);
	return 0;
}

