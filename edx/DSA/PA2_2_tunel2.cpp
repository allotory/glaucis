#include<iostream>
using namespace std;

//�б�ڵ�λ��
#define ListNodePosi(T) ListNode<T>* 

//�б�ڵ�ģ���ࣨ��˫��������ʽʵ�֣�
template <typename T> 
struct ListNode { 
	// ��Ա ��ֵ��ǰ�������
	T data; 
	ListNodePosi(T) pred; 
	ListNodePosi(T) succ; 
	//���header��trailer�Ĺ���
	ListNode() {} 
};

//�б�ģ����
template <typename T> 
class List { 
private:
	//��ģ��ͷ�ڱ���β�ڱ�
	int _size; 
	ListNodePosi(T) header; 
	ListNodePosi(T) trailer; 
protected:
	//�б���ʱ��ʼ��
	void init() {
		//����ͷ�ڱ��ڵ�
		header = new ListNode<T>; 
		//����β�ڱ��ڵ�
		trailer = new ListNode<T>; 
		header->succ = trailer; 
		header->pred = NULL;
		trailer->pred = header; 
		trailer->succ = NULL;
		//��¼��ģ
		_size = 0; 
	}; 
public:
	// ���캯��
	List() { 
		init();
	} 
	//��e�����׽ڵ����
	ListNodePosi(T) insertAsFirst (T const& e) {
		_size++; 
		ListNodePosi(T) x = new ListNode<T>; //�����½ڵ�
		x->data = e;
		header->succ->pred = x;
		x->succ = header->succ;
		header->succ = x;
		x->pred = header;
		return x; 
	}; 
	//��e����ĩ�ڵ����
	ListNodePosi(T) insertAsLast (T const& e) {
		_size++; 
		ListNodePosi(T) x =  new ListNode<T>; //�����½ڵ�
		x->data = e;
		trailer->pred->succ = x;
		x->pred = trailer->pred;
		x->succ = trailer;
		trailer->pred = x;
		return x;
	}; 
	//�����Ϸ�λ��p���Ľڵ㣬���ر�ɾ���ڵ�
	T remove (ListNodePosi(T) p) {
		//���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ��
		T e = p->data; 
		//��̡�ǰ��
		p->pred->succ = p->succ; 
		p->succ->pred = p->pred; 
		//�ͷŽڵ㣬���¹�ģ
		delete p; 
		_size--; 
		//���ر��ݵ���ֵ
		return e; 
	}; 
	//�׽ڵ�λ��
	ListNodePosi(T) first() const { 
		return header->succ; 
	} 
	//ĩ�ڵ�λ��
	ListNodePosi(T) last() const { 
		return trailer->pred; 
	}
	//����
	void traverse() { 
		for (ListNodePosi(T) p = header->succ; p != trailer; p = p->succ) {
			//printf("%d", p->data);
			cout<<p->data<<endl;
		}
	}
	//��С
	int size() {
		return _size;
	}
};

//����ģ���ࣨ�̳�Listԭ�нӿڣ�
template <typename T> 
class Queue: public List<T> { 
public: 
	//size()��empty()�Լ��������Žӿھ���ֱ������
	void enqueue(T const& e) { 
		//��ӣ�β������
		insertAsLast (e); 
	} 
	//���ӣ��ײ�����
	T dequeue() { 
		return List<T>::remove(List<T>::first()); 
	} 
	//����
	ListNodePosi(T) front() { 
		return List<T>::first(); 
	} 
	//��β
	ListNodePosi(T) rear() { 
		return List<T>::last(); 
	} 
	//�Ƿ�Ϊ��
	bool empty() {
		return (List<T>::size()==0) ? true : false;
	}
};

//˫�˶���
template <typename T> 
class Deque: public List<T> {
public:
	//��ȡ��Ԫ��
	ListNodePosi(T) front() {
		return List<T>::first(); 
	}; 
	//��ȡĩԪ��
	ListNodePosi(T) rear() { 
		return List<T>::last();
	}; 
	//��Ԫ��e�嵽����ǰ��
	void insertFront(T const& e) {
		insertAsLast(e);
	}; 
	//��Ԫ��e�嵽����ĩ��
	void insertRear(T const& e) {
		insertAsLast(e); 
	}; 
	//ɾ�����е���Ԫ��
	T removeFront() {
		return List<T>::remove(List<T>::first()); 
	}; 
	//ɾ�����е�ĩԪ��
	T removeRear() {
		return List<T>::remove(List<T>::last()); 
	}; 
};

//�Ѷ�
template <typename T> 
class Queap {
private :
	Queue<int> queue;
	Deque<int> deque;
public :
	void enqueue(T const& e) { 
		queue.enqueue(e);
		deque.insertRear(e);
		for (ListNodePosi(T) p = deque.rear(); (p->pred != NULL) &&(p->data <= e); p = p->pred) {
			p->data = e;
		}
	} 
	T dequeue() { 
		T e = queue.dequeue();
		deque.removeFront();
		return e; 
	} 
	T getMax() {
		return deque.front()->data;
	}
};

/*int main() {

	//List<int> list;
	//list.insertAsFirst(11);
	//list.insertAsFirst(22);
	//list.insertAsFirst(33);
	//list.insertAsFirst(44);
	//list.insertAsLast(55);
	//list.insertAsLast(66);
	//list.remove(list.first());
	////list.remove(list.last());
	//list.traverse();
	//printf("%d", list.size());

	//Queue<int> queue;
	//queue.enqueue(11);
	//queue.enqueue(22);
	//queue.enqueue(33);
	//queue.enqueue(44);
	//printf("%d", queue.size());
	//queue.dequeue();
	//printf("%d", queue.size());
	//queue.traverse();

	//Deque<int> deque;
	//deque.insertAsFirst(11);
	//deque.insertAsFirst(22);
	//deque.insertAsFirst(33);
	//deque.insertAsFirst(44);
	//deque.insertAsLast(55);
	//printf("%d", deque.rear()->data);
	//printf("%d", deque.size());
	//deque.removeFront();
	//deque.traverse();
	//printf("%d", deque.size());
	//deque.removeRear();
	//printf("%d", deque.size());
	//deque.traverse();

	Queap<int> q;

	int n;
	cin>>n;
	for(int i = 0; i < n; i++) {
		char a;
		int x = 0;
		cin>>a;
		switch (a) {
			case'E':
				cin>>x;
				q.enqueue(x);
				break;
			case 'D':
				cout<<q.dequeue()<<endl;
				break;
			case 'M':
				cout<<q.getMax()<<endl;
				break;
		}

	}

	return 0;
}
*/