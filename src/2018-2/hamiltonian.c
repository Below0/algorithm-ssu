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
	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]]){ // n-1���� ������ �������� �������� ������������ ��ΰ� ���� ��
		swt = FALSE;
	}
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]]){// ���� ������ ���� ������ �� �̾��� ���
		swt = FALSE;
	}
	else{
		swt = TRUE;
		j = 0;
		while (j < i && swt){ 
			if (vindex[i] == vindex[j]) swt = FALSE; // �ռ� ������ ������ �� ���� ��� FALSE
			j++;
		}
	}
	return swt; // ��� ����
}

void hamiltonian(int i){
	int j;
	if (promising(i)){
		if (i == n - 1){ // ���������� ������ ���
			for (j = 0; j < SIZE; j++) printf("%d ", vindex[j]); // ������ ���� ���
			printf("\n");
		}
		else{
			for (j = 1; j < n; j++){ //�������� ������ ������ ������ �ִ´�.
				vindex[i + 1] = j;
				hamiltonian(i + 1);// �ع���Ͼ� �Լ� �� ȣ��
			}
		}
	}
}

int main(void){
	vindex[0] = 0; // �������� 0�� ����
	hamiltonian(0);

	return 0;
}