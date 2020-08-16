#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 110;
string scroll, devil, angel;
int dp[MAX][MAX][2];//현재 밟은 문자가 G이고 다음 문자가 S일 때, 현재 악마돌다리 위에 있음. 

int f(int cur, int next, int pos)
{
	if (next == scroll.length())	return 1;

	int &ret = dp[cur][next][pos];
	if (ret != -1)	return ret;

	int sum = 0;

	if (pos == 0)
	{
		for (int i = cur; i < devil.length(); i++)
		{
			if (scroll[next] == devil[i])
				sum+=f(i + 1, next + 1, 1);
		}
	}
	else
	{
		for (int i = cur; i < angel.length(); i++)
		{
			if (scroll[next] == angel[i])
				sum+=f(i + 1, next + 1, 0);
		}
	}

	return dp[cur][next][pos] = sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> scroll;
	cin >> devil;
	cin >> angel;

	memset(dp, -1, sizeof(dp));

	int d = f(0, 0, 0);//시작이 악마돌다리
	int a = f(0, 0, 1);//시작이 천사돌다리

	cout << d + a << "\n";

	return 0;
}