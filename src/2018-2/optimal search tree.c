#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

void optsearchtree(int n, const float p[], float* minavg);
int R[SIZE + 1][SIZE + 1];

int main(void) {
	float p[SIZE] = { (float)3/8, (float)3/8, (float)1/8, (float)1/8};
	float minavg;
	
	optsearchtree(SIZE, p, &minavg);
	printf("minavg = %f", minavg);
}

void optsearchtree(int n, const float p[], float* minavg){
	int i, j, k, diagonal, l, min_k;
	n++; // �Է°��� n������ �迭 ũ��� n+1 x n+1 �̹Ƿ� 
	float sum_p=0, min;
	float A[SIZE+1][SIZE+1];
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) A[i][j] = 9.99; // �Ⱦ��� �� ������ ���� �Է�
		
	for (i = 0; i < n; i++){
		A[i][i] = 0; 
		A[i][i+1] = p[i];
		R[i][i] = 0;
		R[i][i + 1] = i+1;
		
	}
		for (diagonal = 2; diagonal <= n - 1; diagonal++) // �ι�° �밢������ �Է��ϸ� �Ǳ� ����
			for (i = 0; i < n - diagonal; i++){
			j = i + diagonal;
			for (l = i; l < j; l++) sum_p = sum_p + p[l];
			k = i;
			min = A[i][k] + A[k + 1][j];
			min_k = k;
			for (k = i+1; k <= j-1; k++){
				if (min > A[i][k] + A[k + 1][j]){
				
					min = A[i][k] + A[k + 1][j];
					min_k = k;
				}	
			}
			
			A[i][j] = min + sum_p;
			R[i][j] = min_k+1; // �ڵ忡�� 0���� �����ϹǷ� +1 ���ش�
			sum_p = 0;
			}
		printf("- A �迭 - \n"); // A �迭 ���
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%0.3f ", A[i][j]);
			}
			printf("\n");
		}
		printf("\n- R �迭 - \n");
		for (int i = 0; i < n; i++) { // R �迭 ���
			for (int j = 0; j < n; j++) {
				printf("%d ", R[i][j]);
			}
			printf("\n");
		}

		*minavg = A[0][SIZE]; // ����� ����
	
}


