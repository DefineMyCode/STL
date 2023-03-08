#include <queue>//队列
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
	//只能访问队头与队尾
	//可以访问队尾--back()  队头front()
	qtest();
	return 0;
}