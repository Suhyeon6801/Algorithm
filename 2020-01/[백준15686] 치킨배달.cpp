#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAX = 60;
int n, m;
int map[MAX][MAX];
vector<pair<int, int>>v;
vector<pair<int, int>>v2;
bool check[15] = { 0, };//선책된 치킨집 확인
int result = 987654321;

int calc(pair<int,int> p1, pair<int,int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

void f(int cnt, int x)
{
	if (cnt == m)//집-치킨 거리 찾기
	{
		int sum = 0;
		for (int i = 0; i < v2.size(); i++)
		{
			int dist = 987654321;

			for (int j = 0; j < v.size(); j++)
			{
				if (check[j])
				{
					dist = min(dist, calc(v2[i], v[j]));
				}
			}
			sum += dist;			
		}

		result = min(result, sum);
		return;
	}

	if (x == v.size())	return;//기저조건.

	//선정
	check[x] = true;
	f(cnt + 1, x + 1);
	//선정안함
	check[x] = false;
	f(cnt, x + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 2)	v.push_back(make_pair(i, j));
			else if (map[i][j] == 1)	v2.push_back(make_pair(i, j));
		}
	}

	f(0, 0);
	
	cout << result << "\n";
	return 0;
}