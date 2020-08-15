#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[50][5];
int len[50][50];//각 숫자들의 길이
int dy[4] = { 0,-1,0,1 };
int dx[4] = { 1,0,-1,0 };

int getLen(int num)
{
	int ret = 0;
	while (num > 0)
	{
		num /= 10;
		ret++;
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int N = abs(r2 - r1 + 1);
	int M = abs(c2 - c1 + 1);
	int y = 0, x = 0, num = 1, dir = 0, h = 1;
	int val = N * M;
	int maxLen = -1;

	while (val>0)
	{
		for (int k = 0; k < 2; k++)
		{
			for (int i = 0; i < h; i++)
			{
				if (y >= r1 && x >= c1 && y <= r2 && x <= c2)
				{
					arr[y - r1][x - c1] = num;
					val--;
				}

				num++;
				y += dy[dir];
				x += dx[dir];
			}
			dir = (dir + 1) % 4;
		}
		h++;
	}

	//출력 ※최대 길이 기준으로 오른쪽에 붙여서
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			len[i][j] = getLen(arr[i][j]);
			maxLen = max(maxLen, getLen(arr[i][j]));
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (j > 0)
				cout << " ";

			for (int k = len[i][j]; k < maxLen; k++)
				cout << " ";

			cout << arr[i][j];
		}
		cout << "\n";
	}
	cout << "\n";

	return 0;
}