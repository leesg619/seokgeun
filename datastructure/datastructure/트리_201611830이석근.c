#define _CRT_SECURE_NO_WARNINGS
// 이진 탐색 트리를 사용한 영어 사전

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_WORD_SIZE	 100
#define MAX_MEANING_SIZE 200

// 데이터 형식
typedef struct {
	char word[MAX_WORD_SIZE];		// 키필드
	char meaning[MAX_MEANING_SIZE];
} element;
// 노드의 구조
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

// 만약 e1 > e2 -> -1 반환
// 만약 e1 == e2 -> 0  반환 
// 만약 e1 < e2 -> 1 반환
int compare(element e1, element e2)
{
	return strcmp(e1.word, e2.word);
}
// 이진 탐색 트리 출력 함수
void display(TreeNode *p)
{
	if( p != NULL ) {
		printf("(");
		display(p->left);
		printf("%s", p->key.word);
		display(p->right);
		printf(")");
	}
}
// 이진 탐색 트리 탐색 함수
TreeNode *search(TreeNode *root, element key) 
{    
	TreeNode *p=root;
	while(p != NULL){ 
		switch (compare(key, p->key)) {
		case -1:
			p = p->left;
			break;
		case 0:
			return p;
		case 1:
			p = p->right;
			break;
		}
		
		
	} 
	return p; 	// 탐색에 실패했을 경우 NULL 반환
} 
// key를 이진 탐색 트리 root에 삽입한다. 
// key가 이미 root안에 있으면 삽입되지 않는다.
void insert_node(TreeNode **root, element key) 
{
	TreeNode *p, *t; // p는 부모 노드, p는 자식 노드 
	TreeNode *n;	 // n은 새로운 노드

	t = *root;
	p = NULL;
	// 탐색을 먼저 수행 
	while (t != NULL){
		if( compare(key, t->key)==0 ) return;
		p = t;
		if( compare(key , t->key)<0 ) t = t->left;
		else t = t->right;
	}
	// item이 트리 안에 없으므로 삽입 가능
	n = (TreeNode *) malloc(sizeof(TreeNode));
	if( n == NULL ) return;
	// 데이터 복사
	n->key = key;
	n->left = n->right = NULL;
	// 부모 노드와 링크 연결
	if (p != NULL)
		if (compare(key, p->key) < 0)
			p->left = n;
		else p->right = n;
	else *root = n;

	/*코드 작성*/
	/*부모 노드가 있을 때
		/*compare(element e1, element e2)
	/*부모 노드가 없을 때*/
}
// 삭제 함수
void delete_node(TreeNode **root, element key)
{
	TreeNode *p, *child, *succ, *succ_p, *t;

	// key를 갖는 노드 t를 탐색, p는 t의 부모노드
	p = NULL;
	t = *root;
	while( t != NULL && compare(t->key, key) != 0 ){
		p = t;
		t = ( compare(key, t->key)<0 ) ? t->left : t->right;
	}
	if( t == NULL ) { 	// 탐색트리에 없는 키
		printf("key is not in the tree\n");
		return;
	}
	// 단말노드인 경우
	if( (t->left==NULL) && (t->right==NULL) ){ 
		if( p != NULL ){
			if( p->left == t )	 
				p->left = NULL;
			else   p->right = NULL;
		}
		else					// 부모노드가 없으면 루트
			*root = NULL;
	}
	// 하나의 자식만 가지는 경우
	else if((t->left==NULL)||(t->right==NULL)){
		child = (t->left != NULL) ? t->left : t->right;
		if( p != NULL ){
			if( p->left == t )	// 부모노드를 자식노드와 연결 
				p->left = child;
			else p->right = child;
		}
		else
			*root = child;
	}
	else {		// 두개의 자식을 가지는 경우
		succ_p = t;
		succ = t->left;
		
		while (succ->left != NULL) {
			succ_p = succ;
			succ = succ->left;
		}
		if (succ_p->left == succ)
			succ_p->left = succ->right;
		else
			succ_p->right = succ->right;

		t->key = succ->key;
		t = succ;
	
	}
	free(t);
}
// data.txt로부터 저장된 내용을 불러오는 함수
void file_Load(TreeNode **tree) {
	FILE *fp;
	element key;
	fp = fopen("Eng_dic.txt", "r");

	if (fp == NULL) {
		fprintf(stderr, "파일 불러오기 실패");
		exit(1);
	}

	printf("파일로부터 불러온 정보\n");
	while (fscanf(fp, "%s", &key.word) != EOF) {
		printf("단어 : %s", key.word);
		fscanf(fp, "%s", &key.meaning);
		printf(", 의미 : %s\n", key.meaning);
		insert_node(&(*tree), key);
	}
	fclose(fp);
}
//전위순회 순으로 fp파일 스트림에 tree포인터의 내용을 쓴다.
void saving(FILE *ifp, TreeNode *tree) {
	if (tree) {
		fprintf(ifp, "%s", tree->key.word);
		fprintf(ifp, "\n");
		fprintf(ifp, "%s", tree->key.meaning);
		fprintf(ifp, "\n");
		saving(ifp, tree->left);
		saving(ifp, tree->right);
	}
}

void file_save(TreeNode *tree) {
	FILE *ifp;
	ifp = fopen("Eng_dic.txt", "w");
	if (ifp == NULL) {
		fprintf(stderr, "파일 열기 실패");
		exit(1);
	}

	printf("\n\n파일을 전위 순회 방법으로 저장합니다.\n");
	saving(ifp, tree);//함수의 순환방법으로 파일 저장.
	printf("Eng_dic.txt 파일에 저장 완료!!\n");
	fclose(ifp);//열린 파일 스트림을 닫아 준다.
}



void help()
{
	printf("**************\n");
	printf("i: 입력\n");
	printf("d: 삭제\n");
	printf("s: 탐색\n");
	printf("p: 출력\n");
	printf("o: 파일 열기\n");
	printf("v: 파일 저장\n");
	printf("q: 종료\n");
	printf("**************\n");
}

// 이진 탐색 트리를 사용하는 영어 사전 프로그램 
void main()
{
	char command;
	element e;
	TreeNode *root=NULL;
	TreeNode *tmp;

	do{
		help();
		command = getchar();
		fflush(stdin);

		switch (command) {
		case 'i':
			printf("단어:");
			scanf("%s",e.word);
			printf("의미:");
			scanf("%s", e.meaning);
			insert_node(&root, e);
			break;

		case 'd':
			printf("삭제할 단어를 입력하세요.>> ");
			scanf("%s", e.word);
			delete_node(&root, e);
			break;

		case 'p':
			display(root);
			printf("\n");
			break;
			
		case 's':
			printf("단어:");
			scanf("%s", e.word);
			tmp = search(root, e);
			if (tmp != NULL)
				printf("의미 :%s\n", tmp->key.meaning);
			else
				printf("찾으시는 단어가 없습니다.\n");
			break;
		
		case 'v':
			file_save(root);
			printf("\n");
			break;


		case 'o':
			file_Load(&root);
			break;
		}

		while (getchar() != '\n');


	} while(command != 'q');
}
