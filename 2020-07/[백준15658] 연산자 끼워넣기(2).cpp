#include <iostream>
using namespace std;

const int INF = 1000000010;
int oper[4];
int arr[20];
int choose[20];
int N;
int getMax = -INF, getMin = INF;

int calc()
{
	int ret = arr[0];
	for (int i = 0; i < N - 1; i++)
	{
		if (choose[i] == 0)
			ret += arr[i + 1];
		else if (choose[i] == 1)
			ret -= arr[i + 1];
		else if (choose[i] == 2)
			ret *= arr[i + 1];
		else if (choose[i] == 3)
			ret /= arr[i + 1];
	}

	return ret;
}

void dfs(int cnt)
{
	if (cnt == N - 1)
	{
		int result = calc();

		if (getMax < result)	getMax = result;
		if (getMin > result)	getMin = result;

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] != 0)
		{
			oper[i]--;
			choose[cnt] = i;
			dfs(cnt + 1);
			oper[i]++;
			choose[cnt] = 0;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < 4; i++)
		cin >> oper[i];

	dfs(0);

	cout << getMax << "\n";
	cout << getMin << "\n";

	return 0;
}