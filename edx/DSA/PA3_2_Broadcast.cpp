/*
����
ĳ�㲥��˾Ҫ��һ�������������߹㲥����װ�á��õ�������n��С��ÿ��С��Ҫ��װһ̨����������Ÿ��ԵĽ�Ŀ��

�������ù�˾ֻ�����FM104.2��FM98.6�������ε���Ȩ����ʹ��ͬһ���εķ�����ụ����š���֪ÿ̨��������źŸ��Ƿ�Χ������ΪԲ�ģ�20kmΪ�뾶��Բ��������ˣ��������С��20km������С��ʹ��ͬ���Ĳ��Σ���ô���Ǿͻ����ڲ��θ��Ŷ��޷�����������Ŀ�����ڸ�����Щ����С��20km��С���б����жϸù�˾�ܷ�ʹ�����������ľ������������㲥��Ŀ��

����
��һ��Ϊ��������n��m���ֱ�ΪС��ĸ����Լ�������С��20km��С��Ե���Ŀ�� ��������m�У�ÿ��2����������ʾ����С��ľ���С��20km����Ŵ�1��ʼ����

���
����ܹ�����Ҫ�����1���������-1��

��������
4 3
1 2
1 3
2 4
�������
1
����
1 �� n �� 10000

1 �� m �� 30000

����Ҫ���Ǹ�����20kmС���б�Ŀռ����ԣ������Ƿ��������ǲ���ʽ���Ƿ����ô����Կ����Ƴ��������Ϣ�ȵȡ�

ʱ�䣺2 sec

�ռ䣺256MB

��ʾ
BFS
*/

#include <cstdio>
#include <cstdlib>
#define MAXN 10005
class Queue
{
private:
    int *_elem;
    int _capacity;
    int head, tail;
public:
 
    Queue(int c = MAXN)
    {
        _elem = new int[_capacity = c];
        for (int i = 0; i < _capacity; _elem[i++] = 0);
        head = 1;
        tail = 0;
    }
    
    int enQueue(int n)
    {
        _elem[++tail] = n;
        return n;
    }
    
    int deQueue()
    {
        return _elem[head++];
    }
    
    bool isEmpty()
    {
        return head > tail;
    }
    
    int getFront()
    {
        return _elem[head];
    }
    
    int getBack()
    {
        return _elem[tail];
    }
};


typedef struct edge
{
    edge *nextEdge;
    int to;
}edge;

typedef struct vertexNode
{
    int status;
    edge *firstEdge;
    
    vertexNode( int s = 0, edge *p = NULL):
    status(s), firstEdge(p){}
}vertexNode;

class graph
{
private:
    vertexNode *_vertexNodes;

    int _size;
public:
    graph()
    {
        _vertexNodes = new vertexNode[MAXN];
    }
    
    void createEdge(int start, int end)
    {
        edge *q = new edge;
        q->to = end;
        q->nextEdge = _vertexNodes[start].firstEdge;
        _vertexNodes[start].firstEdge = q;
    }
    
    void setSize(int n)
    {
        _size = n;
    }
    
    int bfs(int v)
    {
        Queue queue;
        int w, r;
        r = 1;
        _vertexNodes[v].status = 1;
        queue.enQueue(v);
       
        while (!queue.isEmpty())
        {
            v = queue.getFront();
            edge *q = _vertexNodes[v].firstEdge;
            if (_vertexNodes[v].firstEdge != NULL)
            {
                w = q->to;
                while (q != NULL)
                {
                    if (_vertexNodes[w].status == 0)
                    {_vertexNodes[w].status = -_vertexNodes[v].status; queue.enQueue(w);}
                    if (_vertexNodes[v].status == _vertexNodes[w].status) r = -1;
                    q = q->nextEdge;
                    if (q !=NULL)
                        w = q->to;
                }
            }
            queue.deQueue();
        }
        return r;
    }
    
    int BFS(int n)
    {
        int result = 1;
        for (int i = 1; i <= n; i++)
        {
            if (_vertexNodes[i].status == 0)
            {
                int r = bfs(i);
                if (r == -1) {result = -1; break;}
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[])
{
    int m, n;
    int start, end;
    scanf("%d %d", &n, &m);
    graph g;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &start, &end);
        g.createEdge(end, start);
        g.createEdge(start, end);
    }
    int result = g.BFS(n);
    printf("%d", result);
}