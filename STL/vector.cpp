#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int>& v)
{
	//遍历vector中的数据
	for (vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void PrintVector(vector<vector<int>>& v)
{
	for (vector<vector<int>>::iterator it = v.begin();it != v.end();it++)
	{
		for (vector<int>::iterator i = it->begin();i != it->end();i++)
		{
			cout << *i << ' ';
		}
		cout << endl;
	}
	cout << endl;
}

//vector容器构造
void vtest01()
{
	//默认构造 无参构造
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	PrintVector(v);

	//通过区间方式进行构造 左开右闭 [ )
	vector<int> v2(v.begin(), v.end());//v.begin第一个数据，v.end最后一个数据的后一个位置
	PrintVector(v2);

	//n个elem方式构造
	vector<int> v3(3, 6);
	PrintVector(v3);

	//拷贝构造
	vector<int> v4(v3);
	PrintVector(v4);
}

//vector赋值操作
void vtest02()
{
	vector<int> v1;
	for (int i = 1;i < 10;i++)
		v1.push_back(i);
	PrintVector(v1);

	vector<int> v2;
	v2 = v1;
	PrintVector(v2);

	vector<int> v3;
	v3.assign(v2.begin(),v2.end()-3);
	PrintVector(v3);

	vector<int> v4;
	v4.assign(3, 6);
	PrintVector(v4);
}

//vector容量和大小
void vtest03()
{
	vector<int> v1;
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1为空" << endl;
	else
		cout << "v1不为空" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	v1.push_back(1);
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1为空" << endl;
	else
		cout << "v1不为空" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	for (int i = 0;i < 15;i++)
	{
		v1.push_back(i);
	}
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1为空" << endl;
	else
		cout << "v1不为空" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	//重新指定大小
	v1.resize(10);//小于实际长度截断
	PrintVector(v1);
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1为空" << endl;
	else
		cout << "v1不为空" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	v1.resize(5);//大于实际长度补0 小于实际长度同size一样
	PrintVector(v1);
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1为空" << endl;
	else
		cout << "v1不为空" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	//大于实际长度补第二个参数所指定的数据
	v1.resize(20,6);
	PrintVector(v1);
	
	
}

//vector插入与删除
void vtest04()
{
	vector<int> v1;
	v1.push_back(1);//尾插
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	PrintVector(v1);

	v1.pop_back();//尾删
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	//v1.pop_back();
	//PrintVector(v1);

	//插入 第一个参数得是迭代器
	v1.insert(v1.begin(),10);
	PrintVector(v1);

	v1.insert(v1.begin(), 20);
	PrintVector(v1);

	//在头插入3个6
	v1.insert(v1.begin(), 3, 6);
	PrintVector(v1);

	//删除 参数也是迭代器
	v1.erase(v1.begin());
	PrintVector(v1);
	
	//清空 
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	PrintVector(v1);

	//通过对begin()+n可实现对任意位置删除
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.erase(v1.begin()+v1.size()/2);
	PrintVector(v1);
}

//vector数据存取
void vtest05()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
		v.push_back(i);
	//利用[ ]访问元素 越界报错
	for (int i = 0;i < v.size();i++)
		cout << v[i] << ' ';
	cout << endl;
	
	//利用at访问元素 越界崩
	for (int i = 0;i < v.size();i++)
		cout << v.at(i) << ' ';
	cout << endl;

	cout << "第一个元素：" << v.front() << endl;
	cout << "最后一个元素：" << v.back() << endl;

	v[0] = 10;
	cout << v[0] << endl;
	for (int i = 0;i < v.size();i++)
		cout << v[i] << ' ';
	cout << endl;

	////////////////////////
	vector<vector<int>> v1;
	vector<int> v11;
	vector<int> v22;
	for (int i = 0;i < 3;i++)
		v11.push_back(i);
	for (int i = 0;i < 10;i++)
		v22.push_back(i+10);
	v1.push_back(v11);
	v1.push_back(v22);
	PrintVector(v1);

}

//vector容器的互换
void vtest06()
{
	vector<int> v1;
	for (int i = 1;i < 6;i++)
		v1.push_back(i);
	PrintVector(v1);
	vector<int> v2;
	for (int i = 10;i > 0;i--)
		v2.push_back(i);
	PrintVector(v2);
	cout << "交换v1 v2后" << endl;
	v1.swap(v2);
	PrintVector(v1);
	PrintVector(v2);

	//实际用途
	//巧用swap可以收缩内存空间
	for (int i = 0;i < 100000;i++)
		v2.push_back(i);
	cout << "v2.size=" << v2.size() << endl;
	cout << "v2.capacity=" << v2.capacity() << endl;

	//改变v2的大小后 size改变了但capacity没变
	v2.resize(10);
	cout << "v2.size=" << v2.size() << endl;
	cout << "v2.capacity=" << v2.capacity() << endl;

	//巧用swap收缩内存 
	vector<int>(v2).swap(v2);
	//vector<int>(v2) 通过拷贝构造 创建一个匿名对象 再将匿名对象与v2交换
	//匿名对象有一个特性就是当前行执行结束后匿名对象就会被释放
	//于是v2原来开辟的内存空间也就被释放了 最终v2瘦身成功

	cout << "v2.size=" << v2.size() << endl;
	cout << "v2.capacity=" << v2.capacity() << endl;
}

//vector预留空间 当出事数据量较大时可利用reserve预留空间
//预留位置不初始化且不可访问
void vtest07()
{
	vector<int> v;
	int* p = NULL;
	int count = 0;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}
	}
	cout << count << endl;

	v.resize(0);
	vector<int>(v).swap(v);
	cout << v.capacity() << endl;

	cout << "再次开辟100000个空间的次数：";
	v.reserve(1000);
	count = 0;
	for (int i = 0;i < 100000;i++)
	{
		v.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			count++;
		}
	}
	cout << count << endl;


}

int main()
{
	//vtest01();
	//vtest02();
	//vtest03();
	//vtest04();
	//vtest05();
	//vtest06();
	vtest07();
	return 0;
}