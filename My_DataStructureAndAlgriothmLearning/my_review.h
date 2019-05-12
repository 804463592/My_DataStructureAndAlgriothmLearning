#pragma once

#include <excpt.h>

//下面是你最容易忽略的C++特性

/*(一)模板 template*/
template<class Ta,class Tb,class Tc>
Ta Abc(const Ta& a,const Tb& b,const Tc& c) //const关键字指明函数不可以修改引用参数的值
{
	return a + b + b * c + (a + b - c) / (a + b) + 4;
}

/*（二）递归，recursion function*/
//计算n！的递归函数
int Factorial(int n)
{
	if (n <= 1) return 1;
	else return n * Factorial(n - 1);
} 
template <class T>
T Rsum(T a[], int n)
{ //计算 a[0:n-1］之和
	if (n > 0) return Rsum(a, n - 1) + a[n - 1];
	return 0;
}

/*（三）动态存储分配*/
int Allocation(int n)
{
	////变量
	int* pa = new int(0);
	delete pa;
	pa = NULL;

	////一维数组
	float * px = new float[3];
	delete []px;
	px = NULL;

	//二维数组分配
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[3];

		//初始化为0
		memset(arr[i], 0, sizeof(int) * 3);
	}

	//释放二维数组
	for (int i = 0; i < n; i++)
	{
		delete[]arr[i];
	}
	delete arr;
	arr = NULL;

	return 0;
}

/*（四）类Currency，见pdf*/

/*（五）操作符重载*/
 //通常要求参数为 类

//关键字 operator +以及紧跟其后的一个C++预定义的操作符，如operator= 可被视为一个函数名


/* 友元，保护类成员protected*/

//...


