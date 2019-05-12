#pragma once
#include<ostream>
//���Ա��ʵ��

// �쳣�ࣺ�ڴ治��
class NoMem {
public:
	NoMem() {}
};

//�쳣�ࣺ�����߽�
class OutOfBounds {
public:
	OutOfBounds() {}
};


template<class T>
class LinearList {
public:
	LinearList(int MaxListSize = 10); //���캯��
	~LinearList() { delete[] element; } //��������
	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; }
	bool Find(int k, T& x) const; //���ص�k��Ԫ����x��
	int Search(const T& x) const; // ����x����λ��

	LinearList<T>& Delete(int k, T& x); // ɾ����k��Ԫ�ز�����������x��
	LinearList<T>& Insert(int k, const T& x); // �ڵ�k��Ԫ��֮�����x
	void Output(std::ostream& out) const;
private:
	int length;
	int MaxSize;
	T *element; // һά��̬����
};

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{//���ڹ�ʽ�����Ա��캯��
	MaxSize = MaxListSize;
	element = new T[MaxSize];
	Length = 0;
}

template<class T>
bool LinearList<T>::Find(int k, T&x)const {
	if (k<1 || k>length)return false;
	x = element[k - 1];
	return true;
}

template<class T>
int LinearList<T>::Search(const T& x) const
{// ����x������ҵ����򷵻�x���ڵ�λ��
// ���x���ڱ��У��򷵻�0
	for (int i = 0; i < length; i++)
		if (element[i] == x) return ++i;
	return 0;
}

template<class T>
LinearList<T> & LinearList<T>::Delete(int k, T &x)
{
	//�ѵ�k��Ԫ�ط���x�У�Ȼ��ɾ����k��Ԫ��
	//��������ڵ�k��Ԫ�أ��������쳣OutOfBounds()
	if (Find(k, x))
	{
		for (int i = k; i < length; i++)
			element[i - 1] = element[i];

		length--;
		return *this;
	}
	else throw OutOfBounds();
}

template<class T>
void LinearList<T>::Output(std::ostream& out) const
{
	//�ѱ������������
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
}

// ���� < <
template <class T>
std::ostream& operator<<(std::ostream& out, const LinearList<T>& x)
{
	x.Output(out); return out;
}




template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{// �ڵ�k��Ԫ��֮�����x
// ��������ڵ�k��Ԫ�أ��������쳣O u t O f B o u n d s
// ������Ѿ������������쳣 N o M e m
	if (k < 0 || k > length) throw OutOfBounds();
	if (length == MaxSize) throw NoMem();
	//����ƶ�һ��λ��
	for (int i = length - i; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
	return *this;
}

