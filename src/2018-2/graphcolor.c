#include<stdio.h>

#define TRUE 1
#define FALSE 0
#define SIZE 4 // �� ����
#define m 3 // ���� ����

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
		vcolor[0] = i; // ù��° ���� ���� ���س��� 
		m_coloring(0); // �˰����� ����
		printf("\n");
	}
	return 0;
}

void m_coloring(int i) { // �÷��� �˰���
	int color;
	int k;
	if (promising(i) == TRUE){ // ������ �˻�
		if (i == SIZE - 1){
			for (k = 0; k < SIZE; k++){
				printf("%d ", vcolor[k]); // ��� ���� ���� ĥ������ �� ����Ѵ�.
			}
			printf("\n");
			return;
		}
		else{
			for (color = 1; color <= m; color++){
				vcolor[i + 1] = color; // �ڽĳ���� ���� ĥ��
				m_coloring(i + 1); // �ڽĳ��� �Űܰ���.
			}
		}
	}
}

int promising(int i) {
	int j; 
	int swt = TRUE;
	j = 0;
	while (j<i && swt == TRUE) {
		if (W[i][j] && vcolor[i] == vcolor[j]){ // ���� �´���ְ� ���� ���� ���
			swt = FALSE; // �������� �ʴ�.
		}
		j++;
	}
	return swt;
}