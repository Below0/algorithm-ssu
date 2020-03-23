#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4

void sum_of_subsets(int, int, int);
int promising(int, int, int);

int w[SIZE] = {3, 4, 5, 6}; // �Է°�
int include[SIZE] = { 0,};
int W;

int main(void){
	W = 13;
	int total = 0;
	for (int i = 0; i < SIZE; i++){
		total += w[i];
	}
	sum_of_subsets(0, 0, total); 
	return 0;
}

void sum_of_subsets(int i, int weight, int total){
	
		if (promising(i, weight, total)){ // ������ �˻�
			if (weight == W){
				printf("========include========\n");
				for (int j = 0; j < i; j++){

						printf("%d ", include[j]);
				}
				printf("\n=================\n")
				for (int j = 0; j < i; j++){
					if (include[j] == TRUE){
						printf("%d ", w[j]);
					}
				}
				printf("\n");
			}
			else {
				include[i] = TRUE; // �̹� ���� ������ ���
				sum_of_subsets(i + 1, weight + w[i], total - w[i]);
				include[i] = FALSE; // �̹� ���� �� ���ϰ� �Ѱ��� ���
				sum_of_subsets(i + 1, weight, total - w[i]);
			}
		}
	
}

	int promising(int i, int weight, int total) {
		return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W); // ������ ��� TRUE ���� 

	}