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
	// 이름, 별명, 타입, 체력, 공격력,최소체력,최소공격력,최대체력 변수 가지고 있는 포켓몬 구조체
} Pokemon;

typedef struct mylist_Pokemon {
	Pokemon p[6];
	int length;
}mylist_Pokemon;

typedef struct Bag {
	int monsterball;
	int potion;
	int cash;
}Bag; //몬스터볼,포션,돈 변수 가지고있는 가방 구조체

Pokemon* p_list;
mylist_Pokemon my_list; //내가 잡은 포켓몬리스트
Bag my_bag;
Pokemon *a; //야생의포켓몬
Pokemon *b; //내 전투중인 포켓몬 
int po_num;

void clearBuffer() { //버퍼 비우는 함수
	while (getchar() != '\n');
}
void menu_1() {
	printf("===================================\n");
	printf("\t   포켓몬스터\n");
	printf("     press enter key to start\n");
	printf("===================================\n");
	getchar();
}

int menu_2() {
	int choice;
	printf("===================================\n");
	printf("어느 포켓몬을 고르시겠습니까?\n\n");
	printf("1. 파이리  2. 이상해씨  3. 꼬부기\n>>");
	while (1) {
		scanf("%d", &choice);
		if (choice <= 0 || choice > 3)
			printf("1,2,3 중에만 선택하시오\n>>");
		else break;
	}
	return choice;
}
void menu_3(int choice, Pokemon *pokemon) {
	switch (choice) { //사용자 선택에 따른 내 파트너포켓몬 초기화
	case 1:
		strcpy(pokemon->name, "파이리");
		strcpy(pokemon->type, "불");
		break;
	case 2:
		strcpy(pokemon->name, "이상해씨");
		strcpy(pokemon->type, "풀");
		break;
	case 3:
		strcpy(pokemon->name, "꼬부기");
		strcpy(pokemon->type, "물");
		break;
	}
	printf("포켓몬의 별명을 입력하세요>>> ");
	scanf("%s", pokemon->nickname);
	srand((unsigned int)time(NULL));
	pokemon->hp = rand() % 501 + 500;// 체력은 500~1000 사이로, 공격력은 100~150
	pokemon->power = rand() % 51 + 100;
	pokemon->max_hp = pokemon->hp;
}

int menu_4() {
	int option;
	printf("\n===================================\n");
	printf("    여행을 떠나시겠습니까?\n\n");
	printf("1. 네  2. 아니오 3. 상점 가기 (몬스터볼과 회복 물약 사기)\n>>");
	scanf("%d", &option);
	if (option == 1 || option ==3) //5번 or 상점
		return option;
	else exit(1); //나머지 입력시 프로그램 종료
	
}
Pokemon* menu_5() {
	printf("\n======================\n");
	printf("  길을 걷는중......\n");

	int num = rand() %3001;
	Sleep(num);

	int ran_num= rand() % (po_num-2) + 0;
	a = (Pokemon*)malloc(sizeof(Pokemon)); //야생의포켓몬 동적할당
	a= &p_list[ran_num];
	a->power = rand() % (201 - a->min_power) + a->min_power;
	a->hp = rand() % (1201 - a->min_hp) + a->min_hp; //할때마다 hp,power바꿔줌
	a->max_hp = a->hp;
	printf("야생포켓몬 한마리가 나타났습니다.\n%s\n%s\n%d\n%d\n", a->name, a->type, a->power, a->hp);
	return a;
}

int menu_6() {
	int choice;
	printf("=============================\n");
	printf("현재 내 포켓몬의 체력 : %d/%d\n",b->hp,b->max_hp);
	printf("현재 야생 포켓몬의 체력 : %d/%d\n",a->hp,a->max_hp);
	
	while (1) {
		printf("==============================\n");
		printf("1. 공격 2. 도망치기 3.가방 열기\n>>");
		scanf("%d", &choice);
		if (choice == 3) {
			if (my_bag.monsterball == 0 && my_bag.potion == 0) {
				printf("가방이 비어있습니다.\n");
				continue;
			}
		}
			return choice;
	}
}

int menu_6_1() {
	int motion=1;
	printf("====================\n");
	printf("나의 턴 ! \n");
	printf("공격했다!\n");
	if (strcmp(b->type, "불") == 0)
	{
		if (strcmp(a->type, "물") == 0) {
			printf("효과가 별로인 듯 하다.\n");
			a->hp -= (int)((b->power)*0.5);
		}
		if (strcmp(a->type, "불") == 0) {
			a->hp -= b->power;
		}
		if (strcmp(a->type, "풀") == 0) {
			printf("효과는 굉장했다!\n");
			a->hp -= (int)((b->power)*1.5);
		}
	}
	if (strcmp(b->type, "물") == 0)
	{
		if (strcmp(a->type, "풀") == 0) {
			printf("효과가 별로인 듯 하다.\n");
			a->hp -= (int)((b->power)*0.5);
		}
		if (strcmp(a->type, "물") == 0) {
			a->hp -= b->power;
		}
		if (strcmp(a->type, "불") == 0) {
			printf("효과는 굉장했다!\n");
			a->hp -= (int)((b->power)*1.5);
		}
	}
	if (strcmp(b->type, "풀") == 0)
	{
		if (strcmp(a->type, "불") == 0) {
			printf("효과가 별로인 듯 하다.\n");
			a->hp -= (int)((b->power)*0.5);
		}
		if (strcmp(a->type, "풀") == 0) {
			a->hp -= b->power;
		}
		if (strcmp(a->type, "물") == 0) {
			printf("효과는 굉장했다!\n");
			a->hp -= (int)((b->power)*1.5);
		}
	}

	printf("=======================\n");
	printf("현재 내 포켓몬의 체력 : %d/%d\n", b->hp, b->max_hp);
	printf("현재 야생 포켓몬의 체력 : %d/%d\n", a->hp, a->max_hp);

	if (a->hp < 0) {
		printf("포켓몬을 쓰려트렸다!\n");
		motion = 4;
	}
	if (a->hp == 0) {
		printf("앗! 포켓몬이 도망가버렸다....");
		motion = 4;
	}
	return motion; //hp<=이면motion 4 아니면 그대로 1 
}
int menu_6_3() {
	int choice;
	printf("====================\n");
	printf("1. 몬스터 볼    x %d\n", my_bag.monsterball);
	printf("2. 회복 물약    x %d\n", my_bag.potion);
	printf("어떤 아이템을 사용하시겠습니까 ? :\n>>");
	scanf("%d", &choice);
	return choice;
}

int menu_6_2() {
	int run,motion=0;
	printf("===================\n");
	printf("도망을 쳐보자\n");
	if (a->hp == a->max_hp) {
		run= rand () % 101 ;
		if (run <= 10)
			motion = 1; //도망성공
	}
	else if (a->hp >= (int)((a->max_hp)*0.5)) {
		run = rand() % 101;
		if (run <= 40)
			motion = 1; //도망성공
	}
	else if (a->hp >= (int)((a->max_hp)*0.25)) {
		run = rand() % 101;
		if (run <= 70)
			motion = 1; //도망성공
	}
	else {
		run = rand() % 101;
		if (run <= 90)
			motion = 1; //도망성공
	}
	if (motion == 0)
		printf("도망가기에 실패하였다!\n");
	if (motion == 1)
		printf("도망가기에 성공하였다!\n");
	return motion;
}

int menu_6_3_1() {
	int motion = 0; int catch,do_replay=0;
	char yes_no;
	if (my_bag.monsterball <= 0) {
		printf("몬스터볼이 없습니다.\n턴을 종료합니다.\n");
		return do_replay;
	}
	else {
		printf("가랏!몬스터볼!!!!\n");
		my_bag.monsterball -= 1;
		clearBuffer();
		getchar();
		if (a->hp >= (int)((a->max_hp)*0.5)) {
			printf("체력을 더 깎아주세요..\n턴을 종료합니다.\n");
			return do_replay;
		}
		else if (a->hp >= (int)((a->max_hp)*0.3)) {
			 catch= rand() % 101;
			if (catch <= 30)
				motion = 1; //잡았을 경우
		}
		else if (a->hp >= (int)((a->max_hp)*0.1)) {
			catch = rand() % 101;
			if (catch <= 60)
				motion = 1; //잡았을 경우
		}
		else{
			catch = rand() % 101;
			if (catch <= 90)
				motion = 1; //잡았을 경우
		}
	}
	//잡았을 경우 처리 못잡으면 motion 그대로 0
	if (motion == 0) {
		printf("포켓몬이 몬스터볼을 빠져나왔다!\n");
		return do_replay;
	}
	if (motion == 1) {
		printf("포켓몬을 잡았다!\n");
		my_list.p[my_list.length].max_hp = a->max_hp;
		my_list.p[my_list.length].hp = a->hp;
		my_list.p[my_list.length].power = a->power;
		strcpy(my_list.p[my_list.length].name, a->name);
		strcpy(my_list.p[my_list.length].type, a->type);
		clearBuffer();
		printf("이름을 입력해주세요\n>>");
		scanf("%s", my_list.p[my_list.length].nickname);

		my_list.length += 1;
		if (my_list.length < 6)
			do_replay = 2;
		
	}

	if (my_list.length == 6) {
		printf("넌 이제 내거야!\n");
		printf("여행을 더 떠나볼까?(Y/N)");
		clearBuffer();
		scanf("%c", &yes_no);

		if (yes_no == 'Y')
		{
			do_replay = 1;
			my_list.length = 0; //내포켓몬리스트길이 0으로
		}
		else
			exit(1);
	}

	return do_replay;
}

void menu_6_3_2() {
	if (my_bag.potion <= 0)
		printf("회복 물약이 없습니다.\n턴을종료합니다.\n");
	if (my_bag.potion > 0) {
		printf("회복물약 한 개를 사용합니다.\n");
		b->hp =b->hp +  (int)((b->max_hp)*0.3);
		printf("회복 후 포켓몬의 체력 : %d\n", b->hp);
		my_bag.potion -= 1;
	}
}

int hit_by_opponent() {
	int po_pick;
	int motion=1;
	printf("======================\n");
	printf("상대방의 턴 ! \n");
	printf("공격받았다!\n");
	if (strcmp(a->type,"불") == 0)
	{
		if (strcmp(b->type, "물") == 0) {
			printf("효과가 별로인 듯 하다.\n");
			b->hp -= (int)((a->power)*0.5);
		}
		if (strcmp(b->type, "불") == 0) {
			b->hp -= a->power;
		}
		if (strcmp(b->type, "풀") == 0) {
			printf("효과는 굉장했다!\n");
			b->hp -= (int)((a->power)*1.5);
		}
	}
	if (strcmp(a->type, "물") == 0)
	{
		if (strcmp(b->type, "풀") == 0) {
			printf("효과가 별로인 듯 하다.\n");
			b->hp -= (int)((a->power)*0.5);
		}
		if (strcmp(b->type, "물") == 0) {
			b->hp -= a->power;
		}
		if (strcmp(b->type, "불") == 0) {
			printf("효과는 굉장했다!\n");
			b->hp -= (int)((a->power)*1.5);
		}
	}
	if (strcmp(a->type, "풀") == 0)
	{
		if (strcmp(b->type, "불") == 0) {
			printf("효과가 별로인 듯 하다.\n");
			b->hp -= (int)((a->power)*0.5);
		}
		if (strcmp(b->type, "풀") == 0) {
			b->hp -= a->power;
		}
		if (strcmp(b->type, "물") == 0) {
			printf("효과는 굉장했다!\n");
			b->hp -= (int)((a->power)*1.5);
		}
	}
	
	if (b->hp <= 0) {
		b->hp = 0; //체력 음수만들순 없으니
		printf("내 포켓몬이 공격을 받고 쓰러졌다....\n");
		printf("\n=========================\n");
		for (int i = 0; i < my_list.length; i++) {
			printf("%d. %s  %s   %d/%d\n", i + 1, my_list.p[i].name, my_list.p[i].type, my_list.p[i].hp, my_list.p[i].max_hp);
		}
		printf("\n어느 포켓몬을 내보내시겠습니까? (0 입력시 전투포기, 내보낼 애들이 없으면 음수 입력) \n>>");
		while (1) {
			scanf("%d", &po_pick);
			if (po_pick > my_list.length)
				printf("잘못된 입력입니다. 다시 입력하시오.\n>>");
			if (po_pick <= my_list.length)
				break;
		}

		if (po_pick == 0) {
			printf("전투를 포기합니다..\n");
			motion = 5;
			for (int i = 0; i < my_list.length; i++) {
				if (my_list.p[i].hp == 0)
					continue;
				b = &my_list.p[i];
			} //포기하면서 체력 0이아닌 아이를 대표 포켓몬으로 지정하고
			return motion;
		}

		if (po_pick < 0) { 
			printf("눈이 깜깜해졌다...\n");
			printf("====================\n");
			printf("보유하고 계신 모든 포켓몬이 체력을 회복하였습니다.\n");
			for (int i = 0; i < my_list.length; i++) 
				my_list.p[i].hp = my_list.p[i].max_hp;
			b = &my_list.p[0]; //대표지정
			motion = 4;
			return motion;
		}

		b = &(my_list.p[po_pick - 1]);
		return motion;
	}

	return motion;
}

void store() { //상점 함수
	int option, buy_num;
	char yes_no;
	while (1) {
		printf("\n======================================\n");
		printf("\t\t\t현재 소유 금액 : %d\n", my_bag.cash);
		printf("\t1. 몬스터볼	1000\n");
		printf("\t2. 회복물약	2500\n\n");
		printf("\t어떤 아이템을 사시겠습니까? :");
		scanf("%d", &option);
		if (option == 1) {
			printf("\n몬스터볼을 선택하였습니다.\n");
			printf("몇 개를 살것입니까? >> ");
			scanf("%d", &buy_num);
			if (buy_num * 1000 > my_bag.cash)
			{
				printf("돈이 부족하여 살 수 없다!\n");
				continue;
			}
			printf("구매 하시겠습니까? Y/N으로 답하시오.>>> ");
			clearBuffer();
			scanf("%c", &yes_no);
			if (yes_no == 'Y')
			{
				printf("몬스터볼 %d개를 성공적으로 구매하였다!\n\n", buy_num);
				my_bag.cash -= buy_num * 1000;
				my_bag.monsterball = my_bag.monsterball + buy_num;
				printf("현재 가지고 있는 몬스터볼 : %d\n", my_bag.monsterball);
				continue;
			}
		}

		if (option == 2) {
			printf("\n회복 물약을 선택하였습니다.\n");
			printf("몇 개를 살것입니까? >> ");
			scanf("%d", &buy_num);
			if (buy_num * 2500 >my_bag.cash)
			{
				printf("돈이 부족하여 살 수 없다!\n");
				continue;
			}
			printf("구매 하시겠습니까? Y/N으로 답하시오.>>> ");
			clearBuffer();
			scanf("%c", &yes_no);
			if (yes_no == 'Y') {
				printf("회복물약 %d개를 성공적으로 구매하였다!\n\n", buy_num);
				my_bag.cash -= buy_num * 2500;
				my_bag.potion = my_bag.potion + buy_num;
				printf("현재 가지고 있는 회복물약 : %d\n", my_bag.potion);
				continue;
			}
			else {
				printf("구매를 취소합니다.\n");
				continue;
			}
		}


		else if(option!=1 && option!=2) {
			printf("구매를 종료합니다...\n");
			printf("현재 가지고 있는 몬스터볼 : %d\n", my_bag.monsterball);
			printf("현재 가지고 있는 회복물약 : %d\n", my_bag.potion);
			printf("소유 금액 : %d\n\n", my_bag.cash);
			break;
		}
	}
}

// 전역변수로 뭘 넣어야 인자로 굳이 안넘길지 생각해보자

int main() {
	int line_num;
	int motion, do_replay; //전투중 사용
	FILE *ofp = fopen("pokemon_list.txt", "r+");
	fscanf(ofp, "%d", &line_num); //맨첫줄가져오기 읽어야할 줄 수
	po_num = line_num / 4;
	p_list = (Pokemon*)malloc((po_num) * sizeof(Pokemon));
	for(int i=0;i<po_num;i++){
			fscanf(ofp, "%s", p_list[i].name);
			fscanf(ofp, "%s", p_list[i].type);
			fscanf(ofp, "%d", &(p_list[i].min_power));
			fscanf(ofp, "%d", &(p_list[i].min_hp));
		}//야생 포켓몬 리스트만들기성공
	srand((unsigned int)time(NULL));
	Pokemon partner_pokemon;
	b = (Pokemon*)malloc(sizeof(Pokemon)); //내 전투용 포켓몬
	
Replay:

	my_bag.cash = 10000;
	my_bag.monsterball = 0;
	my_bag.potion = 0;
	
	
	menu_1();
	int choice = menu_2();
	menu_3(choice, &partner_pokemon); //파트너포켓몬 구조체 p[6] 안에 넣어주고 관리해보자
	printf("\n이제 나의 파트너 포켓몬이 생겼어!\n\n포켓몬의 의 정보\n>>>>\n");
	printf("\n이름 : %s\n타입 :%s\n별명 : %s\n공격력 : %d\n체력 :%d", partner_pokemon.name, partner_pokemon.type, partner_pokemon.nickname, partner_pokemon.power, partner_pokemon.hp);
	my_list.p[0] = partner_pokemon; //내포켓몬 리스트에 추가
	my_list.length = 1; // 1 추가
	b = &my_list.p[0]; 
	
	while (1) {
		choice = menu_4();

		if (choice == 3)
			store();


		if (choice == 1)
		{
			menu_5();  //야생포켓몬 생성 6번쪽에서 menu5로가라하면 걍 루프안돌고 그안에서 free하고 menu_5다시호출하기
			while (1) {
				choice = menu_6();
				if (choice == 1) {
					motion = menu_6_1();
					if (motion == 4)
						break;			//디ㅜ졌을경우랑 다 넣어보센 if a체력 <=0 break조져
				}
				if (choice == 2){
					motion=menu_6_2();
					if (motion == 1)
						break;

			}
				if (choice == 3) {			//가방
					motion = menu_6_3();

					if (motion == 1) {
					do_replay=menu_6_3_1();//잡기
					
					if (do_replay == 1) 
						goto Replay; //다시 시작하는 goto문 (조사한거니까 1번만 쓸게요ㅎ)	
					if (do_replay == 2) //포켓몬을 잡았을경우
						break;
				}
					if (motion == 2) {
						menu_6_3_2();//포켓몬회복
						
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

