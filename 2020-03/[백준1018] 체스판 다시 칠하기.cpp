#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 60;
char chess[MAX][MAX];
char Black[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};
char White[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};

int N, M;

int BlackFirst(int y, int x)//(0,0)이 B일때
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (chess[i][j] != Black[i - y][j - x])	cnt++;
		}
	}
	return cnt;
}

int WhiteFirst(int y, int x)
{
	int cnt = 0;
	for (int i = y; i < y + 8; i++)
	{
		for (int j = x; j < x + 8; j++)
		{
			if (chess[i][j] != White[i - y][j - x])	cnt++;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int result = 987654321;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> chess[i][j];
		}
	}

	for (int i = 0; i+7 < N; i++)
	{
		for (int j = 0; j+7 < M; j++)
		{
			result = min(result,min(BlackFirst(i, j), WhiteFirst(i, j)));
		}
	}
	cout << result << "\n";

	return 0;
}