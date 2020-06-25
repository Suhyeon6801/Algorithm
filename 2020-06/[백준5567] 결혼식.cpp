#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int MAX = 510;
int N, M;
vector<int> v[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	int cnt = 0;
	vector<int> f;
	set<int> s;

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < v[1].size(); i++)
	{
		f.push_back(v[1][i]);
	}

	for (int i = 0; i < f.size(); i++)
	{
		int temp = f[i];
		s.insert(temp);
		for (int j = 0; j < v[temp].size(); j++)
		{
			int next = v[temp][j];
			s.insert(next);
		}
	}

	cout << s.size() - 1 << "\n";
	return 0;
}