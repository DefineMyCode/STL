#include <queue>//����
#include <iostream>
using namespace std;

void qtest()
{
	queue<int> q;
	for (int i = 1;i <= 10;i++)
	{
		q.push(i);
	}
	queue<int> q1 = q;
	cout << "q.size()=" << q.size() << endl;

	while (!q.empty())
	{
		int tmp=q.front();
		cout << tmp << ' ';
		q.pop();
	}
	cout << "q.size()=" << q.size() << endl;

}
int main5()
{
	//ֻ�ܷ��ʶ�ͷ���β
	//���Է��ʶ�β--back()  ��ͷfront()
	qtest();
	return 0;
}