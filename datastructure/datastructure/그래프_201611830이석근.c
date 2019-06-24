#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TRUE	1
#define FALSE	0
#define MAX_VERTICES	9	/* 정점의 수 */


typedef struct GraphType {
	int n; // 정점의개수
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int count = 0;
int visited[MAX_VERTICES] = { FALSE, }; //방문안했으면 0 , 했으면 1
int parent[MAX_VERTICES];//start,goal을 탐색 과정 중 새로 방문하는 정점 번호가 v라면, parent[v]에는 정점 v 직전에 방문한 인접 정점의 번호를 저장


void dfs_mat_path(GraphType* g, int start, int goal) {
	int j, k;
	visited[start] = TRUE; //방문한 노드를 1로 표시하여 다시 방문하지 않게 함.
	if (parent[count] != start)//방문한 노드를 저장.
		parent[count] = start;
	count++;
	if (start== goal)//목표지점이라면
		for (k = 0; k < g->n; k++)
			visited[k] = TRUE;
	for (j = 0; j < g->n; j++) {
		if (g->adj_mat[start][j] == 1 && visited[j] == FALSE) { //인접 하고 방문한적이 없으면
			printf("%d -> %d, ", start, j); //경로를 출력
			dfs_mat_path(g, j, goal); //리커시브 이용
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
	} }; //인접행렬로 나타낸 그래프

	printf("시작정점을 입력하세요.(0~8사이의숫자)\n");
	scanf("%d", &start);
	printf("도착정점을 입력하세요.(0~8사이의숫자)\n");
	scanf("%d", &goal);
	printf("깊이 우선 탐색 시작\n\n");
	dfs_mat_path(&g, start, goal); //탐색시작
	printf("\n탐색완료!\n");

	while (getchar() != '\n');
	getchar(); //실행파일에서 결과 출력 과 동시에 바로 꺼지지 않게 엔터를 한번 더 입력하면 종료하게 했습니다.

}