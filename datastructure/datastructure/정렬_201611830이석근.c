//201611830�̼���
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 150 //�迭ũ������

typedef struct Student {
	int stu_num;//�й�
	char name[MAX_SIZE];//�̸�
	char major[MAX_SIZE];//�а�
	int year;//�г�
}Student; //�л� ����ü ����


Student student[MAX_SIZE],sorted_student[MAX_SIZE]; //���� �� : student , ���� �� : sorted_student �迭 ����ü ����(����)

void merge(int low, int mid, int high)
{
	int i, j, k, l;
	i = low;  j = mid + 1;  k = low;
	while (i <= mid && j <= high) //��� �� �� ���� ������(Student) ����ü�̹Ƿ� ���� �������� ���� ���׽��ϴ�.
	{
		if (student[i].stu_num <= student[j].stu_num) //������ ������ �񱳸� ����ü�� ��� �񱳷�
			sorted_student[k] = student[i++];
		else
			sorted_student[k] = student[j++];
		k++;
	}
	if (i>mid) /* �ι�° ����Ʈ �ڿ� �����ִ� �������� �ϰ��պ�*/
		for (l = j; l <= high; l++)
			sorted_student[k++] = student[l];
	else /* ù��° ����Ʈ �ڿ� �����ִ� �������� �ϰ��պ�*/
		for (l = i; l <= mid; l++)
			sorted_student[k++] = student[l];
	/* �迭 sorted[]�� ���ĵ� �����͸� �迭list[]�� �纹��*/
	for (l = low; l <= high; l++)
		student[l] = sorted_student[l];
}


void merge_sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;         /* ����Ʈ�� �յ� ����*/
		merge_sort(low, mid);      /* ���� �κи���Ʈ ����*/
		merge_sort(mid + 1, high); /* ������ �κи���Ʈ ����*/
		merge(low, mid, high);      /* ���ҵ� �ΰ��� �κи���Ʈ �պ�*/
	}
}



void main() {

	int res, i , size;
	FILE *ifp, *ofp;
	ifp =fopen("students.txt", "r");
	if (ifp == NULL) {
		printf("�Է� ������ ���� ���߽��ϴ�.");
		return;
	} /*�Է����� ������, ������� ������*/;
	ofp = fopen("sorted.txt", "w");
	if (ofp == NULL) {
		printf("��� ������ ���� ���߽��ϴ�.");
		return;
	}
	for(i= 0; ; i++){//fscanf�̿��Ͽ� ���پ� student �迭�� ����
		res = fscanf(ifp, "%d   %s   %s   %d", &student[i].stu_num, student[i].name, student[i].major, &student[i].year);
		if (res == EOF)  break; //fscanf�� ���� ���̸� EOF����ϹǷ�
	}
	size = i;
	
	merge_sort(0, size - 1);
	printf("������ �Ϸ��߽��ϴ�.\n");

	for (i = 0; i < size; i++) { //���� �����ͷ� sorted.txt�� ����
		fprintf(ofp, "%d %s %s %d\n", sorted_student[i].stu_num, sorted_student[i].name, sorted_student[i].major, sorted_student[i].year);
	}
	printf("sorted.txt���Ͽ� ������ �����߽��ϴ�.\n");
	getchar();//����ȭ�� ������ ���� �־����ϴ�.
	
	fclose(ifp); fclose(ofp);
}