#pragma once
/*
抽象数据类型 Array{
实例
形如(index, value)的数据对集合，其中任意两对数据的index值都各不相同
操作
Create()：创建一个空的数组
Store(index, value)：添加数据(index, value)，同时删除具有相同 index值的数据对（如果存在）
Retrieve(index)：返回索引值为index的数据对
*/
//一维数组定义
template<class T>
class Array1D {
public:
	Array1D(int size = 0);
	Array1D(const Array1D<T>& v); //拷贝构造函数
	~Array1D() { delete[]element; }

	T& operator[](int i)const;
	int Size() { return size };

	Array1D<T>& operator=(const Array1D<T>& v);
	Array1D<T> operator+() const; // 一元加法操作符
	Array1D<T> operator+(const Array1D<T>& v) const;
	Array1D<T> operator-()const; // 一元减法操作符
	Array1D<T> operator-(const Array1D<T>& v) const;
	Array1D<T> operator*(const Array1D<T>& v) const;
	Array1D<T>& operator+=(const T& x);

private:
	int size;
	T *element; //一维数组
};

template<class T>
Array1D<T>::Array1D(int sz)
{
	//一维数组的构造函数
	if (sz < 0) throw BadInitializers(); //如果报错可以定义一下该类
	size = sz;
	element = new T[sz];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& v)
{// 一维数组的复制构造函数
	size = v.size;
	element = new T[size]; // 申请空间
	for (int i = 0; i < size; i++) // 复制元素
		element[i] = v.element[i];
}

template<class T>
T& Array1D<T>::operator[](int i) const
{// 返回指向第 i个元素的引用
	if (i < 0 || i >= size) throw OutOfBounds();
	return element[i];
}

template<class T>
Array1D<T> & Array1D<T>::operator = (const Array1D<T>& v)
{
	if (this != &v) { //不是自我赋值
		size = v.size;
		delete[] element; // 释放原空间
		element = new T[size]; // 申请空间
		for (int i = 0; i < size; i++) //复制元素
			element[i] = v.element[i];
	}
	return *this;
}

template<class T>
Array1D<T> Array1D<T>:: operator-(const Array1D<T>& v) const
{// 返回 w = (*this) - v,相当于重载减号
	if (size != v.size) throw SizeMismatch();
	// 创建结果数组 w
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] - v.element[i];
	return w;
}

template<class T>
Array1D<T> Array1D<T>::operator-() const
{// 返回w = -(*this)，即取负数，重载负号
// 创建结果数组 w
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = -element[i];
	return w;
}

template<class T>
Array1D<T>& Array1D<T>::operator+=(const T& x)
{
	//把 x 加到(*this)的每个元素上
for (int i = 0; i < size; i++)
	element[i] += x;
return *this;
}

//二维数组类定义
template<class T>
class Array2D {
	public :
	Array2D(int r = 0, int c = 0);
	Array2D(const Array2D<T>& m); // 复制构造函数
	~Array2D() { delete[] row; }
	int Rows() const { return rows; }
	int Columns() const { return cols; }
	Array1D<T>& operator[](int i) const;
	Array2D<T>& operator=(const Array2D<T>& m);
	Array2D<T> operator+() const; // 一元加法操作符
	Array2D<T> operator+(const Array2D<T>& m) const;
	Array2D<T> operator-() const; // 一元减法操作符
	Array2D<T> operator-(const Array2D<T>& m) const;
	Array2D<T> operator*(const Array2D<T>& m) const;
	Array2D<T>& operator+=(const T& x);
	private :
	int rows, cols; // 数组维数
	Array1D<T> *row; // 一维数组的数组
};