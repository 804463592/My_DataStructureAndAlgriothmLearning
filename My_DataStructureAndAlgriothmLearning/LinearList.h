#pragma once
#include<ostream>
//线性表的实现

// 异常类：内存不足
class NoMem {
public:
	NoMem() {}
};

//异常类：超出边界
class OutOfBounds {
public:
	OutOfBounds() {}
};


template<class T>
class LinearList {
public:
	LinearList(int MaxListSize = 10); //构造函数
	~LinearList() { delete[] element; } //析构函数
	bool IsEmpty() const { return length == 0; }
	int Length() const { return length; }
	bool Find(int k, T& x) const; //返回第k个元素至x中
	int Search(const T& x) const; // 返回x所在位置

	LinearList<T>& Delete(int k, T& x); // 删除第k个元素并将它返回至x中
	LinearList<T>& Insert(int k, const T& x); // 在第k个元素之后插入x
	void Output(std::ostream& out) const;
private:
	int length;
	int MaxSize;
	T *element; // 一维动态数组
};

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{//基于公式的线性表构造函数
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
{// 查找x，如果找到，则返回x所在的位置
// 如果x不在表中，则返回0
	for (int i = 0; i < length; i++)
		if (element[i] == x) return ++i;
	return 0;
}

template<class T>
LinearList<T> & LinearList<T>::Delete(int k, T &x)
{
	//把第k个元素放入x中，然后删除第k个元素
	//如果不存在第k个元素，则引发异常OutOfBounds()
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
	//把表输送至输出流
	for (int i = 0; i < length; i++)
		out << element[i] << " ";
}

// 重载 < <
template <class T>
std::ostream& operator<<(std::ostream& out, const LinearList<T>& x)
{
	x.Output(out); return out;
}




template<class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x)
{// 在第k个元素之后插入x
// 如果不存在第k个元素，则引发异常O u t O f B o u n d s
// 如果表已经满，则引发异常 N o M e m
	if (k < 0 || k > length) throw OutOfBounds();
	if (length == MaxSize) throw NoMem();
	//向后移动一个位置
	for (int i = length - i; i >= k; i--)
		element[i + 1] = element[i];
	element[k] = x;
	length++;
	return *this;
}

