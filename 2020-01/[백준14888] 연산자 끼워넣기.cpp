#include <iostream>
#include <algorithm>
using namespace std;

int getMax = -1000001000;
int getMin = 1000000100;
int num[15];
int op[15];
int oper[4];
bool visit[4];
int idx = 0;
int n;

int calc()
{
	int sum = num[0];
	for (int i = 0; i < n - 1; i++)
	{
		if (op[i] == 1)
			sum += num[i + 1];
		else if (op[i] == 2)
			sum -= num[i + 1];
		else if (op[i] == 3)
			sum *= num[i + 1];
		else if (op[i] == 4)
			sum /= num[i + 1];
	}

	return sum;
}

void dfs(int len)
{
	if (len == n - 1)
	{
		int result = calc();

		getMax = max(result, getMax);
		getMin = min(result, getMin);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i]!=0)
		{
			oper[i]--;
			op[len] = i + 1;
			dfs(len + 1);
			oper[i]++;
			op[len] = 0;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	int o;
	for (int i = 0; i < 4; i++)
	{
		cin >> oper[i];
	}

	dfs(0);

	cout << getMax << "\n";
	cout << getMin << "\n";
	
	return 0;
}