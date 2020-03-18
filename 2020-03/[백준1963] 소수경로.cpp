#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

int prime[10010];
bool visit[10010];

bool isPrime(int x)
{
	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}

	return true;
}

int change_num(int num, int index, int other)
{
	int temp;

	if (index == 0)//천의 자리
	{
		temp = num % 1000;
		temp += other * 1000;
	}
	else if (index == 1)//백의 자리
	{
		int a = num / 1000;
		int b = num % 100;
		temp = a * 1000 + other * 100 + b;
	}
	else if (index == 2)//십의 자리
	{
		int a = num / 1000;
		int b = (num % 1000) / 100;
		int c = num % 10;
		temp = a * 1000 + b * 100 + other * 10 + c;
	}
	else //의자리
	{
		int a = num / 1000;
		int b = (num % 1000) / 100;
		int c = (num / 10) % 10;
		temp = a * 1000 + b * 100 + c * 10 + other;
	}

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int testcase;
	cin >> testcase;
	for (int tc = 1; tc <= testcase; tc++)
	{
		int p1, p2;
		queue<pair<int, int>> que;
		memset(visit, 0, sizeof(visit));
		cin >> p1 >> p2;

		que.push(make_pair(p1, 0));
		visit[p1] = true;

		bool flag = false;
		while (!que.empty())
		{
			int cur = que.front().first;
			int cnt = que.front().second;
			que.pop();

			if (cur == p2)
			{
				cout << cnt << "\n";
				flag = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j <= 9; j++)
				{
					int num = change_num(cur, i, j);

					if (num < 1000 || !isPrime(num) || visit[num])	continue;
					else
					{
						visit[num] = true;
						que.push(make_pair(num, cnt + 1));
					}
				}
			}
		}

		if (!flag)
			cout << "impossible\n";
	}

	return 0;
}