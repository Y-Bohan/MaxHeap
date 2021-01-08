#include <iostream>
#include "MaxHeap.h"
using namespace std;
int main()
{
	MaxHeap<int> arry(50);
	int a[] = { 100,95,40,90,85,35,36,80,75,70,65,30,25,20,15,10,5 };		
	arry.insert(a, sizeof(a) / sizeof(int));		//插入序列到堆中
	for (int i = 1; i < sizeof(a) / sizeof(int); i++)		//检查是否满足堆的有序性，即任意结点的值小于等于其父结点的值
		if (arry.compare(i, 2 * i + 1) && arry.compare(i, 2 * i))
			continue;
		else cout << "**********" <<i<< endl;
	arry.traverse();		//层序遍历
	cout << arry.deleteEle(6) << endl;			//删除6号位置的元素
	arry.insert(50);		//插入一个元素
	cout << arry.deleteEle(6) << endl;
	cout << arry.deleteEle(6) << endl;
	arry.clean();
	arry.traverse();
	return 0;
}