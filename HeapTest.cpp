#include <iostream>
#include "MaxHeap.h"
using namespace std;
int main()
{
	MaxHeap<int> arry(50);
	int a[] = { 100,95,40,90,85,35,36,80,75,70,65,30,25,20,15,10,5 };		
	arry.insert(a, sizeof(a) / sizeof(int));		//�������е�����
	for (int i = 1; i < sizeof(a) / sizeof(int); i++)		//����Ƿ�����ѵ������ԣ����������ֵС�ڵ����丸����ֵ
		if (arry.compare(i, 2 * i + 1) && arry.compare(i, 2 * i))
			continue;
		else cout << "**********" <<i<< endl;
	arry.traverse();		//�������
	cout << arry.deleteEle(6) << endl;			//ɾ��6��λ�õ�Ԫ��
	arry.insert(50);		//����һ��Ԫ��
	cout << arry.deleteEle(6) << endl;
	cout << arry.deleteEle(6) << endl;
	arry.clean();
	arry.traverse();
	return 0;
}