#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1010;
queue<pair<int, int>> que;
int n, m;//m가로,n세로
int box[MAX][MAX] = { 0, };
bool visit[MAX][MAX] = { 0, };
int check[MAX][MAX] = { 0, };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int ripe = 0, not_ripe = 0, no_tomato = 0;
int day = 0;

int bfs()
{	
	int tomato = 0;
	while (!que.empty())
	{
		int size = que.size();

		while (size--)
		{
			int y = que.front().first;
			int x = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + dy[i];
				int nx = x + dx[i];

				if (ny < 0 || nx < 0 || ny >= n || nx >= m || box[ny][nx] != 0)	continue;
				else 
				{					
					if (!visit[ny][nx])
					{
						que.push(make_pair(ny, nx));
						visit[ny][nx] = true;
						check[ny][nx] = 1;
						//not_ripe--;
					}
				}
			}
		}
		day++;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (check[i][j] == 1)	tomato++;
		}
	}

	//cout << tomato - ripe << " " << not_ripe << endl;

	if (tomato-ripe == not_ripe)	return day;
	else	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> m >> n;//m가로,n세로

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];

			if (box[i][j] == 1)
			{
				que.push(make_pair(i, j));
				visit[i][j] = true;
				check[i][j] = 1;
				ripe++;
			}
			else if (box[i][j] == 0)
			{
				visit[i][j] = false;
				not_ripe++;
			}
		}
	}

	if (not_ripe == 0) {
		cout << "0\n";
		return 0;
	}

	bool flag = true;
	while (1)
	{
		int result = bfs();

		if (result == -1)
		{
			flag = false;
			break;
		}
		else
		{
			break;
		}

	}
	
	if (flag)
		cout << day - 1 << "\n";
	else
		cout << "-1\n";

	return 0;
}