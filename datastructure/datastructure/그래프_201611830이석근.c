#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	9	/* ������ �� */


typedef struct GraphType {
	int n; // �����ǰ���
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int count = 0;
int visited[MAX_VERTICES] = { FALSE, }; //�湮�������� 0 , ������ 1
int parent[MAX_VERTICES];//start,goal�� Ž�� ���� �� ���� �湮�ϴ� ���� ��ȣ�� v���, parent[v]���� ���� v ������ �湮�� ���� ������ ��ȣ�� ����


void dfs_mat_path(GraphType* g, int start, int goal) {
	int j, k;
	visited[start] = TRUE; //�湮�� ��带 1�� ǥ���Ͽ� �ٽ� �湮���� �ʰ� ��.
	if (parent[count] != start)//�湮�� ��带 ����.
		parent[count] = start;
	count++;
	if (start== goal)//��ǥ�����̶��
		for (k = 0; k < g->n; k++)
			visited[k] = TRUE;
	for (j = 0; j < g->n; j++) {
		if (g->adj_mat[start][j] == 1 && visited[j] == FALSE) { //���� �ϰ� �湮������ ������
			printf("%d -> %d, ", start, j); //��θ� ���
			dfs_mat_path(g, j, goal); //��Ŀ�ú� �̿�
		}
	}

}


void main()
{
	int start;
	int goal;
	
	GraphType g = { 9,{ { 0, 0, 0, 1, 1, 1, 0, 0, 0 },
	{ 0, 0, 0, 0, 1, 0, 0, 1, 0 },
	{ 0, 0, 0, 1, 1, 1, 0, 0, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 0, 0 },
	{ 1, 1, 1, 0, 0, 1, 0, 0, 0 },
	{ 1, 0, 1, 0, 1, 0, 1, 0, 0 },
	{ 0, 0, 0, 1, 0, 1, 0, 1, 1 },
	{ 0, 1, 0, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 0, 1, 0, 0 } 
	} }; //������ķ� ��Ÿ�� �׷���

	printf("���������� �Է��ϼ���.(0~8�����Ǽ���)\n");
	scanf("%d", &start);
	printf("���������� �Է��ϼ���.(0~8�����Ǽ���)\n");
	scanf("%d", &goal);
	printf("���� �켱 Ž�� ����\n\n");
	dfs_mat_path(&g, start, goal); //Ž������
	printf("\nŽ���Ϸ�!\n");

	while (getchar() != '\n');
	getchar(); //�������Ͽ��� ��� ��� �� ���ÿ� �ٷ� ������ �ʰ� ���͸� �ѹ� �� �Է��ϸ� �����ϰ� �߽��ϴ�.

}