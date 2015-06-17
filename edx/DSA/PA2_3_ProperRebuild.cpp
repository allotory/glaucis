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

struct BinNode{
    int data;
    BinNode *lChild;
    BinNode *rChild;
};

BinNode* reBuildTree(int preOrder[], int postOrder[], int length){
    if (length == 1){
        BinNode *T = new BinNode;
        T->data = preOrder[0];
        T->lChild = NULL;
        T->rChild = NULL;
        return T;
    }
    BinNode *T = new BinNode;
    T->data = preOrder[0];
    
    int pos = 0;
    for (; pos < length; pos ++){
        if (postOrder[pos] == *(preOrder + 1))
            break;
    }
    
    int l2 = length-1-(pos + 1);

    T->lChild = reBuildTree(preOrder+1, postOrder, pos + 1);
    T->rChild = reBuildTree(preOrder+1+(pos+1), postOrder+pos+1, l2);
    return T;
}

void inTraverse(BinNode * T){
    if (!T) return;
    inTraverse(T->lChild);
    printf("%d ", T->data);
    inTraverse(T->rChild);
}
int preOrder1[4000000];
int postOrder1[4000000];
/*
int main(){

    int n;
    scanf("%d", &n);
	for (int i = 0; i < n; i++){
        scanf("%d", &preOrder1[i]);
	}
	for (int i = 0; i < n; i++){
        scanf("%d", &postOrder1[i]);
	}
    BinNode *T = reBuildTree(preOrder1, postOrder1, n);
    inTraverse(T);
}*/