#pragma once
/*
������������ Array{
ʵ��
����(index, value)�����ݶԼ��ϣ����������������ݵ�indexֵ��������ͬ
����
Create()������һ���յ�����
Store(index, value)���������(index, value)��ͬʱɾ��������ͬ indexֵ�����ݶԣ�������ڣ�
Retrieve(index)����������ֵΪindex�����ݶ�
*/
//һά���鶨��
template<class T>
class Array1D {
public:
	Array1D(int size = 0);
	Array1D(const Array1D<T>& v); //�������캯��
	~Array1D() { delete[]element; }

	T& operator[](int i)const;
	int Size() { return size };

	Array1D<T>& operator=(const Array1D<T>& v);
	Array1D<T> operator+() const; // һԪ�ӷ�������
	Array1D<T> operator+(const Array1D<T>& v) const;
	Array1D<T> operator-()const; // һԪ����������
	Array1D<T> operator-(const Array1D<T>& v) const;
	Array1D<T> operator*(const Array1D<T>& v) const;
	Array1D<T>& operator+=(const T& x);

private:
	int size;
	T *element; //һά����
};

template<class T>
Array1D<T>::Array1D(int sz)
{
	//һά����Ĺ��캯��
	if (sz < 0) throw BadInitializers(); //���������Զ���һ�¸���
	size = sz;
	element = new T[sz];
}

template<class T>
Array1D<T>::Array1D(const Array1D<T>& v)
{// һά����ĸ��ƹ��캯��
	size = v.size;
	element = new T[size]; // ����ռ�
	for (int i = 0; i < size; i++) // ����Ԫ��
		element[i] = v.element[i];
}

template<class T>
T& Array1D<T>::operator[](int i) const
{// ����ָ��� i��Ԫ�ص�����
	if (i < 0 || i >= size) throw OutOfBounds();
	return element[i];
}

template<class T>
Array1D<T> & Array1D<T>::operator = (const Array1D<T>& v)
{
	if (this != &v) { //�������Ҹ�ֵ
		size = v.size;
		delete[] element; // �ͷ�ԭ�ռ�
		element = new T[size]; // ����ռ�
		for (int i = 0; i < size; i++) //����Ԫ��
			element[i] = v.element[i];
	}
	return *this;
}

template<class T>
Array1D<T> Array1D<T>:: operator-(const Array1D<T>& v) const
{// ���� w = (*this) - v,�൱�����ؼ���
	if (size != v.size) throw SizeMismatch();
	// ����������� w
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = element[i] - v.element[i];
	return w;
}

template<class T>
Array1D<T> Array1D<T>::operator-() const
{// ����w = -(*this)����ȡ���������ظ���
// ����������� w
	Array1D<T> w(size);
	for (int i = 0; i < size; i++)
		w.element[i] = -element[i];
	return w;
}

template<class T>
Array1D<T>& Array1D<T>::operator+=(const T& x)
{
	//�� x �ӵ�(*this)��ÿ��Ԫ����
for (int i = 0; i < size; i++)
	element[i] += x;
return *this;
}

//��ά�����ඨ��
template<class T>
class Array2D {
	public :
	Array2D(int r = 0, int c = 0);
	Array2D(const Array2D<T>& m); // ���ƹ��캯��
	~Array2D() { delete[] row; }
	int Rows() const { return rows; }
	int Columns() const { return cols; }
	Array1D<T>& operator[](int i) const;
	Array2D<T>& operator=(const Array2D<T>& m);
	Array2D<T> operator+() const; // һԪ�ӷ�������
	Array2D<T> operator+(const Array2D<T>& m) const;
	Array2D<T> operator-() const; // һԪ����������
	Array2D<T> operator-(const Array2D<T>& m) const;
	Array2D<T> operator*(const Array2D<T>& m) const;
	Array2D<T>& operator+=(const T& x);
	private :
	int rows, cols; // ����ά��
	Array1D<T> *row; // һά���������
};