#include<stdio.h>
#include<stdlib.h>
#define NODE_SIZE 5 // ����� ����
typedef struct _edge{
	int start_v, end_v;
	int weight;

}edge; // edge �ڷ���
void setEdge(edge* e, int sv, int ev, int w){
	e->start_v = sv;
	e->end_v = ev;
	e->weight = w;
}//edge ������ �Է� �Լ�
void printf_e(edge e){ // edge�� �� vertice ��� �Լ�
	printf("(%d,%d) ", e.start_v, e.end_v);
}
void dijkstra(int n, int W[][NODE_SIZE], edge* F);
int main(){
	int W[NODE_SIZE][NODE_SIZE] = { //�׷��� ���� �Է�
		{0, 7, 4, 6, 1},
		{999, 0, 999, 999, 999},
		{999, 2, 0, 5, 999},
		{999, 3, 999, 0, 999},
		{999, 999, 999, 1, 0}
	};

	edge F[NODE_SIZE-1];
	dijkstra(NODE_SIZE, W, F);
	printf("-------F�迭-------\n"); // ��� ���
	for (int i = 0; i < NODE_SIZE - 1; i++) 
		printf_e(F[i]);
	printf("\n");
	return 0;
}

void dijkstra(int n, int W[][NODE_SIZE], edge* F){ // dijkstra �˰���
	int i, j, vnear;
	int cnt = 0;
	edge e;
	int* touch = (int*)malloc(sizeof(int)*(n-1)); // touch[n-1] ����
	int* length = (int*)malloc(sizeof(int)*(n-1));// length[n-1] ����
	for (i = 0; i < n-1; i++){
		touch[i] = 1;
		length[i] = W[0][i+1];
	} // �ʱ� ����
	
	int min;
	for (i = 0; i < n - 1; i++){
		min = 999; // min = "infinite"
		for (j = 0; j < n - 1; j++){
			if (0 <= length[j] && length[j] <= min){
				min = length[j];
				vnear = j + 2; // ������ ���� ���� ���� �����ֱ� ���� +2
			}
		}
		setEdge(&e, touch[vnear - 2], vnear, length[vnear - 2]); // �̹� �ܰ迡�� �ش��ϴ� ���� ��������
		F[cnt++] = e;// �ش��ϴ� e�� F���տ� �ִ´�.
		for (j = 0; j < n - 1; j++){ // �ش� ��带 ��ģ ����ġ�� �� ª�� ��츦 ������ length�� touch�� �ʱ�ȭ �����ش�.
			if (length[vnear - 2] + W[vnear - 1][j+1] < length[j]){
				length[j] = length[vnear - 2] + W[vnear - 1][j+1];
				touch[j] = vnear;
			}
		}
		length[vnear - 2] = -1; // ����� ���� -1�� �ٲ��ش�.

	}

}