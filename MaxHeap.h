#ifndef MaxHeap_H
#define MaxHeap_H
#include <iostream>
using namespace std;

template <class T>
class MaxHeap
{
public:
	MaxHeap() {}
	MaxHeap(int cap);		//构造一个容量为capcity的大顶堆
	~MaxHeap();			//析构大顶堆的内存空间
	void insert(T ele);		//向堆中插入元素ele
	void insert(T* p,int num);		//将一个序列中的num个元素依次插入堆中
	T deleteMax();		//删除堆顶元素，并返回删除的元素
	T deleteEle(int i);	//删除索引为i的元素
	bool compare(int i, int j);		//比较索引i处的元素是否大于等于索引j处的元素，如果大于，在返回true
	bool traverse();		//层序遍历
	void clean();			//清空堆中所有元素但是不释放堆空间
private:
	void swap(int i, int j);		//交换索引i与索引j处的元素
	void swim(int i);		//将索引i处的元素上浮到堆中合适的位置，保证堆的有序结构
	void sink(int i);		//将索引i处的元素下浮到堆中合适的位置，保证堆的有序结构
private:
	T* arry;		//在堆上开辟一块连续的空间，存放自定义大顶堆的元素		注意，下标0不存发数据，实际元素是从下标1开始索引的；
	int capcity;		//大顶堆数组空间的容量，也即最大能容纳的元素个数   
	int size;			//记录大顶堆中元素的个数
};

template <class T>
MaxHeap<T>::MaxHeap(int cap)
{
	capcity = cap;
	arry = new T[capcity];
	size = 0;
	for (int i = 0; i < capcity; i++)		//初始化堆中每个元素为-1，-1表示此位置不存在元素
		arry[i] = -1;
}

template <class T>
MaxHeap<T>::~MaxHeap()
{
	cout << "***************~Maxheap()**********" << endl;
	delete[] arry;
	arry = NULL;
}

template <class T>
bool MaxHeap<T>::compare(int i, int j)
{
	return arry[i] >= arry[j] ? true : false;
}

template <class T>
void MaxHeap<T>::swap(int i, int j)
{
	T temp = arry[i];
	arry[i] = arry[j];
	arry[j] = temp;
}

template <class T>
void MaxHeap<T>::swim(int i)
{
	while (i > 1)		//i=1时，已经上浮到根结点，没法再继续上浮了
	{
		//如果堆顶（根结点）元素索引是从下标1开始的，那么除根节点外，任意索引为i的结点的父结点的索引为i/2;
		if (arry[i] > arry[i / 2])			//比较结点i和结点i的父结点大小，如果结点i大于其父结点，则和父结点交换，循坏直至上浮到根结点或者结点i小于等于其父结点时结束
		{
			swap(i, i / 2);
			i = i / 2;
		}
		else break;	
	}	
}

template <class T>
void MaxHeap<T>::sink(int i)
{
	while (2*i <= size)		//判断是否存在子结点，如果不存在子结点，说明已经下浮到叶子结点，没法继续下浮，停止
	{
		if (2 * i + 1 <= size)		//判断是否存在右子结点，如果存在右子结点，则一定同时存在左右孩子结点,否则只存在左子结点
		{
			int max=0;
			if (arry[2 * i] >= arry[2 * i + 1])		//找出最大子结点的下标
				max = 2 * i;
			else 
				max = 2 * i + 1;
			if (arry[i] < arry[max])		//如果结点i小于其最大的子结点，则交换,然后继续循环下沉
			{
				swap(i, max);
				i = max;
			}
			else break;		//否则已经下沉到合适位置，停止下沉
		}
		else
		{
			if (arry[i] <arry[2 * i])
			{
				swap(i, 2 * i);
				i = 2 * i;
			}	
		}
	}
}

template <class T>
void MaxHeap<T>::insert(T ele)
{
	if (size >= capcity - 1)	//判断堆是否已经满了，因为第一个元素是从下标1开始编号的，所以实际的最大容量只有capcity - 1
		return;
	size++;
	arry[size] = ele;		//先将其插入到最后一个位置
	swim(size);			//然后将其上浮到合适的位置；
}

template <class T>
void MaxHeap<T>::insert(T* p,int num)
{
	int i = 0;
	while (i<num)
	{
		insert(p[i]);
		i++;
	}
}

template <class T>
T MaxHeap<T>::deleteEle(int i)
{
	T temp = arry[i];		//保存删除的元素值以便函数结束时返回删除值
	swap(i, size);		//先将需要删除处的元素和最后一个元素交换位置;
	arry[size] = -1;	//然后删除size处的元素
	size--;
	sink(i);		//将i索引处的元素下沉
	swim(i);		//将i索引处的元素上浮
	/*******上浮和下沉内部有且只有一个会执行**************/
	return temp;
}

template <class T>
T MaxHeap<T>::deleteMax()
{
	return deleteEle(1);		//堆顶位置就是最大的元素，删除堆顶位置的元素即可;
}

template <class T>
bool MaxHeap<T>::traverse()
{
	if (size == 0)
		return false;
	else
	{
		for (int i = 1; i <= size; i++)
			cout << arry[i] << " ";
	}
	cout << endl;
	return true;
}

template <class T>
void MaxHeap<T>::clean()
{
	for (int i = 1; i <= size; i++)
		arry[i] = -1;
	size = 0;
}


#endif

