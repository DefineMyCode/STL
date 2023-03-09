#include <set>//包含set和multiset
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>
using namespace std;

void PrintSet(set<int>& s)
{
	cout << "set:" << endl;
	for (set<int>::iterator it = s.begin();it != s.end();it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void PrintMultiset(multiset<int>& ms)
{
	cout << "multiset:" << endl;
	for (multiset<int>::iterator it = ms.begin();it != ms.end();it++)
		cout << *it << ' ';
	cout << endl;
}

//set构造与赋值
void stest01()
{
	set<int> s1;
	//插入数据只有insert接口
	s1.insert(5);
	s1.insert(3);
	s1.insert(2);
	s1.insert(1);
	s1.insert(4);
	//重复值无法成功插入 不会报错、警告
	//s1.insert(4);
	PrintSet(s1);
	
	//拷贝构造
	set<int> s2(s1);
	PrintSet(s2);

	//赋值
	set<int> s3 = s2;
	PrintSet(s3);
}

//set大小和交换
void stest02()
{
	set<int> s1;
	if (s1.empty())
		cout << "s1为空" << endl;
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}

	s1.insert(5);
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	s1.insert(1);
	
	if (s1.empty())
		cout << "s1为空" << endl;
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}
	
	set<int> s2;
	s2.insert(10);
	s2.insert(9);
	s2.insert(8);
	s2.insert(7);
	s2.insert(6);
	s2.swap(s1);
	if (s1.empty())
		cout << "s1为空" << endl;
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}
}

//set插入与删除数据
void stest03()
{
	set<int> s1;
	s1.insert(5);
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	s1.insert(1);
	PrintSet(s1);

	cout << "——————————————" << endl;
	s1.erase(s1.begin());
	PrintSet(s1);
	
	//尾删
	set<int>::iterator pos = s1.end();
	pos--;
	s1.erase(pos);

	//s1.erase(s1.end());//报错代码
	PrintSet(s1);

	s1.erase(2);//删除特点元素 自定义数据类型需重载 ==
	PrintSet(s1);

	set<int>s2(s1);
	s2.erase(s2.begin(), s2.end());//删除指定区间
	if (s2.empty())
		cout << "s2为空" << endl;
	else
	{
		cout << "s2不为空" << endl;
		cout << "s2.size()=" << s2.size() << endl;
		PrintSet(s2);
	}
	
	//清空
	s1.clear();
	if (s1.empty())
		cout << "s1为空" << endl;
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}
}

//set查找与统计
void stest04()
{
	set<int> s1;multiset<int> ms1;
	for (int i = 0;i < 20;i++)
	{
		int n = rand() % 100 + 1;
		s1.insert(n);
		ms1.insert(n);
	}
	PrintSet(s1);
	PrintMultiset(ms1);
	int x = rand() % 100 + 1;
	cout << "查找" << x << endl;
	//find查找到元素后返回该元素的迭代器 反之返回end()
	set<int>::iterator node = s1.find(x);
	if (node != s1.end())
		cout << "找到" << x << "了" << endl;
	else
		cout << "没找到" << x << endl;

	//对于set而言count返回的结果只有1或0
	cout << "s1.count(x)=" << s1.count(x) << endl;
	cout << "ms1.count(x)=" << ms1.count(x) << endl;
}

//仿函数
class MyCompar
{
public:
	//重载 ( )
	bool operator()(const int& v1,const int& v2) const
	{
		return v1 > v2;
	}
};

class S_person
{
public:
	S_person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

class S_ComparePerson
{
public:
	bool operator()(const S_person& p1, const S_person& p2) const
	{
		//按照姓名降序
		return p1.name.compare(p2.name) > 0;
	}
};

//set容器排序
void stest05()
{
	set<int, MyCompar> s1;
	//指定排序规则 降序

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);

	for (set<int, MyCompar>::iterator it = s1.begin();it != s1.end();it++)
		cout << *it << ' ';
	cout << endl;

	//排序自定义对象
	//自定义类型都需要指定排序方式
	set<S_person, S_ComparePerson> set1;
	S_person p1("张三", 18);
	S_person p2("小米", 66);
	S_person p3("网", 20);
	S_person p4("周杰伦", 38);
	set1.insert(p1);
	set1.insert(p2);
	set1.insert(p3);
	set1.insert(p4);

	for (set<S_person, S_ComparePerson>::iterator it = set1.begin();it != set1.end();it++)
		cout << it->name << ' ' << it->age << endl;
}
int main()
{
	srand((unsigned int)time(NULL));

	//所有元素都会在插入时自动被排序
	//set/multiset属于关联式容器，底层结构是用二叉树实现
	//set不允许有重复元素
	//multiset允许有重复元素
	//stest01();
	//stest02();
	//stest03();
	//stest04();
	stest05();
	return 0;
}