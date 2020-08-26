#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1010;
int N;
int arr[MAX][MAX];
int par[MAX];
vector<pair<int, pair<int, int>>> v;//cost, from, to 순

int find(int x)
{
	if (par[x] == x)	return x;
	else	return par[x] =  find(par[x]);
}

void merge(int a, int b)
{
	int pa = find(a);
	int pb = find(b);

	par[pa] = pb;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i == j)	continue;
			v.push_back({ arr[i][j], {i,j} });
		}
	}

	for (int i = 0; i <= N; i++)
		par[i] = i;

	sort(v.begin(), v.end());

	int cnt = 0;
	long long result = 0;

	for (int i = 0; i < v.size(); i++)
	{
		int p1 = v[i].second.first;
		int p2 = v[i].second.second;
		int c = v[i].first;

		if (find(p1) != find(p2))
		{
			result += c;
			merge(p1, p2);
			cnt++;

			if (cnt == N - 1)
				break;
		}
	}

	cout << result << "\n";

	return 0;
}