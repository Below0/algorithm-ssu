#include<stdio.h>
#include<stdlib.h>
#define NODE_SIZE 5 // 노드의 개수
typedef struct _edge{
	int start_v, end_v;
	int weight;

}edge; // edge 자료형
void setEdge(edge* e, int sv, int ev, int w){
	e->start_v = sv;
	e->end_v = ev;
	e->weight = w;
}//edge 데이터 입력 함수
void printf_e(edge e){ // edge의 두 vertice 출력 함수
	printf("(%d,%d) ", e.start_v, e.end_v);
}
void dijkstra(int n, int W[][NODE_SIZE], edge* F);
int main(){
	int W[NODE_SIZE][NODE_SIZE] = { //그래프 정보 입력
		{0, 7, 4, 6, 1},
		{999, 0, 999, 999, 999},
		{999, 2, 0, 5, 999},
		{999, 3, 999, 0, 999},
		{999, 999, 999, 1, 0}
	};

	edge F[NODE_SIZE-1];
	dijkstra(NODE_SIZE, W, F);
	printf("-------F배열-------\n"); // 결과 출력
	for (int i = 0; i < NODE_SIZE - 1; i++) 
		printf_e(F[i]);
	printf("\n");
	return 0;
}

void dijkstra(int n, int W[][NODE_SIZE], edge* F){ // dijkstra 알고리즘
	int i, j, vnear;
	int cnt = 0;
	edge e;
	int* touch = (int*)malloc(sizeof(int)*(n-1)); // touch[n-1] 선언
	int* length = (int*)malloc(sizeof(int)*(n-1));// length[n-1] 선언
	for (i = 0; i < n-1; i++){
		touch[i] = 1;
		length[i] = W[0][i+1];
	} // 초기 설정
	
	int min;
	for (i = 0; i < n - 1; i++){
		min = 999; // min = "infinite"
		for (j = 0; j < n - 1; j++){
			if (0 <= length[j] && length[j] <= min){
				min = length[j];
				vnear = j + 2; // 집합의 값과 실제 값을 맞춰주기 위해 +2
			}
		}
		setEdge(&e, touch[vnear - 2], vnear, length[vnear - 2]); // 이번 단계에서 해당하는 엣지 정보설정
		F[cnt++] = e;// 해당하는 e를 F집합에 넣는다.
		for (j = 0; j < n - 1; j++){ // 해당 노드를 거친 가중치가 더 짧을 경우를 생각해 length와 touch를 초기화 시켜준다.
			if (length[vnear - 2] + W[vnear - 1][j+1] < length[j]){
				length[j] = length[vnear - 2] + W[vnear - 1][j+1];
				touch[j] = vnear;
			}
		}
		length[vnear - 2] = -1; // 연결된 노드는 -1로 바꿔준다.

	}

}