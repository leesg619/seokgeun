#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	100		/* 정점의 수 */
#define INF	10000	/* 무한대 (연결이 없는 경우) */

typedef struct GraphType {
	int n;	// 정점의 개수
	int weight[MAX_VERTICES][MAX_VERTICES]; //가중치 인접 행렬
} GraphType;


int distance[MAX_VERTICES];
int found[MAX_VERTICES];
int parent[MAX_VERTICES];

void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) /* 초기화 */
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		/*parents의초기화*/
	}
	found[start] = TRUE;    /* 시작 정점 방문 표시 */
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

int choose(int distance[], int n, int found[]) { //현재 distance중 가장 작은 가중치를 갖는 정점을 반환
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

void print_status(GraphType*g) { //현재 STEP에서 distance와 found의 상태 출력
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
	
	//모든  정점마다 parent 배열 이용하여 경로출력
	}
