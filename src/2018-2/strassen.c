#include<stdio.h>
#include<stdlib.h>

void strassen(int, int**, int**, int**); // 슈트라센(곱)
int** mat_sum(int, int**, int**);//합
int** mat_sub(int, int**, int**);//차
int** mat_init(int);//선언
void partition(int n, int**, int**, int**, int**, int**);//n/2 * n/x 행렬로 분할

void mat_printf(int n, int** m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", m[i][j]);

		printf("\n");
	}
	printf("\n");
}

int main(void) {
	int n;// n은 2의 멱수

	scanf("%d", &n); //nxn의 행렬 2개 입력 받음

	int ** a, **b, **res;

	a = mat_init(n);
	b = mat_init(n);
	res = mat_init(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			scanf("%d", &b[i][j]);
	}

	printf("\n--------A--------\n");
	mat_printf(n, a);
	printf("\n--------B--------\n");
	mat_printf(n, b);
	
	strassen(n, a, b, res);
	printf("\nResult\n");
	mat_printf(n, res);

	return 0;
}

int** mat_sum(int n, int **a, int** b) {

	int **c;

	c = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) c[i] = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	return c;
}

int** mat_sub(int n, int **a, int** b) {

	int **c = (int**)malloc(sizeof(int*)*n);

	for (int i = 0; i < n; i++) c[i] = (int*)malloc(sizeof(int)*n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = a[i][j] - b[i][j];
		}
	}

	return c;
}

void strassen(int n, int** a, int** b, int** res) {

	int m1, m2, m3, m4, m5, m6, m7;
	int m = n / 2;
	if (n == 1)
		res[0][0] = a[0][0] * b[0][0];

	else if (n == 2) {

		m1 = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
		m2 = (a[1][0] + a[1][1]) * b[0][0];
		m3 = a[0][0] * (b[0][1] - b[1][1]);
		m4 = a[1][1] * (b[1][0] - b[0][0]);
		m5 = (a[0][0] + a[0][1]) * b[1][1];
		m6 = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
		m7 = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);

		res[0][0] = m1 + m4 - m5 + m7;	res[0][1] = m3 + m5;
		res[1][0] = m2 + m4; res[1][1] = m1 - m2 + m3 + m6;

	}
	else {
		int **A11, **A12, **A21, **A22;
		int **B11, **B12, **B21, **B22;

		A11 = mat_init(m); A12 = mat_init(m); A21 = mat_init(m); A22 = mat_init(m);
		B11 = mat_init(m); B12 = mat_init(m); B21 = mat_init(m); B22 = mat_init(m);
		partition(n, a, A11, A12, A21, A22);
		partition(n, b, B11, B12, B21, B22);

		int **M1, **M2, **M3, **M4, **M5, **M6, **M7;

		M1 = mat_init(m);M2 = mat_init(m);M3 = mat_init(m);
		M4 = mat_init(m);M5 = mat_init(m);M6 = mat_init(m);M7 = mat_init(m);

		strassen(m, mat_sum(m, A11, A22), mat_sum(m, B11, B22), M1);
		strassen(m, mat_sum(m, A21, A22), B11, M2);
		strassen(m, A11, mat_sub(m, B12, B22), M3);
		strassen(m, A22, mat_sub(m, B21, B11), M4);
		strassen(m, mat_sum(m, A11, A12), B22, M5);
		strassen(m, mat_sub(m, A21, A11), mat_sum(m, B11, B12), M6);
		strassen(m, mat_sub(m, A12, A22), mat_sum(m, B21, B22), M7);

		for (int i = 0; i < m; i++){
			for (int j = 0; j < m; j++){
				res[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
				res[i][j + m] = M3[i][j] + M5[i][j];
				res[i + m][j] = M2[i][j] + M4[i][j];
				res[i + m][j + m] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
			}
		}

	}

}

void partition(int n, int** matrix, int** A11, int** A12, int **A21, int **A22) {

	int m = n / 2;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			A11[i % m][j % m] = matrix[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = m; j < n; j++) {
			A12[i % m][j % m] = matrix[i][j];
		}
	}

	for (int i = m; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A21[i % m][j % m] = matrix[i][j];
		}
	}

	for (int i = m; i < n; i++) {
		for (int j = m; j < n; j++) {
			A22[i % m][j % m] = matrix[i][j];
		}
	}

}

int** mat_init(int n) {
	int **matrix;
	matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) matrix[i] = (int*)malloc(sizeof(int)*n);

	return matrix;
}