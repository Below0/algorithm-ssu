#include<stdio.h>
#include<stdlib.h>


int** mat_init(int);//����
int minmult(int, const int*);
void order(int, int);


void mat_printf(int n, int** m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", m[i][j]);

		printf("\n");
	}
	printf("\n");
}

int** mat_init(int n) {
	int **matrix;
	matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) matrix[i] = (int*)malloc(sizeof(int)*n);

	return matrix;
}

int d[6] = { 10, 4, 5, 20, 2, 50 };//minult�Լ����Ķ���ͷλ����d�迭�����������μ���
int p[5][5] = { 0 };//k�������ϴ�p�迭�����������μ�������, 0�����ʱ�ȭ

int main() {
	int i, result1, result2;
	printf("asdasd");
	result1 = minmult(5, d);//����������5�����������ֱ⶧����5�ǰ����ٷκ����ش�
	printf("M[1][5] : %d\n", result1);//minmult�Լ���return����M[1][5]����ǰ����

	printf("P[1][5]���: ");
	order(0, 4);//P���������Ͽ���θ�����ϱ������Լ�ȣ��
}


int minmult(int n, const int* d) {
	int i, j, k, diagonal;
	int **M = mat_init(n);
	for (int i = 0; i < n; i++) M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 0; i < n - diagonal; i++){
			j = i + diagonal;
			M[i][j] = diagonal;
		}
	printf("\\\")\n
	mat_printf(n, M);
	return M[0][n - 1];
}
//k���������P���������Ͽ�����������α��ϴ��Լ�
void order(int i, int j) {
	if (i == j)
		printf("A%d", i + 1);
	else {
		int k = p[i][j];
		printf("(");
		//i=j���ɶ���������Լ����
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}
