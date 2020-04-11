#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int paper[10][10];
int paper_cnt[6] = { 0,5,5,5,5,5 };
int getMin = INF;
int cnt = 0;

void f(int y, int x)
{
	//기저조건 y==10이면 확인 끝!
	if (y == 10)
	{
		getMin = min(getMin, cnt);
		return;
	}

	if (x == 10)
	{
		f(y + 1, 0);//담줄 확인
		return;
	}

	if (paper[y][x] == 0)
	{
		f(y, x + 1);
	}
	else
	{
		for (int len = 5; len >= 1; len--)
		{
			if (paper_cnt[len] == 0 || y + len > 10 || x + len > 10)	continue;

			bool flag = true;
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					if (paper[y + i][x + j] == 0)
					{
						flag = false;
						break;
					}
				}

				if (!flag)
					break;
			}

			if (!flag)//존재하지 않는 경우 -> 패스
				continue;

			//존재하면 덮어보고
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					paper[y+i][x+j] = 0;
				}
			}

			paper_cnt[len]--;
			cnt++;

			f(y, x + len);//담꺼 확인

			//초기화
			for (int i = 0; i < len; i++)
			{
				for (int j = 0; j < len; j++)
				{
					paper[y + i][x + j] = 1;
				}
			}

			paper_cnt[len]++;
			cnt--;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> paper[i][j];
		}
	}

	f(0, 0);

	if (getMin == INF)
		cout << "-1\n";
	else
		cout << getMin << "\n";

	return 0;
}