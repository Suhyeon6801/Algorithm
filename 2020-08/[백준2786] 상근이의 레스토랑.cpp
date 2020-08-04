#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int INF = 1e9;
int N;
vector<pair<int, int>> v;
int getPrice[500010];

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.second < p2.second;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		v.push_back({ a,b });
	}

	sort(v.begin(), v.end(), comp);
	getPrice[N] = INF;

	//1. 첫주문 가격이 작을 때, 2. 첫주문-일반가격 주문이 작을 때
	for (int i = N - 1; i >= 0; i--)
	{
		getPrice[i] = min(v[i].first, getPrice[i + 1]);
	}

	int k = 0;
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (v[i].second - v[i].first > v[k].second - v[k].first)
			k = i;
		sum += v[i].second;
		cout << min(sum - v[k].second + v[k].first, sum - v[i].second + getPrice[i]) << "\n";
	}

	return 0;
}