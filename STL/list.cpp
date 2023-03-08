#include <list>
#include <iostream>

using namespace std;

void PrintList(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin();it != L.end();it++)
	{
		cout << *it << ' ';
	}
	cout << endl;
}

void ltest1()
{
	list<int> L;
	for (int i = 0;i < 10;i++)
	{
		L.push_back(i);
	}
	
	cout << "L.push_back:" << endl;
	PrintList(L);

	//交换
	list<int> L2;
	L2.assign(3, 6);
	cout << "L2.push_back:" << endl;
	PrintList(L2);
	L2.swap(L);
	cout << "L与L2交换后：" << endl;
	
	cout << "L.push_back:" << endl;
	PrintList(L);
	
	cout << "L2.push_back:" << endl;
	PrintList(L2);
}

//list插入与删除
void ltest2()
{
	list<int> L1;
	L1.push_back(1);
	L1.push_back(2);
	L1.push_back(3);
	L1.push_front(10);
	L1.push_front(20);
	L1.push_front(30);
	PrintList(L1);

	L1.pop_back();
	PrintList(L1);

	L1.pop_front();
	PrintList(L1);

	list<int>::iterator pos = L1.begin();
	for (int i = 0;i < 3;i++)
		pos++;
	//第一个参数为插入的位置(必须为当前list已有的)
	//list<int> L2(L1);
	//L1.insert(L2.begin(),0);
	L1.insert(pos, 0);
	PrintList(L1);

	L1.erase(pos);
	//pos是指向的最开始设置的位置 故2被删除
	PrintList(L1);

	//移除
	L1.push_back(666);
	L1.push_front(666);
	pos = L1.begin();
	for (int i = 0;i < L1.size() / 2;i++)
		pos++;
	L1.insert(pos, 666);
	cout << "移除666前" << endl;
	PrintList(L1);
	cout << "移除666后" << endl;

	//移除链表中所有与之匹配的节点
	L1.remove(666);
	PrintList(L1);

	L1.clear();
	PrintList(L1);
}

//list数据存取
void ltest3()
{
	list<int> L;
	for (int i = 1;i <= 10;i++)
		L.push_back(i);
	cout << "L.front=" << L.front() << endl;
	cout << "L.back=" << L.back() << endl;
}

class person
{
public:
	person(string name, int age, double weight)
	{
		this->name = name;
		this->age = age;
		this->weight = weight;
	}

	string name;
	int age;
	double weight;
};

bool MyCompare(int v1,int v2)
{
	//降序 让第一个参数大于第二个参数
	return v1 > v2;
}

bool ComparePerson(person p1, person p2)
{
	//按姓名升序 姓名相同 按年龄降序
	if (p1.name == p2.name)
		return p1.age > p2.age;
	return p1.name.compare(p2.name) < 0;
	
}

//list反转和排序
void ltest4()
{
	list<int> L;
	L.push_back(1);
	L.push_back(6);
	L.push_back(2);
	L.push_back(5);
	L.push_back(3);
	L.push_back(0);
	PrintList(L);

	cout << "reverse后" << endl;
	L.reverse();
	PrintList(L);

	L.reverse();

	//排序 不支持随机访问的容器 
	//有对应的成员函数实现排序

	L.sort();//默认升序
	PrintList(L);

	L.sort(MyCompare);//升序
	PrintList(L);


}

//自定义数据类型list排序
void ltest5()
{
	list<person> L;
	person p1("周润发", 58, 62.33);
	person p2("周星驰", 55, 63.88);
	person p3("郭富城", 66, 58.32);
	person p4("李小龙", 88, 70.13);
	person p5("王明", 18, 51.98);
	person p6("邓超", 10, 66.52);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<person>::iterator it = L.begin();it != L.end();it++)
		cout << "name: " << it->name << " age: " << it->age << " weight: " << it->weight << endl;

	//排序
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "按姓名排序：" << endl;
	L.sort(ComparePerson);
	for (list<person>::iterator it = L.begin();it != L.end();it++)
		cout << "name: " << it->name << " age: " << it->age << " weight: " << it->weight << endl;
}
int main()
{
	//STL中的list是一个双向循环链表
	//插入删除快 遍历慢
	//ltest1();
	//ltest2();
	//ltest3();
	//ltest4();
	ltest5();
	return 0;
}