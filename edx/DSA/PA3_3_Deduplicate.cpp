/*
����
Epicure�������ڱ�׫һ����ʳ�ٿ�ȫ�顣Ϊ�ˣ����Ѵ��ڶ��ͬ���������Ѽ�����һ���߳�����ʳ�����嵥����ȻԴ�Զ���֮�֣�������Ȼ�����ظ����������ʱ�������ɸ����Epicure������˵������������϶����¶�����Բ����ǡ�һ��С�ˡ��������㲻��������ʳ�������������һ����

����
��1��Ϊ1������n����ʾ�����嵥�ĳ��ȡ�����n�и�Ϊһ������

���
���г����ظ�������������ظ��Ľ����һ�Σ�����������ԭ�嵥���״γ����ظ������ڶ��γ��֣���λ��Ϊ��

����
Input
10
brioche
camembert
cappelletti
savarin
cheddar
cappelletti
tortellni
croissant
brioche
mapotoufu

Output
cappelletti
brioche

����
1 < n < 6 * 10^5

��������Сд��ĸ��ɣ����������ַ�����ÿ��Ȳ�����40

ʱ�䣺2 sec

�ռ䣺256 MB

��ʾ
ɢ��
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define MAXN 600005

const int SZ = 1<<19;
struct fastio
{
    char inbuf[SZ];char outbuf[SZ];fastio()
    {//���������
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

struct Node
{
    char foodName[45];
    Node *next;
    Node *prev;
    bool appeared;
    
    Node()
    {
        foodName[0] = '\0';
        appeared = false;
        next = NULL;
        prev = NULL;
    }
};

class hashNode
{
private:
    int size;
    Node *head;
    Node *tail;
    void init()
    {
        size = 0;
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->prev = head;
    }

public:
    hashNode()
    {
        init();
    }
    
    void addNode(Node *p)
    {
        head->next->prev = p;
        p->next = head->next;
        head->next = p;
        p->prev = head;
        
        size++;
    }
    Node *getHead()
    {
        return head->next;
    }
    

    Node* inHashNodeList(Node *p)
    {
        Node *q = new Node;
        for (q = head; q != tail; q = q->next)
        {
            if (strcmp(q->foodName, p->foodName) == 0)
                return q;
        }
        return NULL;
    }
}foodList[MAXN];

int calHash(char key[])
{
    int h = 0;
    int i = 0;
    while (key[i] != '\0')
    {
        h = (h << 5)|(h >> 27);
        h += (int)key[i];
        i++;
    }
    h = h > 0 ? h: -h;
    return h % 350377;
}

int main(int argc, const char * argv[])
{
    int n, key;
    char temp[45];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &temp);
        key = calHash(temp);
        Node *food = new Node;
        strcpy(food->foodName, temp);
        
        Node *p = foodList[key].inHashNodeList(food);
        if (p == NULL)
        {
            foodList[key].addNode(food);
        }
        
        else
        {
            if (p->appeared == false)
            {
                printf("%s\n", food->foodName);
                p->appeared = true;
            }
        }
    }
    return 0;
}