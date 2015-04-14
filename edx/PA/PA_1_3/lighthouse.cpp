/*
����
��������������Ϊ��·��ֻ������
��ͼһ��ʾ��ÿ������������һյ̽�յƣ������䶫�������������Զ���ֱ������̽�յƵĹ���֮�����Ը����κξ��롣�������������֮С�����Լٶ����ǲ���˴��ڵ���
������A��B���ڶԷ���������Χ�ڣ���������ܹ������˴ˡ�������ͼ����ʵ���У�����������������˴ˣ������̵������ǣ��졢�̵���Ҳ���ǡ�

���ڣ������κ�һ������ĵ����������������ж��ٶԵ����ܹ������˴ˡ�

����
��n+1�С�

��1��Ϊ1������n����ʾ������������

��2��n+1��ÿ�а���2������x, y���ֱ��ʾ�������ĺᡢ�����ꡣ

���
1����������ʾ�������˴˵ĵ����Ե�������

����
Input
3
2 2
4 3
5 1
Output
1

����
����90%�Ĳ�����1 �� n �� 3��105

����95%�Ĳ�����1 �� n �� 106

ȫ��������1 �� n �� 4��106

����������x, y���������Ҳ�ͬ������x, y���������

1 �� x, y �� 10^8

ʱ�䣺2 sec

�ڴ棺256 MB

��ʾ
ע����������ͱ����ķ�Χ��C/C++�е�int����ͨ���������32λ�������䷶ΧΪ[-231, 231 - 1]����һ���㹻���ɱ���������

*/

#include <stdio.h>  
#include <stdlib.h>  
  
#define MAXN 200002  
  
typedef struct P {  
    long x;  
    long y;  
}Point;  
  
Point p[MAXN];  
long A[MAXN];  
long cunt=0;  
long L[MAXN],R[MAXN];  
const long M=999999999;  
  
//���� x ��ֵ��С���󽫽ṹ������  
int cmp(const void *a,const void *b) {  
     return (*(Point*)a).x > (*(Point*)b).x ? 1 : -1;  
}  
  
void Merge(long Left,long Middle,long Right) {  
    long n1=Middle-Left+1;  
    long n2=Right-Middle;  
  
    long i,k;  
	for(i=1;i<=n1;i++) { 
        L[i]=A[Left+i-1];
	}
	for(i=1;i<=n2;i++) {
        R[i]=A[Middle+i];
	}
  
    L[n1+1]=M;  
    R[n2+1]=M;  
  
    i=1;  
    long j=1;  
    for(k=Left;k<=Right;k++) {  
		if(L[i]<=R[j]) { 
            A[k]=L[i++];
		} else{  
            A[k]=R[j++];  
            cunt+=n1-i+1;                 //cuntΪȫ�ֱ���  
        }  
    }  
}  
  
void Merge_sort(long Left,long Right) {  
    long Middle;  
    if(Left<Right) {  
        Middle=(Left+Right) >> 1;   
        Merge_sort(Left,Middle);    // ���ַֽ��󲿷�  
        Merge_sort(Middle+1,Right); // ���ַֽ��в���  
        Merge(Left,Middle,Right);   //�ϲ�������  
    }  
}  
  
int main() {  
    long n;  
    scanf("%d", &n);  
      
    long i;  
	for(i=0; i<n; i++) { 
        scanf("%d%d",&p[i].x,&p[i].y);  
	}
        
    //���� x �����������  
    qsort(p,n,sizeof(p[0]),cmp);  
  
	for(i=0;i<n;i++) { 
        A[i+1]=p[i].y;
	}
  
    Merge_sort(1,n);  
  
    long tmp=(n*(n-1)) >> 1;  
    printf("%ld\n",tmp-cunt);  
      
    return 0;  
}  
