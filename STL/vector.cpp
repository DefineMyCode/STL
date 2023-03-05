#include <iostream>
#include <vector>
using namespace std;

void PrintVector(vector<int>& v)
{
	//����vector�е�����
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

//vector��������
void vtest01()
{
	//Ĭ�Ϲ��� �޲ι���
	vector<int> v;
	for (int i = 0;i < 10;i++)
	{
		v.push_back(i);
	}
	PrintVector(v);

	//ͨ�����䷽ʽ���й��� ���ұ� [ )
	vector<int> v2(v.begin(), v.end());//v.begin��һ�����ݣ�v.end���һ�����ݵĺ�һ��λ��
	PrintVector(v2);

	//n��elem��ʽ����
	vector<int> v3(3, 6);
	PrintVector(v3);

	//��������
	vector<int> v4(v3);
	PrintVector(v4);
}

//vector��ֵ����
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

//vector�����ʹ�С
void vtest03()
{
	vector<int> v1;
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1Ϊ��" << endl;
	else
		cout << "v1��Ϊ��" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	v1.push_back(1);
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1Ϊ��" << endl;
	else
		cout << "v1��Ϊ��" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	for (int i = 0;i < 15;i++)
	{
		v1.push_back(i);
	}
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1Ϊ��" << endl;
	else
		cout << "v1��Ϊ��" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	//����ָ����С
	v1.resize(10);//С��ʵ�ʳ��Ƚض�
	PrintVector(v1);
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1Ϊ��" << endl;
	else
		cout << "v1��Ϊ��" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	v1.resize(5);//����ʵ�ʳ��Ȳ�0 С��ʵ�ʳ���ͬsizeһ��
	PrintVector(v1);
	cout << "v1.size()=" << v1.size() << endl;
	if (v1.empty())
		cout << "v1Ϊ��" << endl;
	else
		cout << "v1��Ϊ��" << endl;
	cout << "v1.capacity()=" << v1.capacity() << endl;
	cout << endl;

	//����ʵ�ʳ��Ȳ��ڶ���������ָ��������
	v1.resize(20,6);
	PrintVector(v1);
	
	
}

//vector������ɾ��
void vtest04()
{
	vector<int> v1;
	v1.push_back(1);//β��
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	PrintVector(v1);

	v1.pop_back();//βɾ
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	v1.pop_back();
	PrintVector(v1);

	//v1.pop_back();
	//PrintVector(v1);

	//���� ��һ���������ǵ�����
	v1.insert(v1.begin(),10);
	PrintVector(v1);

	v1.insert(v1.begin(), 20);
	PrintVector(v1);

	//��ͷ����3��6
	v1.insert(v1.begin(), 3, 6);
	PrintVector(v1);

	//ɾ�� ����Ҳ�ǵ�����
	v1.erase(v1.begin());
	PrintVector(v1);
	
	//��� 
	//v1.erase(v1.begin(), v1.end());
	v1.clear();
	PrintVector(v1);

	//ͨ����begin()+n��ʵ�ֶ�����λ��ɾ��
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.erase(v1.begin()+v1.size()/2);
	PrintVector(v1);
}

//vector���ݴ�ȡ
void vtest05()
{
	vector<int> v;
	for (int i = 0;i < 10;i++)
		v.push_back(i);
	//����[ ]����Ԫ�� Խ�籨��
	for (int i = 0;i < v.size();i++)
		cout << v[i] << ' ';
	cout << endl;
	
	//����at����Ԫ�� Խ���
	for (int i = 0;i < v.size();i++)
		cout << v.at(i) << ' ';
	cout << endl;

	cout << "��һ��Ԫ�أ�" << v.front() << endl;
	cout << "���һ��Ԫ�أ�" << v.back() << endl;

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

//vector�����Ļ���
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
	cout << "����v1 v2��" << endl;
	v1.swap(v2);
	PrintVector(v1);
	PrintVector(v2);

	//ʵ����;
	//����swap���������ڴ�ռ�
	for (int i = 0;i < 100000;i++)
		v2.push_back(i);
	cout << "v2.size=" << v2.size() << endl;
	cout << "v2.capacity=" << v2.capacity() << endl;

	//�ı�v2�Ĵ�С�� size�ı��˵�capacityû��
	v2.resize(10);
	cout << "v2.size=" << v2.size() << endl;
	cout << "v2.capacity=" << v2.capacity() << endl;

	//����swap�����ڴ� 
	vector<int>(v2).swap(v2);
	//vector<int>(v2) ͨ���������� ����һ���������� �ٽ�����������v2����
	//����������һ�����Ծ��ǵ�ǰ��ִ�н�������������ͻᱻ�ͷ�
	//����v2ԭ�����ٵ��ڴ�ռ�Ҳ�ͱ��ͷ��� ����v2����ɹ�

	cout << "v2.size=" << v2.size() << endl;
	cout << "v2.capacity=" << v2.capacity() << endl;
}

//vectorԤ���ռ� �������������ϴ�ʱ������reserveԤ���ռ�
//Ԥ��λ�ò���ʼ���Ҳ��ɷ���
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

	cout << "�ٴο���100000���ռ�Ĵ�����";
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