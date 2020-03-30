#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int Player = 10;
int N;
int arr[60][10];
bool visit[10];
int isSelect[10];
int getMax = -1;

void start_Game()
{
	int score = 0;
	int start_player = 1;
	int base[4];

	for (int i = 1; i <= N; i++)
	{
		int Out_cnt = 0;
		bool next = false;
		memset(base, 0, sizeof(base));

		while (1)
		{
			for (int j = start_player; j < Player; j++)
			{
				int p = arr[i][isSelect[j]];

				if (p == 0)	Out_cnt++;
				else if (p == 1)//안타
				{
					for (int k = 3; k >= 1; k--)//각 베이스에 있던 선수들 1루씩 이동!
					{
						if (base[k] == 1)
						{
							if (k == 3)//3루에 있으면 홈으로 이동해서 득점! 
							{
								score++;
								base[k] = 0;
							}
							else
							{
								base[k + 1] = 1;
								base[k] = 0;
							}
						}
					}
					base[1] = 1;//안타치고 1루로 이동
				}
				else if (p == 2)//2루타
				{
					for (int k = 3; k >= 1; k--)
					{
						if (base[k] == 1)
						{
							if (k == 2 || k==3)//2,3루에 있으면 홈으로 이동해서 득점!
							{
								score++;
								base[k] = 0;
							}
							else
							{
								base[k + 2] = 1;
								base[k] = 0;
							}
						}
					}
					base[2] = 1;
				}
				else if (p == 3)//3루타
				{
					for (int k = 3; k >= 1; k--)
					{
						if (base[k] == 1)
						{
							score++;
							base[k] = 0;
						}
					}
					base[3] = 1;
				}
				else if (p == 4)//홈런
				{
					for (int k = 3; k >= 1; k--)
					{
						if (base[k] == 1)//모든 베이스 다 들어옴
						{
							score++;
							base[k] = 0;
						}
					}
					score++;
				}

				if (Out_cnt == 3)//이닝 바꾸기
				{
					start_player = j + 1;//시작선수는 그 다음선수

					if (start_player == Player)	start_player = 1;//다 돌았으면 첨부터

					next = true;
					break;
				}
				
			}

			if (next)	break;
			start_player = 1;
		}
	}

	getMax = max(score, getMax);
}

void dfs(int x)
{
	if (x == Player)
	{
		start_Game();
		return;
	}

	for (int i = 1; i <Player; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			isSelect[i] = x;//i번선수의 타선은 x번
			dfs(x + 1);
			isSelect[i] = 0;
			visit[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <Player; j++)
		{
			cin >> arr[i][j];
		}
	}

	isSelect[4] = 1;//4번선수의 타선은 1번
	visit[4] = true;
	dfs(2);

	cout << getMax << "\n";

	return 0;
}