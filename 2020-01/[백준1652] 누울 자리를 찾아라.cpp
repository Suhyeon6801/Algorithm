#include <iostream>
using namespace std;

char map[110][110];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	int row = 0, col = 0;
	int cnt;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == '.')
			{
				cnt++;
			}
			else if (map[i][j] == 'X')
			{
				if (cnt >= 2)	row++;
				cnt = 0;
			}
		}
		if (cnt >= 2)	row++;
	}

	for (int i = 0; i < n; i++)
	{
		cnt = 0;
		for (int j = 0; j < n; j++)
		{
			if (map[j][i] == '.')
			{
				cnt++;
			}
			else if (map[j][i] == 'X')
			{
				if (cnt >= 2)	col++;
				cnt = 0;
			}
		}
		if (cnt >= 2)	col++;
	}

	cout << row << " " << col << "\n";

	return 0;
}

/*
5
..X..
..X..
..X..
..X..
..X..
정답은 10 4
*/