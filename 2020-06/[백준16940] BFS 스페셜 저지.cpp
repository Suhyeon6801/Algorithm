#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100010;
vector<int> v[MAX];
bool visit[MAX];
vector<int> v2;
vector<int> order[MAX];

bool comp(int a, int b)
{
	return order[a] < order[b];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		int m;
		cin >> m;
		v2.push_back(m);
		order[m].push_back(i);//1번 순서 1, 2번순서 2, 3번순서 3이런식으로..
	}

    //order순으로 인접리스트 정렬
	for (int i = 1; i <= N; i++)
		sort(v[i].begin(), v[i].end(), comp);

	vector<int> result;
	queue<int> que;
	que.push(1);
	visit[1] = true;

	while (!que.empty())
	{
		int cur = que.front();
		que.pop();

		result.push_back(cur);

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			if (!visit[next])
			{
				que.push(next);
				visit[next] = true;
			}
		}
	}

	if (result == v2)	cout << "1\n";
	else cout << "0\n";

	return 0;
}