#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4

int n = SIZE;

int W[SIZE][SIZE] = {
	{0, 1, 0, 1},
	{1, 0, 1, 0},
	{0, 1, 0, 1},
	{1, 0, 1, 0}
};
int vindex[SIZE];

int promising(int i){
	int j; int swt;
	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]]){ // n-1개의 지점을 지났으나 마지막에 시작점으로의 경로가 없을 때
		swt = FALSE;
	}
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]]){// 현재 지점과 다음 지점이 안 이어질 경우
		swt = FALSE;
	}
	else{
		swt = TRUE;
		j = 0;
		while (j < i && swt){ 
			if (vindex[i] == vindex[j]) swt = FALSE; // 앞서 지나온 지점을 또 지날 경우 FALSE
			j++;
		}
	}
	return swt; // 결과 리턴
}

void hamiltonian(int i){
	int j;
	if (promising(i)){
		if (i == n - 1){ // 정상적으로 돌았을 경우
			for (j = 0; j < SIZE; j++) printf("%d ", vindex[j]); // 지나온 지점 출력
			printf("\n");
		}
		else{
			for (j = 1; j < n; j++){ //시작점을 제외한 나머지 지점을 넣는다.
				vindex[i + 1] = j;
				hamiltonian(i + 1);// 해밀토니안 함수 재 호출
			}
		}
	}
}

int main(void){
	vindex[0] = 0; // 시작점은 0을 기준
	hamiltonian(0);

	return 0;
}