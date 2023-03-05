#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#define JUDGE 10

using namespace std;
void GetScore(vector<int>& v);
void DeleMaxMin(vector<int>& v, deque<deque<int>>& d);
void PrintPlayers(deque<deque<int>>& d);
int main()
{
	vector<int> score;
	deque<int> playera;
	deque<int> playerb;
	deque<int> playerc;
	deque<int> playerd;
	deque<int> playere;

	deque<deque<int>> players;
	players.push_back(playera);
	players.push_back(playerb);
	players.push_back(playerc);
	players.push_back(playerd);
	players.push_back(playere);

	for (int i = 0;i < 5;i++)
	{
		GetScore(score);
		DeleMaxMin(score, players);
	}
	PrintPlayers(players);
	return 0;
}

void GetScore(vector<int>& v)
{
	cout << "������������ί������" << endl;
	for (int i = 0;i < JUDGE;i++)
	{
		int x = 0;
		cin >> x;
		v.push_back(x);
	}	
	
}

void DeleMaxMin(vector<int>& v,deque<deque<int>>& d)
{
	static int cur = 0;
	for (int i = 0;i < JUDGE;i++)
	{
		d[cur].push_back(v[i]);
	}
	v.clear();
	sort(d[cur].begin(), d[cur].end());
	//ȥ�������ͷ�
	d[cur].pop_back();
	d[cur].pop_front();

	//�����۷�
	int sum = 0;
	for(int j=0;j<d[cur].size();j++)
		sum += d[cur][j];
	d[cur].push_back(sum / d[cur].size());
	cur++;
}

void PrintPlayers(deque<deque<int>>& d)
{
	for (int i = 0;i < 5;i++)
	{
		cout << "��" << i + 1 << "��ѡ��ȥ��һ����߷�����ͷֺ�" << endl;
		for (int j = 0;j < d[i].size()-1;j++)
			cout << d[i][j] << ' ';
		cout << "avg: " << d[i].back() << endl;
	}
}