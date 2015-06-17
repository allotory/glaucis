/*
����
������һ����������ȫ�����Ϸ�����淨�ǣ���һ������ϳ�ʼ���������ɸ���ɫ���ӣ����������������ڵ����Ӳ�����ȫͬɫ���˺�����Է������ӵ�����ϲ�����ԭ�������С�һ�������������ͬɫ�����ӱ�����ڣ����Ǿͻ�������ʧ����������������ܻ�����ʽ����������㽫��ʱ���ܷ������ӡ�

���������׼��Ϊ���дһ����Ϸ���̵ĻطŹ��ߡ������Ѿ�����Ϸ������˹��̼�¼�Ĺ��ܣ����طŹ��ܵ�ʵ����ί��������ɡ�

��Ϸ���̵ļ�¼�У������ǹ���ϳ�ʼ���������У�Ȼ������ҽ�����������һϵ�в�������������ǣ��ڸ��β���֮��ʱ������µ��������С�

����
��һ����һ���ɴ�д��ĸ'A'~'Z'��ɵ��ַ�������ʾ����ϳ�ʼ���������У���ͬ����ĸ��ʾ��ͬ����ɫ��

�ڶ�����һ������n����ʾ�����طŹ��̹���n�β�����

��������n�����ζ�Ӧ�ڸ��β�����ÿ�β�����һ������k��һ����д��ĸ���������Կո�ָ������У���Ϊ�����ӵ���ɫ��������ǰ����m�����ӣ���k �� [0, m]��ʾ������Ƕ��֮����δ��������֮ǰ���ڹ���ϵ�λ��

���
�����n�У����θ������β������������漴��������������֮�����ϵ��������С�

����������û�����ӣ����ԡ�-����ʾ��

����
	Input:
		ACCBA
		5
		1 B
		0 A
		2 B
		4 C
		0 A
	Output:
		ABCCBA
		AABCCBA
		AABBCCBA
		-
		A

����
0 �� n �� 10^4

0 �� ��ʼ�������� �� 10^4

ʱ�䣺2 sec

�ڴ棺256 MB

��ʾ
�б�
*/

#include <stdio.h>
#include "string.h"
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node *pred;
	struct Node *succ;
}List, *MyList;

// ����ͷβ�ڵ�
MyList head = (MyList)malloc(sizeof(List));
MyList tail = (MyList)malloc(sizeof(List));

//��ʼ��
void init(char *a, int n) {

	head->pred = NULL;
	head->succ = tail;
	head->data = '-';
	tail->pred = head;
	tail->succ = NULL;
	tail->data = '-';

	MyList p = head;

	for(int i=0; i<n; i++) {
		 MyList node  = new Node();
		 node->data = a[i];
		 node->pred = p;
		 node->succ = p->succ;
		 p->succ->pred = node;
		 p->succ = node;
		 p = node;
	}
}

// ���ڵ���뵽��indexλ��֮ǰ
int insert(int k, char t) {
	int i = -1;
	MyList p = head;
	while (i++ < k) {
		p = p->succ;
	}

	MyList node = (MyList)malloc(sizeof(List));
	node->data = t;
	node->pred = p->pred;
	node->succ = p;
	p->pred->succ = node;
	p->pred = node;

	return 0;
}
/*
  0123456789
  accde
  1 b
  abccde
		0123456789
  		AABBCCBA
		4 C
		AABBcCCBA
*/
//�ж�ɾ���ڵ�
void remove(int k) {	
	MyList p1 = NULL, p2 = NULL, p3 = NULL, p4 = NULL, p = head;
	MyList begin = head, end = tail;
	bool b = true;
	int repeat, i = -1;

	// find position
	while (i++ < k - 2) {
		p = p->succ;
	}

	//init for 'begin' and 'end'
	begin = p; 
	end = p; 
	i = 0;
	while (i++ < 4 && end->succ != tail) {
		end = end->succ;
	}

	while (b && p != tail) {
		b = false; 
		repeat = 1;
		while (p != end) {
			p = p->succ;

			if (p->pred->data == p->data) {
				repeat++;
			}else {
				repeat = 1;
			}

			if (repeat == 3) {
				b = true;
				if (p->data == p->succ->data) {
					repeat++;
					p = p->succ;
				}

				if (repeat == 3) {
					p3 = p; 
					p2 = p3->pred; 
					p1 = p2->pred;
					p1->pred->succ = p3->succ;
					p3->succ->pred = p1->pred;
					p = p->succ;
					delete p1; 
					delete p2; 
					delete p3;
				 } else {
					p4 = p; 
					p3 = p4->pred; 
					p2 = p3->pred; 
					p1 = p2->pred;
					p1->pred->succ = p4->succ;
					p4->succ->pred = p1->pred;
					p = p->succ;
					delete p1; 
					delete p2; 
					delete p3; 
					delete p4;
				 }
				break;
			}
		}

		if (b && p != tail) {
			 begin = p; 
			 i = 0;
			 while (i++ < 2 && begin->pred != head) {
				 begin = begin->pred;
			 }
			 end = p; 
			 i = 0;
			 if (i++ < 1 && end->succ != tail){
				 end = end->succ;
			 }
			 p = begin;
		 }
	}
}

// ���ڵ���뵽��indexλ��֮ǰ
void display() {
	MyList p = head->succ;
	if(p == tail) {
		printf("-");
	}else {
		while(p->succ != NULL) {
			printf("%c", p->data);
			p = p->succ;
		}
	}
	printf("\n");
}

int main() {
	char a[10005];
	int n;

	scanf("%s", &a);
	init(a, strlen(a));
	scanf("%d", &n);

	for(int i=0; i<n; i++) {
		int k;
		char t;

		scanf("%d %c", &k, &t);
		insert(k, t);
		remove(k);
		display();
	}


	//scanf("%d\n", &n);


/*
	for(int i = 0; i<10; i++) {
		printf("%c", a[i]);
	}

	for(int i = 0; i<n; i++) {	
		scanf("%d\n", &k);
		printf("-%d\n", k);
	}
*/
	return 0;
}