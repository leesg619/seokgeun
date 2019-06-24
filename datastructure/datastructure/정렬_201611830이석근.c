//201611830이석근
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 150 //배열크기지정

typedef struct Student {
	int stu_num;//학번
	char name[MAX_SIZE];//이름
	char major[MAX_SIZE];//학과
	int year;//학년
}Student; //학생 구조체 선언


Student student[MAX_SIZE],sorted_student[MAX_SIZE]; //정렬 전 : student , 정렬 후 : sorted_student 배열 구조체 선언(전역)

void merge(int low, int mid, int high)
{
	int i, j, k, l;
	i = low;  j = mid + 1;  k = low;
	while (i <= mid && j <= high) //멤버 비교 후 같은 형식의(Student) 구조체이므로 대입 연산으로 정렬 시켰습니다.
	{
		if (student[i].stu_num <= student[j].stu_num) //기존의 데이터 비교를 구조체의 멤버 비교로
			sorted_student[k] = student[i++];
		else
			sorted_student[k] = student[j++];
		k++;
	}
	if (i>mid) /* 두번째 리스트 뒤에 남아있는 데이터의 일괄합병*/
		for (l = j; l <= high; l++)
			sorted_student[k++] = student[l];
	else /* 첫번째 리스트 뒤에 남아있는 데이터의 일괄합병*/
		for (l = i; l <= mid; l++)
			sorted_student[k++] = student[l];
	/* 배열 sorted[]에 정렬된 데이터를 배열list[]로 재복사*/
	for (l = low; l <= high; l++)
		student[l] = sorted_student[l];
}


void merge_sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;         /* 리스트의 균등 분할*/
		merge_sort(low, mid);      /* 왼쪽 부분리스트 정렬*/
		merge_sort(mid + 1, high); /* 오른쪽 부분리스트 정렬*/
		merge(low, mid, high);      /* 분할된 두개의 부분리스트 합병*/
	}
}



void main() {

	int res, i , size;
	FILE *ifp, *ofp;
	ifp =fopen("students.txt", "r");
	if (ifp == NULL) {
		printf("입력 파일을 열지 못했습니다.");
		return;
	} /*입력파일 포인터, 출력파일 포인터*/;
	ofp = fopen("sorted.txt", "w");
	if (ofp == NULL) {
		printf("출력 파일을 열지 못했습니다.");
		return;
	}
	for(i= 0; ; i++){//fscanf이용하여 한줄씩 student 배열에 저장
		res = fscanf(ifp, "%d   %s   %s   %d", &student[i].stu_num, student[i].name, student[i].major, &student[i].year);
		if (res == EOF)  break; //fscanf는 파일 끝이면 EOF출력하므로
	}
	size = i;
	
	merge_sort(0, size - 1);
	printf("정렬을 완료했습니다.\n");

	for (i = 0; i < size; i++) { //파일 포인터로 sorted.txt에 저장
		fprintf(ofp, "%d %s %s %d\n", sorted_student[i].stu_num, sorted_student[i].name, sorted_student[i].major, sorted_student[i].year);
	}
	printf("sorted.txt파일에 저장을 성공했습니다.\n");
	getchar();//실행화면 유지를 위해 넣었습니다.
	
	fclose(ifp); fclose(ofp);
}