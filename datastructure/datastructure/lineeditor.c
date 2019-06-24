 //201611830 이석근
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_CHAR_PER_LINE	512
#define MAX_NAME	256

typedef struct {
	char a[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode {
	element data;
	struct ListNode *link;
} ListNode;
typedef struct {
	ListNode *head;     
	int length;		
} ListType; //헤드

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node)
{
	if (*phead == NULL) {	
		new_node->link = NULL;
		*phead = new_node;
	}
	else if (p == NULL) { 
		new_node->link = *phead;
		*phead = new_node;
	}
	else {			
		new_node->link = p->link;
		p->link = new_node;
	}
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed)
{
	if (p == NULL)
		*phead = (*phead)->link;
	else
		p->link = removed->link;
	free(removed);
}

void init(ListType *list)
{
	if (list == NULL) return;
	list->length = 0;
	list->head = NULL;
}

ListNode *get_node_at(ListType *list, int pos)
{
	ListNode *tmp_node = list->head;
	if (pos < 0) return NULL;
	for (int i = 0; i<pos; i++)
		tmp_node = tmp_node->link;
	return tmp_node;
}

int get_length(ListType *list)
{
	return list->length;
}


void add(ListType *list, int position, element data)
{
	ListNode *p;
	if ((position >= 0) && (position <= list->length)) {
		ListNode*node = (ListNode *)malloc(sizeof(ListNode));
		if (node == NULL) {
			printf("메모리 할당에러");
			exit(1);
		}
		node->data = data;
		p = get_node_at(list, position - 1);
		insert_node(&(list->head), p, node);
		list->length++;
	}
}

void add_last(ListType *list, element data)
{
	add(list, get_length(list), data);
}

void add_first(ListType *list, element data)
{
	add(list, 0, data);
}

int is_empty(ListType *list)
{
	if (list->head == NULL) return 1;
	else return 0;
}

void delete(ListType *list, int pos)
{
	if (!is_empty(list) && (pos >= 0) && (pos < list->length)) {
		ListNode *p = get_node_at(list, pos - 1);
		remove_node(&(list->head), p, (p != NULL) ? p->link : NULL);
		list->length--;
	}
}

element get_entry(ListType *list, int pos)
{
	ListNode *p;
	if (pos >= list->length) {
		printf("위치 오류");
		exit(1);
	}
	p = get_node_at(list, pos);
	return p->data;
}

void clear(ListType *list)
{
	for (int i = 0; i<list->length; i++)
		delete(list, i);
}

void display(ListType *buffer)
{
	ListNode *tmp_node;
	tmp_node = buffer->head;

	printf("**************\n");
	for (int i = 0; i<buffer->length; i++)
	{
		printf("%s", tmp_node->data.a);
		tmp_node = tmp_node->link;
	}
	printf("**************\n");
}


void read_file(ListType *buffer)
{
	char fname[MAX_NAME];
	FILE *fd;
	element p;

	if (!is_empty(buffer)) {
		clear(buffer);
	}
	init(buffer);

	printf("파일 이름을 입력하세요:");
	scanf("%s", fname);
	getchar();

	fd = fopen(fname, "r");
	if (fd == NULL) {
		printf("파일을 열수 없습니다."); 
		return; 
	}
	while (fgets(p.a, MAX_CHAR_PER_LINE, fd)!=NULL) {
		add_last(buffer, p);
	}
	fclose(fd);

	display(buffer);
}

void write_file(ListType *buffer)
{
	FILE *fd;
	char fname[MAX_NAME];
	element p;
	
	printf("파일 이름을 입력하세요:");
	scanf("%s", &fname);

	fd = fopen(fname, "w");
	if (fd == NULL) { printf("파일을 열수 없습니다."); return; }

	getchar();

	for (int i = 0; i < get_length(buffer); i++)
	{
		p = get_entry(buffer, i);
		fputs(p.a, fd);
	}
	fclose(fd);

	display(buffer);
}

void delete_line(ListType *buffer)
{

	int position;

	if (is_empty(buffer))
		printf("지울 라인이 없습니다.\n");
	else
	{
		printf("지울 라인을 입력(줄은 0부터 셉니다.):");
		scanf("%d", &position);
		delete(buffer, position);
	}
	getchar();

	display(buffer);
}

void insert_line(ListType *buffer)
{

	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;

	printf("입력 할 행 번호를 입력하시오(0줄부터 셉니다) :");
	scanf("%d", &position);
	getchar();                 

	printf("내용입력:");
	fgets(line, MAX_CHAR_PER_LINE, stdin);

	strcpy(p.a, line);
	add(buffer, position, p);

	display(buffer);
}

ListNode *reverse_line(ListType *buffer)
{

	ListNode *p, *q, *r;
	p = buffer->head;
	q = NULL;
	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	getchar();

	return q;

}


void find_line(ListType *buffer)
{
	ListNode *p;
	char line[MAX_CHAR_PER_LINE];
	int i = 0;
	p = buffer->head;

	getchar();

	printf("찾을 문자열을 입력하세요:");
	fgets(line, MAX_CHAR_PER_LINE, stdin);

	while (p != NULL) {
		if (strcmp(p->data.a, line) == 0) { printf("찾으시는 문자열의 라인은 %d번째 입니다.\n", i);  break; }   
		p = p->link;
		i++;
	}
	if (p == NULL) printf("찾지 못했습니다.\n");
}

void change_line(ListType *buffer)
{
	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;

	printf("수정할 라인을 선택하세요.");
	scanf("%d", &position);
	delete(buffer, position);

	getchar();

	printf("새로 넣을 텍스트를 입력하세요:");
	fgets(line, MAX_CHAR_PER_LINE, stdin);

	strcpy(p.a, line);
	add(buffer, position, p);

	display(buffer);
}

void help()
{
	printf("**************\n");
	printf("i: 입력\n");
	printf("d: 삭제\n");
	printf("r: 파일읽기\n");
	printf("w: 파일쓰기\n");
	printf("f: 문자열찾기\n");
	printf("v: 리스트 순서 뒤집기\n");
	printf("c: 특정 라인을 새로운 텍스트로 변경\n");
	printf("q: 종료\n");
	printf("**************\n");
}

void do_command(ListType *buffer, char command)
{
	switch (command)
	{
	case 'i':
		insert_line(buffer);
		break;
	case 'd':
		delete_line(buffer);
		break;
	case 'r':
		read_file(buffer);
		break;
	case 'w':
		write_file(buffer);
		break;
	case 'v':
		buffer->head = reverse_line(buffer);
		display(buffer);
		break;
	case 'c':
		change_line(buffer);
		break;
	case 'f':
		find_line(buffer);
		break;
	case 'q':
		break;

	}

}
void main()
{
	char command;
	ListType buffer;

	init(&buffer);
	do {
		help();
		command = getchar();
		do_command(&buffer, command);
		fflush(stdin);
	} while (command != 'q');
}
