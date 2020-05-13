#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10010;
int N, M;
vector<int> v[MAX];
bool visit[MAX];
int cnt = 0; 
int getMax;

void dfs(int x)
{
	visit[x] = true;
	cnt++;

	for (int i = 0; i < v[x].size(); i++)
	{
		int y = v[x][i];
		if (!visit[y])
			dfs(y);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B;
	vector<int> ans;
	cin >> N >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		v[B].push_back(A);
	}

	int ret = 0;

	for (int i = 1; i <= N; i++)
	{
		memset(visit, 0, sizeof(visit));
		cnt = 0;

		dfs(i);

		if (ret == cnt)
			ans.push_back(i);
		if (ret < cnt)
		{
			ret = cnt;
			ans.clear();
			ans.push_back(i);
		}
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << "\n";

	return 0;
}