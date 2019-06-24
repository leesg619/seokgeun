 //201611830 �̼���
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
} ListType; //���

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
			printf("�޸� �Ҵ翡��");
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
		printf("��ġ ����");
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

	printf("���� �̸��� �Է��ϼ���:");
	scanf("%s", fname);
	getchar();

	fd = fopen(fname, "r");
	if (fd == NULL) {
		printf("������ ���� �����ϴ�."); 
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
	
	printf("���� �̸��� �Է��ϼ���:");
	scanf("%s", &fname);

	fd = fopen(fname, "w");
	if (fd == NULL) { printf("������ ���� �����ϴ�."); return; }

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
		printf("���� ������ �����ϴ�.\n");
	else
	{
		printf("���� ������ �Է�(���� 0���� ���ϴ�.):");
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

	printf("�Է� �� �� ��ȣ�� �Է��Ͻÿ�(0�ٺ��� ���ϴ�) :");
	scanf("%d", &position);
	getchar();                 

	printf("�����Է�:");
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

	printf("ã�� ���ڿ��� �Է��ϼ���:");
	fgets(line, MAX_CHAR_PER_LINE, stdin);

	while (p != NULL) {
		if (strcmp(p->data.a, line) == 0) { printf("ã���ô� ���ڿ��� ������ %d��° �Դϴ�.\n", i);  break; }   
		p = p->link;
		i++;
	}
	if (p == NULL) printf("ã�� ���߽��ϴ�.\n");
}

void change_line(ListType *buffer)
{
	int position;
	char line[MAX_CHAR_PER_LINE];
	element p;

	printf("������ ������ �����ϼ���.");
	scanf("%d", &position);
	delete(buffer, position);

	getchar();

	printf("���� ���� �ؽ�Ʈ�� �Է��ϼ���:");
	fgets(line, MAX_CHAR_PER_LINE, stdin);

	strcpy(p.a, line);
	add(buffer, position, p);

	display(buffer);
}

void help()
{
	printf("**************\n");
	printf("i: �Է�\n");
	printf("d: ����\n");
	printf("r: �����б�\n");
	printf("w: ���Ͼ���\n");
	printf("f: ���ڿ�ã��\n");
	printf("v: ����Ʈ ���� ������\n");
	printf("c: Ư�� ������ ���ο� �ؽ�Ʈ�� ����\n");
	printf("q: ����\n");
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
