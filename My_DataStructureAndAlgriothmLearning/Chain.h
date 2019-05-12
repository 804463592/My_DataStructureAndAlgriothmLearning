#pragma once

//友元必须先声明才行
template<typename T> class Chain;

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
	Chain() {first = NULL; };
	~Chain();
	bool IsEmpty() const { return first == 0; }
	int Length() const;
	bool Find(int k, T& x) const;
	int Search(const T& x) const;
	Chain<T>& Delete(int k, T& x);
	Chain<T>& Insert(int k, const T& x);
	void Output(std::ostream& out) const;

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
	while(current) {
		len++;
		current = current->link;
	}
	return len;
}