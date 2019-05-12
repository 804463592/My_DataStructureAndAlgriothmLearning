#pragma once

#include <excpt.h>

//�������������׺��Ե�C++����

/*(һ)ģ�� template*/
template<class Ta,class Tb,class Tc>
Ta Abc(const Ta& a,const Tb& b,const Tc& c) //const�ؼ���ָ�������������޸����ò�����ֵ
{
	return a + b + b * c + (a + b - c) / (a + b) + 4;
}

/*�������ݹ飬recursion function*/
//����n���ĵݹ麯��
int Factorial(int n)
{
	if (n <= 1) return 1;
	else return n * Factorial(n - 1);
} 
template <class T>
T Rsum(T a[], int n)
{ //���� a[0:n-1��֮��
	if (n > 0) return Rsum(a, n - 1) + a[n - 1];
	return 0;
}

/*��������̬�洢����*/
int Allocation(int n)
{
	////����
	int* pa = new int(0);
	delete pa;
	pa = NULL;

	////һά����
	float * px = new float[3];
	delete []px;
	px = NULL;

	//��ά�������
	int **arr = new int*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[3];

		//��ʼ��Ϊ0
		memset(arr[i], 0, sizeof(int) * 3);
	}

	//�ͷŶ�ά����
	for (int i = 0; i < n; i++)
	{
		delete[]arr[i];
	}
	delete arr;
	arr = NULL;

	return 0;
}

/*���ģ���Currency����pdf*/

/*���壩����������*/
 //ͨ��Ҫ�����Ϊ ��

//�ؼ��� operator +�Լ���������һ��C++Ԥ����Ĳ���������operator= �ɱ���Ϊһ��������


/* ��Ԫ���������Աprotected*/

//...


