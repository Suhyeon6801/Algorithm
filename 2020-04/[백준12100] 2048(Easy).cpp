#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 30;
int N;
int map[MAX][MAX];
int board[MAX][MAX];
int order[5];
int answer = 0;

void copyBoard()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			map[i][j] = board[i][j];
}

int getScore()
{
	int result = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (result < map[i][j])
				result = map[i][j];
		}
	}

	return result;
}

void Right()
{
	//1.오른쪽으로 모든 data를 이동
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			bool check = false;
			if (map[i][j] == 0)
			{
				int k = j - 1;
				while (k >= 0)
				{
					if (map[i][k] != 0)
					{
						check = true;
						break;
					}
					k--;
				}

				if (check)
				{
					map[i][j] = map[i][k];
					map[i][k] = 0;
				}
			}		
		}
	}

	//2.가장 오른쪽부터 자기좌표-1의 값이랑 같으면 그 값 2배해주고 좌표-1은 0
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (map[i][j] == map[i][j - 1])
			{
				map[i][j] *= 2;
				map[i][j - 1] = 0;
			}
		}
	}

	//3.1번이랑 똑같이.
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			bool check = false;
			if (map[i][j] == 0)
			{
				int k = j - 1;
				while (k >= 0)
				{
					if (map[i][k] != 0)
					{
						check = true;
						break;
					}
					k--;
				}

				if (check)
				{
					map[i][j] = map[i][k];
					map[i][k] = 0;
				}
			}
		}
	}
}

void Down()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			bool check = false;
			if (map[j][i] == 0)
			{
				int k = j - 1;
				
				while (k >= 0)
				{
					if (map[k][i] != 0)
					{
						check = true;
						break;
					}
					k--;
				}

				if (check)
				{
					map[j][i] = map[k][i];
					map[k][i] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			if (map[j][i] == map[j - 1][i])
			{
				map[j][i] *= 2;
				map[j - 1][i] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = N - 1; j > 0; j--)
		{
			bool check = false;
			if (map[j][i] == 0)
			{
				int k = j - 1;

				while (k >= 0)
				{
					if (map[k][i] != 0)
					{
						check = true;
						break;
					}
					k--;
				}

				if (check)
				{
					map[j][i] = map[k][i];
					map[k][i] = 0;
				}
			}
		}
	}
}

void Up()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool check = false;
			if (map[j][i] == 0)
			{
				int k = j + 1;
				while (k < N)
				{
					if (map[k][i] != 0)
					{
						check = true;
						break;
					}
					k++;
				}

				if (check)
				{
					map[j][i] = map[k][i];
					map[k][i] = 0;
				}
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (map[j][i] == map[j + 1][i])
			{
				map[j][i] *= 2;
				map[j + 1][i] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool check = false;
			if (map[j][i] == 0)
			{
				int k = j + 1;
				while (k < N)
				{
					if (map[k][i] != 0)
					{
						check = true;
						break;
					}
					k++;
				}

				if (check)
				{
					map[j][i] = map[k][i];
					map[k][i] = 0;
				}
			}
		}
	}
}

void Left()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool check = false;

			if (map[i][j] == 0)
			{
				int k = j + 1;
				while (k < N)
				{
					if (map[i][k] != 0)
					{
						check = true;
						break;
					}
					k++;
				}
				if (check)
				{
					map[i][j] = map[i][k];
					map[i][k] = 0;
				}
			}		
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			if (map[i][j] == map[i][j + 1])
			{
				map[i][j] *= 2;
				map[i][j + 1] = 0;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1; j++)
		{
			bool check = false;

			if (map[i][j] == 0)
			{
				int k = j + 1;
				while (k < N)
				{
					if (map[i][k] != 0)
					{
						check = true;
						break;
					}
					k++;
				}
				if (check)
				{
					map[i][j] = map[i][k];
					map[i][k] = 0;
				}
			}
		}
	}
}

void Play()
{
	for (int i = 0; i < 5; i++)
	{
		int d = order[i];

		if (d == 0)	Right();
		else if (d == 1)	Down();
		else if (d == 2)	Left();
		else if (d == 3)	Up();
	}

	answer = max(getScore(), answer);
}

void dfs(int cnt, int idx)
{
	if (cnt == 5)
	{
		copyBoard();
		Play();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		order[cnt] = i;
		dfs(cnt + 1, i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];

	dfs(0, 0);
	cout << answer << "\n";

	return 0;
}