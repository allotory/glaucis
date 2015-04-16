/*
描述
祖玛是一款曾经风靡全球的游戏，其玩法是：在一条轨道上初始排列着若干个彩色珠子，其中任意三个相邻的珠子不会完全同色。此后，你可以发射珠子到轨道上并加入原有序列中。一旦有三个或更多同色的珠子变成相邻，它们就会立即消失。这类消除现象可能会连锁式发生，其间你将暂时不能发射珠子。

开发商最近准备为玩家写一个游戏过程的回放工具。他们已经在游戏内完成了过程记录的功能，而回放功能的实现则委托你来完成。

游戏过程的记录中，首先是轨道上初始的珠子序列，然后是玩家接下来所做的一系列操作。你的任务是，在各次操作之后及时计算出新的珠子序列。

输入
第一行是一个由大写字母'A'~'Z'组成的字符串，表示轨道上初始的珠子序列，不同的字母表示不同的颜色。

第二行是一个数字n，表示整个回放过程共有n次操作。

接下来的n行依次对应于各次操作。每次操作由一个数字k和一个大写字母Σ描述，以空格分隔。其中，Σ为新珠子的颜色。若插入前共有m颗珠子，则k ∈ [0, m]表示新珠子嵌入之后（尚未发生消除之前）在轨道上的位序。

输出
输出共n行，依次给出各次操作（及可能随即发生的消除现象）之后轨道上的珠子序列。

如果轨道上已没有珠子，则以“-”表示。

样例
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

限制
0 ≤ n ≤ 10^4

0 ≤ 初始珠子数量 ≤ 10^4

时间：2 sec

内存：256 MB

提示
列表
*/
#include <stdio.h>
#include "string.h"
#include <stdlib.h>

typedef struct Node {
	char data;
	struct Node *pred;
	struct Node *succ;
}List, *MyList;


MyList head = (MyList)malloc(sizeof(List));
MyList tail = (MyList)malloc(sizeof(List));


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

思路就是规则：
1、链式数据结构；

2、指定插入位置并插入一个数据；

3、从插入位置向链的两端延伸，直到遇到链的一端或者遇到与插入位置颜色不符的位置为止；

4、如果延伸量小于3，则不变；如果大于等于3，则将所有延伸区域内的所有数据全部删除，
	然后以原延伸区域的任意一个端点作为插入位置（无新的插入数据），
	继续判断新的延伸位置，直到链数据全部删除或者延伸量小于3为止。

5、重复2-4步，直到塞满所有位置或清空所有数据为止。
*/

void remove(int k) {	
	int i = -1;
	MyList p = head;
	while (i++ < k) {
		p = p->succ;
	}

	if((p->pred->data == p->data) && (p->data == p->succ->data)) { 
		p->pred->pred->succ = p->succ->succ;
		p->succ->succ->pred = p->pred->pred;
		delete p->pred;
		delete p->succ;
		delete p;
	}else if((p->pred->pred->data == p->pred->data) && (p->pred->data == p->data)) { 
		p->pred->pred->pred->succ = p->succ;
		p->succ->pred = p->pred->pred->pred;
		delete p->pred->pred;
		delete p->pred;
		delete p;
	}else if((p->data == p->succ->data) && (p->succ->succ->data)) {  
		p->pred->succ = p->succ->succ->succ;
		p->succ->succ->succ->pred = p->pred;
		delete p->succ->succ;
		delete p->succ;
		delete p;
	}
}


void display() {
	MyList p = head->succ;
	if(p == tail) {
		printf("%c", "-");
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