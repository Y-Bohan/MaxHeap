#ifndef MaxHeap_H
#define MaxHeap_H
#include <iostream>
using namespace std;

template <class T>
class MaxHeap
{
public:
	MaxHeap() {}
	MaxHeap(int cap);		//����һ������Ϊcapcity�Ĵ󶥶�
	~MaxHeap();			//�����󶥶ѵ��ڴ�ռ�
	void insert(T ele);		//����в���Ԫ��ele
	void insert(T* p,int num);		//��һ�������е�num��Ԫ�����β������
	T deleteMax();		//ɾ���Ѷ�Ԫ�أ�������ɾ����Ԫ��
	T deleteEle(int i);	//ɾ������Ϊi��Ԫ��
	bool compare(int i, int j);		//�Ƚ�����i����Ԫ���Ƿ���ڵ�������j����Ԫ�أ�������ڣ��ڷ���true
	bool traverse();		//�������
	void clean();			//��ն�������Ԫ�ص��ǲ��ͷŶѿռ�
private:
	void swap(int i, int j);		//��������i������j����Ԫ��
	void swim(int i);		//������i����Ԫ���ϸ������к��ʵ�λ�ã���֤�ѵ�����ṹ
	void sink(int i);		//������i����Ԫ���¸������к��ʵ�λ�ã���֤�ѵ�����ṹ
private:
	T* arry;		//�ڶ��Ͽ���һ�������Ŀռ䣬����Զ���󶥶ѵ�Ԫ��		ע�⣬�±�0���淢���ݣ�ʵ��Ԫ���Ǵ��±�1��ʼ�����ģ�
	int capcity;		//�󶥶�����ռ��������Ҳ����������ɵ�Ԫ�ظ���   
	int size;			//��¼�󶥶���Ԫ�صĸ���
};

template <class T>
MaxHeap<T>::MaxHeap(int cap)
{
	capcity = cap;
	arry = new T[capcity];
	size = 0;
	for (int i = 0; i < capcity; i++)		//��ʼ������ÿ��Ԫ��Ϊ-1��-1��ʾ��λ�ò�����Ԫ��
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
	while (i > 1)		//i=1ʱ���Ѿ��ϸ�������㣬û���ټ����ϸ���
	{
		//����Ѷ�������㣩Ԫ�������Ǵ��±�1��ʼ�ģ���ô�����ڵ��⣬��������Ϊi�Ľ��ĸ���������Ϊi/2;
		if (arry[i] > arry[i / 2])			//�ȽϽ��i�ͽ��i�ĸ�����С��������i�����丸��㣬��͸���㽻����ѭ��ֱ���ϸ����������߽��iС�ڵ����丸���ʱ����
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
	while (2*i <= size)		//�ж��Ƿ�����ӽ�㣬����������ӽ�㣬˵���Ѿ��¸���Ҷ�ӽ�㣬û�������¸���ֹͣ
	{
		if (2 * i + 1 <= size)		//�ж��Ƿ�������ӽ�㣬����������ӽ�㣬��һ��ͬʱ�������Һ��ӽ��,����ֻ�������ӽ��
		{
			int max=0;
			if (arry[2 * i] >= arry[2 * i + 1])		//�ҳ�����ӽ����±�
				max = 2 * i;
			else 
				max = 2 * i + 1;
			if (arry[i] < arry[max])		//������iС���������ӽ�㣬�򽻻�,Ȼ�����ѭ���³�
			{
				swap(i, max);
				i = max;
			}
			else break;		//�����Ѿ��³�������λ�ã�ֹͣ�³�
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
	if (size >= capcity - 1)	//�ж϶��Ƿ��Ѿ����ˣ���Ϊ��һ��Ԫ���Ǵ��±�1��ʼ��ŵģ�����ʵ�ʵ��������ֻ��capcity - 1
		return;
	size++;
	arry[size] = ele;		//�Ƚ�����뵽���һ��λ��
	swim(size);			//Ȼ�����ϸ������ʵ�λ�ã�
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
	T temp = arry[i];		//����ɾ����Ԫ��ֵ�Ա㺯������ʱ����ɾ��ֵ
	swap(i, size);		//�Ƚ���Ҫɾ������Ԫ�غ����һ��Ԫ�ؽ���λ��;
	arry[size] = -1;	//Ȼ��ɾ��size����Ԫ��
	size--;
	sink(i);		//��i��������Ԫ���³�
	swim(i);		//��i��������Ԫ���ϸ�
	/*******�ϸ����³��ڲ�����ֻ��һ����ִ��**************/
	return temp;
}

template <class T>
T MaxHeap<T>::deleteMax()
{
	return deleteEle(1);		//�Ѷ�λ�þ�������Ԫ�أ�ɾ���Ѷ�λ�õ�Ԫ�ؼ���;
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

