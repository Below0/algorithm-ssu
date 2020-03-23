#include<stdio.h>
#include<stdlib.h>

int minmult(int, const int*); // Chained Matrix ��İ��� �ּ� ������ ���ϱ�
void order(int, int); // P����� ������� �ּ� ������ �Ǵ� ��� ������ ���


void mat_printf(int n, int** m) { // �迭 ��� �Լ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) printf("%d ", m[i][j]);

		printf("\n");
	}
	printf("\n");
}

int** mat_init(int n) { // n X n �迭 ���� ���� �Լ�
	int **matrix;
	matrix = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) matrix[i] = (int*)malloc(sizeof(int)*n);

	return matrix;
}

int d[7] = { 5, 2, 3, 4, 6, 7, 8 }; // ����� ���� �Է�
int size = 6;
int P[6][6] = { 0, };


int main(void) {
	int i, n, res;
	res = minmult(size, d);
	printf("M[1][5] : %d\n", res); // �ּ� ���� �� ���
	printf("P[1][5]���: "); // ��� ���
	order(0, 5);
}


int minmult(int n, const int* d) {
	int i, j, k, diagonal;
	int **M = mat_init(n);
	int min;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) M[i][j] = 999999; // ���� �ʴ� ���� ������ ���� �Է�
	for (int i = 0; i < n; i++) M[i][i] = 0;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
		for (i = 0; i < n - diagonal; i++){
			j = i + diagonal;
			for (k = i; k < j; k++){ // ��� i ���� k ���� ������ ���� �ּ� ���� ���� ���� ���ϴ� ����
				min = M[i][k] + M[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
				if (M[i][j] > min){
					M[i][j] = min;
					P[i][j] = k + 1; // ���� �ڵ忡�� 0���� �����̹Ƿ� +1 ���ش�
				}
			}
		}

	mat_printf(n, M);
	return M[0][n - 1]; // ����� ���(��� 1���� n���� ������ �� ���� �ּ� ���� ��)
}

void order(int i, int j) { //���� ���� ���� ������ �������� P����� �̿��Ͽ� ���

	if (i == j)
		printf("A%d", i + 1);
	else {
		int k = P[i][j] - 1; // K+1�� �����߾��� ������ ���� ���� �ٽ� -1
		printf("(");
		order(i, k); // i ���� k �� �����Ͽ� ���
		order(k + 1, j); // k + 1 ���� j�� �����Ͽ� ���
		printf(")");
	}
}
