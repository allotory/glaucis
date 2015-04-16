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

#define L 16000001
int a[L]; 
int s[L];
int b[L];

int size = -1;

void push(int e) {
	s[size + 1] = e;
	size++;
}

int pop() {
	int e = s[size];
	s[size] = 0;
	size--;
	return e;
}

int top() {
	int e = s[size];
	return e;
}

bool empty() {
	return (size == -1)? true: false;
}


int main() {
	int n, m;
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		b[i] = i+1;
	}
/*
	5 5         b=1 2 3 4 5
				a=3 2 4 1 5
				a=3 1 2 4 5
	s= 
	j=4
*/
	string r = "";
	bool flag = true;
	int j = 0;
	for(int i=0; i<n; i++) {
		int e = a[i];
		int t;
		if(size > m) {
			flag = false;
			cout<<"No\n";
			break;
		}
		if(!empty()) {
			t = top();
			if(t != e && b[j] != e) {
				flag = false;
				cout<<"No\n";
				break;
			}else if(t == e){
				pop();
				r += "pop\n";
			}else if(b[j] == e){ 
				push(b[j]);
				r += "push\n";
				b[j] = 0;
				j = e;
				pop();
				r += "pop\n";
			}else {
				flag = false;
				cout<<"No\n";
				break;
			}
		}else {
			for(j; j<e; j++) {

				push(b[j]);
				r += "push\n";
				b[j] = 0;
			}
			j = e;
			pop();
			r += "pop\n";
		}
	}

	if(flag) {
		cout<<r<<endl;
	}
/*	
	for(int i=0; i<n; i++) {
		printf("%d", a[i]);
		printf("%d\n", b[i]);
	}

	
	
	for(int i=0; i<n; i++) {
		printf("%d\n", a[i]);
	}

	push(1);
	push(2);
	push(3);	
	for(int i=size; i>=0; i--) {
		printf("%d\n", s[i]);
	}
	int e = pop();
	printf("%d", e);
	for(int i=size; i>=0; i--) {
		printf("%d\n", s[i]);
	}
*/
	return 0;
}