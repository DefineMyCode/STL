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

	//����
	list<int> L2;
	L2.assign(3, 6);
	cout << "L2.push_back:" << endl;
	PrintList(L2);
	L2.swap(L);
	cout << "L��L2������" << endl;
	
	cout << "L.push_back:" << endl;
	PrintList(L);
	
	cout << "L2.push_back:" << endl;
	PrintList(L2);
}

//list������ɾ��
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
	//��һ������Ϊ�����λ��(����Ϊ��ǰlist���е�)
	//list<int> L2(L1);
	//L1.insert(L2.begin(),0);
	L1.insert(pos, 0);
	PrintList(L1);

	L1.erase(pos);
	//pos��ָ����ʼ���õ�λ�� ��2��ɾ��
	PrintList(L1);

	//�Ƴ�
	L1.push_back(666);
	L1.push_front(666);
	pos = L1.begin();
	for (int i = 0;i < L1.size() / 2;i++)
		pos++;
	L1.insert(pos, 666);
	cout << "�Ƴ�666ǰ" << endl;
	PrintList(L1);
	cout << "�Ƴ�666��" << endl;

	//�Ƴ�������������֮ƥ��Ľڵ�
	L1.remove(666);
	PrintList(L1);

	L1.clear();
	PrintList(L1);
}

//list���ݴ�ȡ
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
	//���� �õ�һ���������ڵڶ�������
	return v1 > v2;
}

bool ComparePerson(person p1, person p2)
{
	//���������� ������ͬ �����併��
	if (p1.name == p2.name)
		return p1.age > p2.age;
	return p1.name.compare(p2.name) < 0;
	
}

//list��ת������
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

	cout << "reverse��" << endl;
	L.reverse();
	PrintList(L);

	L.reverse();

	//���� ��֧��������ʵ����� 
	//�ж�Ӧ�ĳ�Ա����ʵ������

	L.sort();//Ĭ������
	PrintList(L);

	L.sort(MyCompare);//����
	PrintList(L);


}

//�Զ�����������list����
void ltest5()
{
	list<person> L;
	person p1("����", 58, 62.33);
	person p2("���ǳ�", 55, 63.88);
	person p3("������", 66, 58.32);
	person p4("��С��", 88, 70.13);
	person p5("����", 18, 51.98);
	person p6("�˳�", 10, 66.52);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<person>::iterator it = L.begin();it != L.end();it++)
		cout << "name: " << it->name << " age: " << it->age << " weight: " << it->weight << endl;

	//����
	cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "����������" << endl;
	L.sort(ComparePerson);
	for (list<person>::iterator it = L.begin();it != L.end();it++)
		cout << "name: " << it->name << " age: " << it->age << " weight: " << it->weight << endl;
}
int main()
{
	//STL�е�list��һ��˫��ѭ������
	//����ɾ���� ������
	//ltest1();
	//ltest2();
	//ltest3();
	//ltest4();
	ltest5();
	return 0;
}