/*
����
ĳ�г�����վ���������ӽṹ��Figure 1��ʾ��

���У�AΪ��ڣ�BΪ���ڣ�SΪ��תä�ˡ�����������Ϊ���쵥��ʽ���г���ʻ�ķ���ֻ���Ǵ�A��S���ٴ�S��B�����⣬������������Ϊ�������S��פ�����������Ǵ�B��ʻ���Ĵ��򣬿������A��ʻ��Ĵ���ͬ������S���������ޣ�ͬʱפ���ĳ��᲻�ó���m�ڡ�

��ĳ�г��ɱ������Ϊ{1, 2, ..., n}��n�ڳ�����ɡ�����Աϣ��֪�����������Ͻ�ͨ������Щ�����ܷ���{a1, a2, ..., an}�Ĵ����������к��B��ʻ����������У�Ӧ��������

�Ĵ������?

����
�����С�

��һ��Ϊ��������n��m��

�ڶ���Ϊ�Կո�ָ���n����������֤Ϊ{1, 2, ..., n}��һ�����У���ʾ���жϿ����Ե�ʻ������{a1��a2��...��an}��

���
��ʻ�����п��У�������������У�����push��ʾ�����A����S��pop��ʾ�����S����B��ÿ������ռһ�С�

�������У������No��

����
Input
5 5
3 1 2 4 5

Output
No

����
1 �� n �� 1,600,000

0 �� m �� 1,600,000

ʱ�䣺2 sec

�ռ䣺256 MB
*/
#include <iostream>
#include <string>

using namespace std;

class MyStack {
public:
	int stack[16000001];

	int size;

	void push(int e) {
		stack[size + 1] = e;
		size++;
	}

	int pop() {
		int e = stack[size];
		stack[size] = 0;
		size--;
		return e;
	}

	int top() {
		int e = stack[size];
		return e;
	}

	bool empty() {
		return (size == -1)? true: false;
	}
};

int main() {
	int n, m;
	int size = -1;
	MyStack a, s, b;
	a.size = size;
	b.size = size;
	s.size = size;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a.stack[i];
	}

/*
	5 5         b=1 2 3 4 5
				a=3 2 4 1 5
				a=3 1 2 4 5
	s= 
	j=4
*/
	

	return 0;
}