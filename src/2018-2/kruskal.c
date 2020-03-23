#include<stdio.h>
#define N 7 // edge의 수
#define CNT_NODE 5// node 수
#define TRUE 1
#define FALSE 0

typedef struct _edge{
	int start_v, end_v;
	int weight;

}edge; // edge 자료형
void sort(edge*);
void setEdge(edge* e, int sv, int ev, int w){
	e->start_v = sv;
	e->end_v = ev;
	e->weight = w;
}//edge 데이터 입력 함수

void printf_e(edge e){ // edge의 두 vertice 출력 함수
	printf("(%d,%d) ", e.start_v, e.end_v);
}

typedef int set_pointer;
typedef struct _nodetype {
	int parent; 
	int depth;
}nodetype;

typedef nodetype universe[N];
universe U;
void makeset(int i){ U[i].parent = i; U[i].depth = 0; }

set_pointer find(int i){
	int j = i;
	while (U[j].parent != j)
		j = U[j].parent;
	return j;
}

void merge(set_pointer p, set_pointer q){
	if (U[p].depth == U[q].depth){
		U[p].depth = +1;
		U[q].parent = p;
	}
	else if (U[p].depth < U[q].depth){
		U[p].parent = q;
	}
	else U[q].parent = p;
}

int equal(set_pointer p, set_pointer q){
	if (p == q) return TRUE;
	else return FALSE;
}

void initial(int n){
	for (int i = 0; i < n; i++) makeset(i);
}

void kruskal(int n, int m, edge* E, edge* F);

int main(void){
	edge E[N], F[CNT_NODE-1]; //F에는 노드의 개수 -1개의 Edge가 들어간다.
	setEdge(&E[4], 1, 2, 1);
	setEdge(&E[6], 3, 5, 2);  setEdge(&E[2], 1, 3, 3); setEdge(&E[1], 2, 3, 3); setEdge(&E[0], 3, 4, 4);
	setEdge(&E[5], 4, 5, 5); setEdge(&E[3], 2, 4, 6); // 데이터 입력
	kruskal(5, N, E, F);// 크루스칼 알고리즘 실행
	printf("====F배열====\n"); 
	for (int cnt = 0; cnt < CNT_NODE-1; cnt++){ // F배열 출력
		printf_e(F[cnt]);
	}
	printf("\n");
	return 0;
}

void kruskal(int n, int m, edge* E, edge* F){
	int i, j, k = 0;
	int f_count = 0;
	set_pointer p, q;
	edge e;
	initial(n);
	sort(E); // 가중치 오름차순으로 정렬
	while (f_count<n-1){
		e = E[k];
		i = e.start_v-1;
		j = e.end_v-1;
		p = find(i);
		q = find(j);
		if (p != q){
			merge(p, q);
			F[f_count] = e;
			f_count++;
		}
		k++;
	}
}
void swap(edge* a, edge* b){
	edge temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void sort(edge* e){ // 가중치 정렬 함수
	for (int i = 0; i < N; i++){
		for (int j = i; j < N; j++){
			if (e[i].weight > e[j].weight){
				swap(&e[i], &e[j]);
			}
			else if (e[i].weight == e[j].weight){
				if (e[i].start_v > e[j].start_v){
					swap(&e[i], &e[j]);
				}
			}
		}
	}
}