#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, M;
char map[20][20];
bool visit[20][20][20][20];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int rx, ry, bx, by, destY, destX;
queue<pair<int, int>> red;
queue<pair<int, int>> blue;
int cnt = 0;
bool isEscape = false;

int getDist(int y1, int x1, int y2, int x2)
{
	return abs(y1 - y2) + abs(x1 - x2) ;
}

void bfs()
{
	while (!red.empty())
	{
		int size = red.size();

		while (size--)
		{
			ry = red.front().first;
			rx = red.front().second;
			by = blue.front().first;
			bx = blue.front().second;
			red.pop();
			blue.pop();

			if (cnt > 10)	break;

			if (ry == destY && rx == destX)
			{
				isEscape = true;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int nry = ry + dy[i];
				int nrx = rx + dx[i];
				int nby = by + dy[i];
				int nbx = bx + dx[i];

                //상하좌우이동
				while (1)
				{
					if (map[nry][nrx] == '#')//원위치
					{
						nry -= dy[i];
						nrx -= dx[i];
						break;
					}

					if (map[nry][nrx] == 'O')	break;
					
					nry += dy[i];
					nrx += dx[i];
				}

				while (1)
				{
					if (map[nby][nbx] == '#')//원위치
					{
						nby -= dy[i];
						nbx -= dx[i];
						break;
					}

					if (map[nby][nbx] == 'O')	break;

					nby += dy[i];
					nbx += dx[i];
				}

				if (nby == destY && nbx == destX)	continue;

				if (nry == nby && nrx == nbx)
				{
					int rDist = getDist(ry, rx,nry, nrx);
					int bDist = getDist(by, bx, nby, nbx);

					if (rDist > bDist)
					{
						nry -= dy[i];
						nrx -= dx[i];
					}
					else
					{
						nby -= dy[i];
						nbx -= dx[i];
					}
				}

				if (visit[nry][nrx][nby][nbx])	continue;
				
				red.push(make_pair(nry, nrx));
				blue.push(make_pair(nby, nbx));
				visit[nry][nrx][nby][nbx] = true;
			}
		}

		if (isEscape)	break;
		else
			cnt++;
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 'R')
			{
				ry = i, rx = j;
				red.push(make_pair(i, j));
			}
			else if (map[i][j] == 'B')
			{
				by = i, bx = j;
				blue.push(make_pair(i, j));
			}
			else if (map[i][j] == 'O')
			{
				destY = i, destX = j;
			}
		}
	}

	visit[ry][rx][by][bx] = true;

	bfs();
	if (isEscape)	cout << cnt << "\n";
	else
		cout << "-1\n";


	return 0;
}