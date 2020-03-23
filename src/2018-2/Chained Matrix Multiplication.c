#include<stdio.h>
#include<stdlib.h>

int minmult(int, const int*); // Chained Matrix 행렬곱의 최소 곱셈수 구하기
void order(int, int); // P행렬을 기반으로 최소 곱셈이 되는 행렬 곱셈식 출력


void mat_printf(int n, int** m) { // 배열 출력 함수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", m[i][j]);

		printf("\n");
	}
	printf("\n");
}

int** mat_init(int n) { // n X n 배열 동적 선언 함수
	int **matrix;
	matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) matrix[i] = (int*)malloc(sizeof(int)*n);

	return matrix;
}

int d[7] = { 5, 2, 3, 4, 6, 7, 8 }; // 행렬의 정보 입력
int size = 6;
int P[6][6] = { 0, };


int main(void) {
	int i, n, res;
	res = minmult(size, d);
	printf("M[1][5] : %d\n", res); // 최소 곱셈 수 계산
	printf("P[1][5]경로: "); // 경로 출력
	order(0, 5);
}


int minmult(int n, const int* d) {
	int i, j, k, diagonal;
	int **M = mat_init(n);
	int min;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) M[i][j] = 999999; // 쓰지 않는 값들 구별을 위해 입력
	for (int i = 0; i < n; i++) M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 0; i < n - diagonal; i++){
			j = i + diagonal;
			for (k = i; k < j; k++){ // 행렬 i 부터 k 까지 곱했을 때의 최소 곱셈 수행 수를 구하는 과정
				min = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
				if (M[i][j] > min){
					M[i][j] = min;
					P[i][j] = k + 1; // 실제 코드에선 0부터 시작이므로 +1 해준다
				}
			}
		}

	mat_printf(n, M);
	return M[0][n - 1]; // 결과값 출력(행렬 1부터 n까지 곱했을 때 곱의 최소 수행 수)
}

void order(int i, int j) { //곱셉 실행 수가 최적이 나오도록 P행렬을 이용하여 출력

	if (i == j)
		printf("A%d", i + 1);
	else {
		int k = P[i][j] - 1; // K+1로 저장했었기 때문에 읽을 때는 다시 -1
		printf("(");
		order(i, k); // i 부터 k 로 분할하여 재귀
		order(k + 1, j); // k + 1 부터 j로 분할하여 재귀
		printf(")");
	}
}
