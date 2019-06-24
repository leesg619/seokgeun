#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* ������ �� */
#define INF	10000	/* ���Ѵ� (������ ���� ���) */

typedef struct GraphType {
	int n;	// ������ ����
	int weight[MAX_VERTICES][MAX_VERTICES]; //����ġ ���� ���
} GraphType;


int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int parent[MAX_VERTICES];

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* �ʱ�ȭ */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		/*parents���ʱ�ȭ*/
	}
	found[start] = TRUE;    /* ���� ���� �湮 ǥ�� */
	distance[start] = 0;
	parent[start] = start;

	for (i = 0; i<g->n - 2; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w<g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w]<distance[w])
					distance[w] = distance[u] + g->weight[u][w];
	}
}

int choose(int distance[], int n, int found[]) { //���� distance�� ���� ���� ����ġ�� ���� ������ ��ȯ
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType*g) { //���� STEP���� distance�� found�� ���� ���
	static int step = 1;
	printf("STEP %d : ", step++);
	printf("distance : ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->n; i++)
		printf("%2d ", found[i]);
	printf("\n\n");

}

void main() {
	GraphType g = { 8,
	{{0,5,6,2,INF,INF,INF,INF},
	{INF,0,3,INF,INF,INF,INF,INF},
	{INF,INF,0,INF,2,INF,1,INF},
	{INF,INF,1,0,7,INF,INF,INF},
	{3,INF,INF,INF,0,1,INF,4},
	{INF,INF,INF,INF,INF,0,7,2},
	{INF,INF,INF,1,INF,INF,0,11},
	{INF,INF,INF,INF,INF,INF,INF,0}}
	};
	shortest_path(&g, 0);
	
	//���  �������� parent �迭 �̿��Ͽ� ������
	}
