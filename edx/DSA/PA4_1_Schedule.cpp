/*
����
ĳ�����ܼ��㼯Ⱥ��HPC cluster�����õ�������������ڲ�ͬ��Ϊ��������ٶ��ü�Ⱥ��֧�ֶ�����ͬʱִ�У���ͬһʱ��ֻ�е���������ִ��״̬����ʼ״̬�£�ÿ�������ɳ������ȼ�����һ������ָ�����ȼ�������ֵԽС���ȼ�Խ�ߣ������ȼ�����ȣ���������ASCII�ֵ�˳��������ȡ��˺�CPU����Դ���Ǳ����ȼ�����С������ռ�ã�ÿһ���������ϣ���ѡȡ���ȼ�����С��һ���񡣲���������������ڼ��������ͨ�����������˳������ǽ����ȼ����ӱ����ӱ����������ʱ����Ժ��ԣ�������������ȣ�ֻ�������ȼ�����С��2^32ʱ���������˳�

��������ǣ����ݳ�ʼ���ȼ����ã�������������ԭ��Ԥ��һ�����������ִ�����С�

����
��һ��Ϊ�Կո�ָ�����������n��m��nΪ��ʼʱ������������mΪ��Ԥ�������ִ�����г��ȣ�ÿ��ĩβ��һ�����з�

����n�зֱ����һ��������һ���ɲ�����8��Сд��ĸ��������ɵ��ַ�����ǰ��Ϊ����ĳ�ʼ���ȼ���������Ϊ�����������ֺ��ַ���֮���Կո�ָ�

���
���m�У�����һ���ַ�������ִ�д���ֱ����ִ��������ǰm����������ƣ���ִ����������m����ô��������������������ǰ���������񼴿ɡ�

����
Input
3 3
1 hello
2 world
10 test

Output
hello
hello
world

����
0 �� n �� 4,000,000

0 �� m �� 2,000,000

0 < ÿ������ĳ�ʼ���ȼ� < 2^32

����������������

ʱ�䣺2 sec

�ڴ棺512 MB

��ʾ
���ȼ�����
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 10000005
#define  InHeap(n, i)      ( ( ( -1 ) < ( i ) ) && ( ( i ) < ( n ) ) )
#define  Parent(i)         ( ( i - 1 ) >> 1 )
#define  LastInternal(n)   Parent( n - 1 )
#define  LChild(i)         ( 1 + ( ( i ) << 1 ) )
#define  RChild(i)         ( ( 1 + ( i ) ) << 1 )
#define  ParentValid(i)    ( 0 < i )
#define  LChildValid(n, i) InHeap( n, LChild( i ) )
#define  RChildValid(n, i) InHeap( n, RChild( i ) )
#define  Smaller(PQ, i, j)  (  (PQ[i]) < (PQ[j])  ? (i) : (j) )
#define  ProperParent(PQ, n, i) \
( RChildValid(n, i) ? Smaller( PQ, Smaller( PQ, i, LChild(i) ), RChild(i) ) : \
( LChildValid(n, i) ? Smaller( PQ, i, LChild(i) ) : i ))


const int SZ = 1<<19;
struct fastio
{
    char inbuf[SZ];char outbuf[SZ];fastio()
    {
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

struct Node
{
    long long priority;
    char name[10];
    
    bool operator < (const Node &a)
    {
        if (priority < a.priority)
            return true;
        else if (priority == a.priority)
        {
            int temp = 0;
            while (name[temp] == a.name[temp])
            {
                temp++;
            }
            if (name[temp] < a.name[temp])
                return true;
        }
        return false;
    }
};

void swap(Node &a, Node &b)
{
    Node temp = a;
    a = b;
    b = temp;
}

int percolateDown(int n, int i, Node *_elem)
{
    int j;
    j = ProperParent(_elem, n ,i);
    while (i != j)
    {
        swap(_elem[i], _elem[j]);
        i = j;
        j = ProperParent(_elem, n ,i);
    }
    
    return i;
}

void heapify(int n, Node *_elem)
{
    for ( int i = LastInternal ( n ); InHeap ( n, i ); i-- )
        percolateDown(n, i, _elem);
}
Node task[MAXN];
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %s", &task[i].priority, &task[i].name);
    }
    heapify(n, task);
    int count_1 = 0;
    int size = n;
    while (size > 0 && count_1 < m)
    {
        printf("%s\n", task[0].name);
        count_1++;
        task[0].priority = task[0].priority * 2;
        if (task[0].priority >= 4294967296)
        {
            swap(task[0], task[size-1]);
            size--;
        }
        percolateDown(size, 0, task);
    }
}