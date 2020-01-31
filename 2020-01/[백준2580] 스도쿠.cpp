#include <iostream>
using namespace std;

int arr[9][9];
bool row[9][9];
bool col[9][9];
bool box[9][9];

int boxIndex(int y, int x)
{
	return (y / 3) * 3 + x / 3;
}

void f(int cnt)
{
	if (cnt == 81)
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		exit(0);//바로 종료해버림.
	}

	int y = cnt / 9;
	int x = cnt % 9;

	if (arr[y][x] != 0)	f(cnt + 1);
	else
	{
		for (int i = 1; i <= 9; i++)
		{
			if (!row[y][i] && !col[x][i] && !box[boxIndex(y, x)][i])
			{
				row[y][i] = true;
				col[x][i] = true;
				box[boxIndex(y, x)][i] = true;
				arr[y][x] = i;
				f(cnt + 1);
				row[y][i] = false;
				col[x][i] = false;
				box[boxIndex(y, x)][i] = false;
				arr[y][x] = 0;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];

			if (arr[i][j] != 0)
			{
				row[i][arr[i][j]] = true;
				col[j][arr[i][j]] = true;
				box[boxIndex(i, j)][arr[i][j]] = true;
			}
		}
	}

	f(0);

	return 0;
}