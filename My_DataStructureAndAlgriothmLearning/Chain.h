#pragma once
//using namespace std;

//要使用友元，必须先声明才行，另外，typename 和class通常没什么区别
template<typename T> class Chain;
template<class T> class ChainIterator;

template <class T>
class ChainNode {
	friend class Chain<T>;
private:
	T data;
	ChainNode<T> *link;
};

template<class T>
class Chain {
private:
	ChainNode<T> *first; // 指向第一个节点的指针
public:
	Chain() { first = NULL; };
	~Chain();
	bool IsEmpty() const { return first == 0; }
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(std::ostream& out) const;

	void Erase();
	Chain<T>& Append(const T&x);

};


template<class T>
Chain<T>::~Chain()
{// 链表的析构函数，用于删除链表中的所有节点
	ChainNode<T> *next; // 下一个节点
	while (first) {
		next = first->link;
		delete first;
		first = next;
	}
}

template<class T>
int Chain<T>::Length()const
{
	ChainNode<T> *current = first;
	int len = 0;
	while (current) {
		len++;
		current = current->link;
	}
	return len;
}

template <class T>void swappp(T& a, T& b) {}

template<class T>
bool Chain<T>::Find(int k, T&x)const
{
	if (k < 1)return false;
	Chain<T>* current = first;
	int index = 1;//索引
	while (index < k && current)
	{
		current = current->link;
		index++;
	}
	if (current)
	{
		x = current->data;
		return true;
	}
	else return false;
}

template<class T>
int Chain<T>::Search(const T& x)const
{ //寻找x，发现x，则返回x的地址，否则返回0
	ChainNode<T>* current = first;
	int index = 1;
	while (current && current->data != x)
	{
		current = current->link;
		index++;
	}
	if (current) return index;
	return 0;
}

template<class T>
void Chain<T>::Output(std::ostream& out)const
{
	//将链表元素送至输出流
	Chain<T>* current;
	for (current = first; current; current = current->link)
		out << current->data << " ";
}

//重载<<
template<class T>
std::ostream& operator<<(std::ostream&out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}

//从链表中删除一个元素
template<class T>
Chain<T>& Chain<T>::Delete(int k, T&x)
{
	//把第k个元素取至x，然后从链表中删除第k个元素
	//如果不存在第k个元素，则引发异常OutOfBounds()
	if (k < 1 || !first)
	{
		throw OutOfBounds();
	}

	ChainNode<T>* p = first;

	//q定位第k-1个位置,p定位第k个位置
	if (k == 1) first = first->link;
	else {
		ChainNode<T>*q = first;
		for (int index = 1; index < k - 1 && q; index++)
			q = q->link;

		if (!q || !q->link)
			throw OutOfBounds();

		p = q->link;
		q->link = p->link;
	}
	//获取数据后，删除
	x = p->data;
	delete p;
	return *this;

}

template<class T>
Chain<T>& Chain<T>::Insert(int k,const T&x)
{
	if (k < 0) throw OutOfBounds();

	ChainNode<T> *p=first;

	for (int index = 1; index < k &&p; index++)
		p = p->link;
	if (k > 0 && !p) throw OutOfBounds();//不存在第k个元素，否则插入

	ChainNode<T>* y = new ChainNode<T>;
	y->data = x; //没有定义构造函数，因此只能直接赋值
	if (k) { //在p之后插入
		y->link = p->link;
		p->link = y;
	}
	else { //k=0,作为第一个元素插入
		y->link = first;
		first = y;
	}

	return *this;
}

template<class T>
void Chain<T>::Erase()
{
	ChainNode<T> *next;
	while (first)
	{
		next = first->link;
		delete first;
		first = next;

	}
}

template<class T>
Chain<T>& Chain<T>::Append(const T& x)
{
	//在链表末尾添加元素x

	ChainNode<T> * node_x =new ChainNode<T>;
	node_x->data = x;
	node_x->link = NULL;
	
	ChainNode<T>* p = first;

	if (first)
	{ //链表非空
		while (p)
		{
			p = p->link;
		}
		p->link = node_x;
	}
	else
	{
		first = node_x;
	}
	return *this;
}

//构造一个链表遍历器类
template<class T>
class ChainIterator {

public:
	T* Initialize(const Chain<T>& c)
	{
		location = c.first;
		if (location)return &location->data;
		else return 0;
	}
	T* Next()
	{
		if (!location) return 0;
		location = location->link;
		if (location) return &location->data;
		else return 0;
	}
private:
	ChainNode<T> *location;


	/*遍历器调用方式;
int *x;
ChainIterator<int> c;
x = c.Initialize(X);
while (x) {
cout << *x << ' ' ;
x = c.Next();
}
cout << endl;
	
	*/
};

//单向链表的扩充：循环链表，双向链表， 实质上区别不大

