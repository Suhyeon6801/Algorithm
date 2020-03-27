#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <cstdlib>
using namespace std;

string str;
char papers[10];
bool visit[10];
char result[10];
set <int> number;

bool isPrime(int x)
{
	if (x == 1 || x == 0)	return false;

	for (int i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return false;
	}

	return true;
}

void dfs(int len, int idx)
{
	if (idx == len)
	{
		int temp = atoi(result);

		if (isPrime(temp))
			number.insert(temp);

		return;
	}

	for (int i = 0; i < str.length(); i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			result[idx] = papers[i];
			dfs(len, idx + 1);
			result[idx] = 0;
			visit[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int c;
	cin >> c;

	for (int tc = 1; tc <= c; tc++)
	{
		cin >> str;

		for (int i = 0; i < str.length(); i++)
			papers[i] = str[i];

		for (int i = 1; i <= str.length(); i++)
		{
			memset(visit, 0, sizeof(visit));
			memset(result, 0, sizeof(result));

			dfs(i, 0);
		}

		cout << number.size() << "\n";

		number.clear();
	}

	return 0;
}