#include <iostream>
#include <deque>
#include <algorithm>//标准算法头文件
using namespace std;

//为防止在遍历时修改deque里面的数据故加上const
void PrintDeque(const deque<int>& d)
{
	//与此同时迭代器也要修改成const_iterator
	for (deque<int>::const_iterator it = d.begin();it != d.end();it++)
		cout << *it << ' ';
	cout << endl;
}

//deque大部分接口与vector差不多
//主要演示vector没有的
void dtest1()
{
	deque<int> d1;
	for (int i = 0;i < 10;i++)
		d1.push_front(i);//头插
	PrintDeque(d1);
	
	d1.pop_front();//头删
	PrintDeque(d1);
	
	deque<int>::iterator it = d1.begin();
	d1.erase(it + 3);
	PrintDeque(d1);

	cout << "排序前：" << endl;
	d1.clear();
	d1.push_back(1);
	d1.push_back(5);
	d1.push_back(3);
	d1.push_back(7);
	d1.push_back(2);
	d1.push_back(0);
	d1.push_back(4);
	PrintDeque(d1);

	cout << "排序后：" << endl;
	//默认排序：升序 对于支持随机访问的容器都可以用sort
	sort(d1.begin(), d1.end());
	PrintDeque(d1);
}

int main3()
{
	//总结：deque--double ended queue(双端队列)
	//支持随机访问
	//deque与vector的主要区别
	//deque没有capacity的概念 头插尾插数据效率较高
	dtest1();
	return 0;
}