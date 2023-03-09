#include <set>//����set��multiset
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

//set�����븳ֵ
void stest01()
{
	set<int> s1;
	//��������ֻ��insert�ӿ�
	s1.insert(5);
	s1.insert(3);
	s1.insert(2);
	s1.insert(1);
	s1.insert(4);
	//�ظ�ֵ�޷��ɹ����� ���ᱨ������
	//s1.insert(4);
	PrintSet(s1);
	
	//��������
	set<int> s2(s1);
	PrintSet(s2);

	//��ֵ
	set<int> s3 = s2;
	PrintSet(s3);
}

//set��С�ͽ���
void stest02()
{
	set<int> s1;
	if (s1.empty())
		cout << "s1Ϊ��" << endl;
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}

	s1.insert(5);
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	s1.insert(1);
	
	if (s1.empty())
		cout << "s1Ϊ��" << endl;
	else
	{
		cout << "s1��Ϊ��" << endl;
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
		cout << "s1Ϊ��" << endl;
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}
}

//set������ɾ������
void stest03()
{
	set<int> s1;
	s1.insert(5);
	s1.insert(4);
	s1.insert(3);
	s1.insert(2);
	s1.insert(1);
	PrintSet(s1);

	cout << "����������������������������" << endl;
	s1.erase(s1.begin());
	PrintSet(s1);
	
	//βɾ
	set<int>::iterator pos = s1.end();
	pos--;
	s1.erase(pos);

	//s1.erase(s1.end());//�������
	PrintSet(s1);

	s1.erase(2);//ɾ���ص�Ԫ�� �Զ����������������� ==
	PrintSet(s1);

	set<int>s2(s1);
	s2.erase(s2.begin(), s2.end());//ɾ��ָ������
	if (s2.empty())
		cout << "s2Ϊ��" << endl;
	else
	{
		cout << "s2��Ϊ��" << endl;
		cout << "s2.size()=" << s2.size() << endl;
		PrintSet(s2);
	}
	
	//���
	s1.clear();
	if (s1.empty())
		cout << "s1Ϊ��" << endl;
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1.size()=" << s1.size() << endl;
		PrintSet(s1);
	}
}

//set������ͳ��
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
	cout << "����" << x << endl;
	//find���ҵ�Ԫ�غ󷵻ظ�Ԫ�صĵ����� ��֮����end()
	set<int>::iterator node = s1.find(x);
	if (node != s1.end())
		cout << "�ҵ�" << x << "��" << endl;
	else
		cout << "û�ҵ�" << x << endl;

	//����set����count���صĽ��ֻ��1��0
	cout << "s1.count(x)=" << s1.count(x) << endl;
	cout << "ms1.count(x)=" << ms1.count(x) << endl;
}

//�º���
class MyCompar
{
public:
	//���� ( )
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
		//������������
		return p1.name.compare(p2.name) > 0;
	}
};

//set��������
void stest05()
{
	set<int, MyCompar> s1;
	//ָ��������� ����

	s1.insert(1);
	s1.insert(2);
	s1.insert(3);
	s1.insert(4);
	s1.insert(5);

	for (set<int, MyCompar>::iterator it = s1.begin();it != s1.end();it++)
		cout << *it << ' ';
	cout << endl;

	//�����Զ������
	//�Զ������Ͷ���Ҫָ������ʽ
	set<S_person, S_ComparePerson> set1;
	S_person p1("����", 18);
	S_person p2("С��", 66);
	S_person p3("��", 20);
	S_person p4("�ܽ���", 38);
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

	//����Ԫ�ض����ڲ���ʱ�Զ�������
	//set/multiset���ڹ���ʽ�������ײ�ṹ���ö�����ʵ��
	//set���������ظ�Ԫ��
	//multiset�������ظ�Ԫ��
	//stest01();
	//stest02();
	//stest03();
	//stest04();
	stest05();
	return 0;
}