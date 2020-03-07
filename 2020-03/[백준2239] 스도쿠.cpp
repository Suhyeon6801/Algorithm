#include <iostream>
using namespace std;

int arr[9][9];
bool box[9][9];
bool row[9][9];
bool col[9][9];

int boxPos(int y, int x)
{
	return (y / 3) * 3 + (x / 3);
}

void f(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
		exit(0);
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (arr[y][x] != 0)	
		f(cnt + 1);
	else
	{
		for (int k = 1; k <= 9; k++)
		{
			if (!row[y][k] && !col[k][x] && !box[boxPos(y, x)][k])
			{
				row[y][k] = true;
				col[k][x] = true;
				box[boxPos(y, x)][k] = true;
				arr[y][x] = k;
				f(cnt + 1);
				row[y][k] = false;
				col[k][x] = false;
				box[boxPos(y, x)][k] = false;
				arr[y][x] = 0;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	char c;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> c;

			arr[i][j] = c - '0';

			if (arr[i][j] != 0)
			{
				row[i][arr[i][j]] = true;
				col[arr[i][j]][j] = true;
				box[boxPos(i, j)][arr[i][j]] = true;
			}
		}
	}

	f(0);

	return 0;
}