/*
����
��������n���㣬������һ������ [a, b]���Լ����������ڵĵ�����

����
��һ�а��������������������n����ѯ�Ĵ���m��

�ڶ��а���n������Ϊ����������ꡣ

����m�У�������������������ѯ��������ұ߽�a��b��

���
��ÿ�β�ѯ��������ڱ�����[a, b]�ڵ�ĸ�����

����
Input
5 2
1 3 7 9 11
4 6
7 12
Output
0
3

����
0 �� n, m �� 5��105

���ڴβ�ѯ������[a, b]������a �� b

��������껥��

��������ꡢ��ѯ����ı߽�a��b����Ϊ������10^7�ķǸ�����

ʱ�䣺2 sec

�ڴ棺256 MB
*/
#include <stdio.h>
#include <stdlib.h>

#define L 500005 
int arr[L]; 

int compare(const void *a, const void *b) {
    int *pa = (int*)a;
    int *pb = (int*)b;
	//��С��������
    return (*pa )- (*pb);  
}

/*
	���ֲ��ҷ���ֵΪ�����ڲ���Ԫ�ص����Ԫ�ص��±꣬
	�ʲ�����߽�aʱ�����aǡ�ñ��ҵ��������ս����Ҫ+1����ͬ��left-1��
*/
int find(int low, int high, int *arr, int key) {  
    while(low < high) {  
        int mid = (low + high) >> 1;  
        (key < arr[mid]) ? high = mid : low = mid+1;  
    }  
    return --low;  
} 

void range(int n, int m) {
	for(int i=0; i<m; i++) {
		int count = 0;
		int a, b;
		scanf("%d %d", &a, &b);
		int left = find(0, n, arr, a);
		int right = find(0, n, arr, b);
		//printf("%d %d\n", left, right);
		if(arr[left] == a && left >= 0) {
			left--;
		}
		printf("%d\n", (right-left));
	}
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m); 

	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	//��������
	qsort(arr, n, sizeof(int), compare);
	//for(int i = 0; i<n; i++) {
	//	printf("%d ", arr[i]);
	//}
	range(n, m);
	return 0;
}