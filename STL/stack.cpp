#include <stack>
#include <iostream>
using namespace std;

void stest1()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	
	stack<int> s1;
	s1 = s;
	cout << s.size() << endl;
	while (!s.empty())
	{
		int tmp = s.top();
		cout << tmp << ' ';
		s.pop();
	}
	
	while (!s1.empty())
	{
		s.push(s1.top());
		s1.pop();
	}
	
	cout << "����֮��" << endl;
	while (!s.empty())
	{
		int tmp = s.top();
		cout << tmp << ' ';
		s.pop();
	}
}
int main4()
{
	//stack ջ�Ƚ����(FILO) ��֧��ͬһ�˲�����ɾ��
	//��֧�ֱ��� ֻ�ܷ���ջ��
	stest1();
	return 0;
}