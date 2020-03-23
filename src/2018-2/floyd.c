#include<stdio.h>
#include<stdlib.h>


int** mat_init(int);//선언
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

int d[6] = { 10, 4, 5, 20, 2, 50 };//minult함수의파라미터로사용할d배열을전역변수로선언
int p[5][5] = { 0 };//k값저장하는p배열을전역변수로선언한후, 0으로초기화

int main() {
	int i, result1, result2;
	printf("asdasd");
	result1 = minmult(5, d);//사용할행렬이5개로정해져있기때문에5의값을바로보내준다
	printf("M[1][5] : %d\n", result1);//minmult함수의return값인M[1][5]행렬의값출력

	printf("P[1][5]경로: ");
	order(0, 4);//P행렬을사용하여경로를출력하기위한함수호출
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
//k값이저장된P행렬을사용하여최적순서경로구하는함수
void order(int i, int j) {
	if (i == j)
		printf("A%d", i + 1);
	else {
		int k = p[i][j];
		printf("(");
		//i=j가될때까지재귀함수사용
		order(i, k);
		order(k + 1, j);
		printf(")");
	}
}
