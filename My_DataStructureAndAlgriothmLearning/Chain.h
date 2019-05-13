#pragma once
//using namespace std;

//Ҫʹ����Ԫ���������������У����⣬typename ��classͨ��ûʲô����
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
	ChainNode<T> *first; // ָ���һ���ڵ��ָ��
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
{// �������������������ɾ�������е����нڵ�
	ChainNode<T> *next; // ��һ���ڵ�
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
	int index = 1;//����
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
{ //Ѱ��x������x���򷵻�x�ĵ�ַ�����򷵻�0
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
	//������Ԫ�����������
	Chain<T>* current;
	for (current = first; current; current = current->link)
		out << current->data << " ";
}

//����<<
template<class T>
std::ostream& operator<<(std::ostream&out, const Chain<T>& x)
{
	x.Output(out);
	return out;
}

//��������ɾ��һ��Ԫ��
template<class T>
Chain<T>& Chain<T>::Delete(int k, T&x)
{
	//�ѵ�k��Ԫ��ȡ��x��Ȼ���������ɾ����k��Ԫ��
	//��������ڵ�k��Ԫ�أ��������쳣OutOfBounds()
	if (k < 1 || !first)
	{
		throw OutOfBounds();
	}

	ChainNode<T>* p = first;

	//q��λ��k-1��λ��,p��λ��k��λ��
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
	//��ȡ���ݺ�ɾ��
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
	if (k > 0 && !p) throw OutOfBounds();//�����ڵ�k��Ԫ�أ��������

	ChainNode<T>* y = new ChainNode<T>;
	y->data = x; //û�ж��幹�캯�������ֻ��ֱ�Ӹ�ֵ
	if (k) { //��p֮�����
		y->link = p->link;
		p->link = y;
	}
	else { //k=0,��Ϊ��һ��Ԫ�ز���
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
	//������ĩβ���Ԫ��x

	ChainNode<T> * node_x =new ChainNode<T>;
	node_x->data = x;
	node_x->link = NULL;
	
	ChainNode<T>* p = first;

	if (first)
	{ //����ǿ�
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

//����һ�������������
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


	/*���������÷�ʽ;
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

//������������䣺ѭ������˫������ ʵ�������𲻴�

