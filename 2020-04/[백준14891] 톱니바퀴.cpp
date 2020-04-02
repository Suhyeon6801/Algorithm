#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int arr[5][8];

bool check(int x, int y)//회전해야할지 확인
{
	if (x < y)
	{
		if (arr[x][2] != arr[y][6])
			return true;
		else
			return false;
	}
	else
	{
		if (arr[x][6] != arr[y][2])
			return true;
		else
			return false;
	}
}

void rotate(int x, int dir)
{
	int temp[8];
	for (int i = 0; i < 8; i++)
		temp[i] = arr[x][i];

	if (dir == -1)
	{
		for (int i = 0; i <= 6; i++)
			arr[x][i] = temp[i + 1];

		arr[x][7] = temp[0];
	}
	else
	{
		for (int i = 1; i < 8; i++)
			arr[x][i] = temp[i - 1];

		arr[x][0] = temp[7];
	}
}

void checkLeft(int x, int dir)
{
	if (x < 1 || x>4)	return;//범위 벗어남

	if (check(x, x + 1))
	{
		checkLeft(x - 1, dir*(-1));//재귀 돌려서 확인
		rotate(x, dir);
	}
}

void checkRight(int x, int dir)
{
	if (x < 1 || x>4)	return;//범위 벗어남

	if (check(x, x - 1))
	{
		checkRight(x + 1, dir*(-1));
		rotate(x, dir);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	}

	int K, num, dir;
	queue<pair<int, int>> que;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> num >> dir;

		checkLeft(num - 1, dir*(-1));
		checkRight(num + 1, dir*(-1));
		rotate(num, dir);
	}

	int ans = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (arr[i][0] != 0)
			ans += arr[i][0] * (int)pow(2, i - 1);
	}

	cout << ans << "\n";

	return 0;
}