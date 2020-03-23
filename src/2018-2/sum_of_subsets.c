#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4

void sum_of_subsets(int, int, int);
int promising(int, int, int);

int w[SIZE] = {3, 4, 5, 6}; // 입력값
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
	
		if (promising(i, weight, total)){ // 유망성 검사
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
				include[i] = TRUE; // 이번 값을 더했을 경우
				sum_of_subsets(i + 1, weight + w[i], total - w[i]);
				include[i] = FALSE; // 이번 값을 안 더하고 넘겼을 경우
				sum_of_subsets(i + 1, weight, total - w[i]);
			}
		}
	
}

	int promising(int i, int weight, int total) {
		return (weight + total >= W) && (weight == W || weight + w[i + 1] <= W); // 유망할 경우 TRUE 리턴 

	}