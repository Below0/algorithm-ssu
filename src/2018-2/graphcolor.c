#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4 // 면 갯수
#define m 3 // 색깔 갯수

void m_coloring(int i);
int promising(int i);
int cnt = 0;
int cnt2 = 0;
int vcolor[SIZE] = { 0, };
int W[SIZE][SIZE] = {
	{ 0, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 1, 1, 0, 1 },
	{ 1, 0, 1, 0 }
};

int main(void){
	for (int i = 1; i <= m; i++){
		vcolor[0] = i; // 첫번째 면의 색을 정해놓고 
		m_coloring(0); // 알고리즘을 실행
		printf("\n");
	}
	return 0;
}

void m_coloring(int i) { // 컬러링 알고리즘
	int color;
	int k;
	if (promising(i) == TRUE){ // 유망성 검사
		if (i == SIZE - 1){
			for (k = 0; k < SIZE; k++){
				printf("%d ", vcolor[k]); // 모든 면의 색이 칠해졌을 때 출력한다.
			}
			printf("\n");
			return;
		}
		else{
			for (color = 1; color <= m; color++){
				vcolor[i + 1] = color; // 자식노드의 색을 칠함
				m_coloring(i + 1); // 자식노드로 옮겨간다.
			}
		}
	}
}

int promising(int i) {
	int j; 
	int swt = TRUE;
	j = 0;
	while (j<i && swt == TRUE) {
		if (W[i][j] && vcolor[i] == vcolor[j]){ // 면이 맞닿아있고 색이 같을 경우
			swt = FALSE; // 유망하지 않다.
		}
		j++;
	}
	return swt;
}