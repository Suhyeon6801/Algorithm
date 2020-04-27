#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 30;
int map[MAX][MAX];
int N;
int arr[MAX][MAX];
int result = 987654321;
int sumArea[6] = { 0 };
struct Point {
	int y, x;
};
Point point[4];

bool isBoundary(int x, int y, int d1, int d2)
{
	if (x + d1 >= N || y - d1 < 0)	return false;
	if (x + d2 >= N || y + d2 >= N)	return false;
	if (x + d1 + d2 >= N || y - d1 + d2 >= N)	return false;
	if (x + d2 + d1 >= N || y + d2 - d1 < 0)	return false;

	return true;
}

void getResult()
{
	memset(sumArea, 0, sizeof(sumArea));
	int getMax = -1, getMin = 987654321;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			sumArea[arr[i][j]] = sumArea[arr[i][j]] + map[i][j];
		}
	}

	for (int i = 1; i <= 5; i++)
	{
		if (getMax < sumArea[i])
			getMax = sumArea[i];

		if (getMin > sumArea[i])
			getMin = sumArea[i];
	}

	int temp = getMax - getMin;

	if (result > temp)
		result = temp;
}

void getNumber()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			arr[i][j] = 5;

	int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;

	for (int i = 0; i < point[1].x; i++)
	{
		if (i >= point[0].x)	cnt1++;

		for (int j = 0; j <= point[0].y - cnt1; j++)
		{
			arr[i][j] = 1;
		}
	}

	for (int i = 0; i <= point[2].x; i++)
	{
		if (i > point[0].x)	cnt2++;
		for (int j = point[0].y + 1 + cnt2; j < N; j++)
		{
			arr[i][j] = 2;
		}
	}

	for (int i = N - 1; i >= point[1].x; i--)
	{
		if (i < point[3].x)	cnt3++;
		for (int j = 0; j < point[3].y - cnt3; j++)
			arr[i][j] = 3;
	}

	for (int i = N - 1; i > point[2].x; i--)
	{
		if (i <= point[3].x)	cnt4++;
		for (int j = point[3].y + cnt4; j < N; j++)
			arr[i][j] = 4;
	}

	getResult();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			for (int d1 = 1; d1 <= j; d1++)
			{
				for (int d2 = 1; d2 < N - j; d2++)
				{
					if (isBoundary(i, j, d1, d2))
					{
						point[0].x = i, point[0].y = j;
						point[1].x = i + d1, point[1].y = j - d1;
						point[2].x = i + d2, point[2].y = j + d2;
						point[3].x = i + d1 + d2, point[3].y = j -d1 +d2;

						getNumber();
					}
				}
			}
		}
	}

	cout << result << "\n";

	return 0;
}