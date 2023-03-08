#include <iostream>
#include <deque>
#include <algorithm>//��׼�㷨ͷ�ļ�
using namespace std;

//Ϊ��ֹ�ڱ���ʱ�޸�deque��������ݹʼ���const
void PrintDeque(const deque<int>& d)
{
	//���ͬʱ������ҲҪ�޸ĳ�const_iterator
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
		cout << *it << ' ';
	cout << endl;
}

//deque�󲿷ֽӿ���vector���
//��Ҫ��ʾvectorû�е�
void dtest1()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
		d1.push_front(i);//ͷ��
	PrintDeque(d1);
	
	d1.pop_front();//ͷɾ
	PrintDeque(d1);
	
	deque<int>::iterator it = d1.begin();
	d1.erase(it + 3);
	PrintDeque(d1);

	cout << "����ǰ��" << endl;
	d1.clear();
	d1.push_back(1);
	d1.push_back(5);
	d1.push_back(3);
	d1.push_back(7);
	d1.push_back(2);
	d1.push_back(0);
	d1.push_back(4);
	PrintDeque(d1);

	cout << "�����" << endl;
	//Ĭ���������� ����֧��������ʵ�������������sort
	sort(d1.begin(), d1.end());
	PrintDeque(d1);
}

int main3()
{
	//�ܽ᣺deque--double ended queue(˫�˶���)
	//֧���������
	//deque��vector����Ҫ����
	//dequeû��capacity�ĸ��� ͷ��β������Ч�ʽϸ�
	dtest1();
	return 0;
}