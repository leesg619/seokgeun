
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

//미로의 행과 열의 위치
typedef struct  StackObjectRec {
	short r;
	short c;
} StackObject;

StackObject  stack[MAX_STACK_SIZE];
int  top = -1;
StackObject here = { 1,0 }, entry = { 1,0 };
//미로 모양
char maze[MAZE_SIZE][MAZE_SIZE] = {
	{ '1', '1', '1', '1', '1', '1' },
	{ 'e', '0', '0', '0', '1', '1' },
	{ '1', '1', '0', '1', '1', '1' },
	{ '1', '1', '0', '1', '1', '1' },
	{ '1', '0', '0', '0', '0', 'x' },
	{ '1', '1', '1', '1', '1', '1' },
};

void initialize()
{
	top = -1;
}
//스택이 비어있는지 검사
int isEmpty()
{
	return (top == -1);
}
//스택이 가득 찼는가를 검사
int isFull()
{
	return (top == (MAX_STACK_SIZE - 1));
}
//스택의 맨 위에 item 추가
void push(StackObject item)
{
	if (isFull()) {
		printf("stack is full\n");
	}
	else stack[++top] = item;
}
//스택의 맨 위에 있는 요소를 삭제
StackObject pop()
{
	if (isEmpty()) {
		printf("stack is empty\n");
	}
	else return stack[top--];
}
//스택에 들어있는 요소 출력
void printStack()
{
	int i;
	for (i = 5; i>top; i--)
		printf("|     |\n");
	for (i = top; i >= 0; i--)
		printf("|(%01d,%01d)|\n", stack[i].r, stack[i].c);
	printf("-------\n");
}

//현재 미로 모양 출력
void printMaze(char m[MAZE_SIZE][MAZE_SIZE])
{
	int r, c;
	printf("\n\n");
	for (r = 0; r<MAZE_SIZE; r++) {
		for (c = 0; c<MAZE_SIZE; c++) {
			if (c == here.c && r == here.r)
				printf("m ");
			else {
				if (m[r][c] == 0) printf("0 ");
				else printf("%c ", m[r][c]);
			}
		}
		printf("\n");
	}
	printf("\n\n");
}

void pushLoc(int r, int c)
{
	StackObject tmp;
	if (r < 0 || c < 0) return;
	if (maze[r][c] != '1' && maze[r][c] != '.')
	{
		tmp.r = r;
		tmp.c = c;
		push(tmp);
	}
}

void main()
{
	int r, c;
	here = entry;
	printMaze(maze);
	printStack();
	while (maze[here.r][here.c] != 'x') {

		r = here.r;
		c = here.c;
		maze[r][c] = '.';

		pushLoc(r - 1, c);
		pushLoc(r + 1, c);
		pushLoc(r, c - 1);
		pushLoc(r, c + 1);

		printMaze(maze);
		printStack();

		if (isEmpty()) {
			printf("실패");
			return;
		}
		else here = pop();

		getch();
	}
	printf("성공\n");
}

