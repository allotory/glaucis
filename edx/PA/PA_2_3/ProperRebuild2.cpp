/*
����
һ����˵������������������������кͺ���������У�������ȷ��Ψһȷ���ö�������



��ͼһ��

����ͼһ�е����ö���������Ȼ�����ǲ�ͬ���������������ǵ����򡢺���������ж�����ͬ�ġ�

���Ƕ��ڡ������������ÿ���ڲ��ڵ㶼���������ӵĶ��������������������򡢺����������������ȫȷ�����Ľṹ��

����������n���ڵ���[1, n]�ڵ��������б�ţ�����һ��������������򡢺���������У��������������������С�

����
��һ��Ϊһ������n�����������нڵ�ĸ�����

�ڶ�������Ϊ��֪�����򡢺���������С�

���
��һ�У������������������������С�

����
Input
5
1 2 4 5 3
4 5 2 3 1
Output
4 2 5 1 3

����
����95%�Ĳ�����1 �� n �� 1,000,000

����100%�Ĳ�����1 �� n �� 4,000,000

�����������{1,2...n}�����У��Ҷ�Ӧ��һ�úϷ����������

ʱ�䣺2 sec

�ռ䣺256 MB

��ʾ


�۲����Һ��������򡢺�����������е�λ��

������Ƶ05e5-3
*/

#include<stdio.h>

int preOrder2[4000000];
int postOrder2[4000000];

struct BinNode { 
	int data; 
	BinNode* lc; 
	BinNode* rc; 
};

//��������ع�
BinNode* properRebuild(int preOrder[], int postOrder[], int n) {
	//ֻ��һ�����ڵ�
	if(n == 1) {
		BinNode* root = new BinNode();
		root->data = preOrder[0];
		root->lc = NULL;
		root->rc = NULL;
		return root;
	}

	//���ڵ�
	BinNode* root = new BinNode();
	root->data = preOrder[0];

	//�������������ֽ�λ��
	int posi;
	for(posi = 0; posi < n; posi++) {
		if(*(preOrder+1) == postOrder[posi]) {
			break;
		}
	}

	//����������
	int n_temp = n - 1 - (posi + 1);

	root->lc = properRebuild(preOrder+1, postOrder, posi+1);
	root->rc = properRebuild(preOrder+1+(posi+1), postOrder+(posi+1), n_temp);

	return root;
};

//�������������
void travIn_R(BinNode* x) { 
	if (!x) return;
	travIn_R(x->lc);
	printf("%d ", x->data);
	travIn_R(x->rc);
};


int main() {
	int n;
    scanf("%d", &n);
	for (int i = 0; i < n; i++){
        scanf("%d", &preOrder2[i]);
	}
	for (int i = 0; i < n; i++){
        scanf("%d", &postOrder2[i]);
	}
    BinNode* b = properRebuild(preOrder2, postOrder2, n);
    travIn_R(b);
	return 0;
}
