#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10;
int N, M;
int map[MAX][MAX];
int arr[MAX][MAX];//복사할map
vector<pair<int, int>> camera;
vector<int> angle;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool visit[MAX][MAX][4];
int getMin = 987654321;

void CopyMap()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			arr[i][j] = map[i][j];
}

int BlindSpot()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)	cnt++;
		}
	}
	return cnt;
}

void printArr()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void dfs(int cnt)
{
	if (cnt == camera.size())
	{
		CopyMap();
		//각 카메라 각도에 맞춰서 카메라가 비추는 곳은 7로 표기해주자
		for (int i = 0; i < angle.size(); i++)
		{
			int y = camera[i].first;
			int x = camera[i].second;

			for (int j = 0; j < 4; j++)
			{
				if (visit[y][x][j])
				{
					int dir = (angle[i] + j) % 4;
					int ny = y + dy[dir];
					int nx = x + dx[dir];

					while (1)
					{
						if (ny < 0 || nx < 0 || ny >= N || nx >= M || arr[ny][nx] == 6)	break;

						if (arr[ny][nx] == 0)
							arr[ny][nx] = 7;

						ny += dy[dir];
						nx += dx[dir];
					}

				}			
			}
		}		
		getMin = min(BlindSpot(), getMin);
		return;
	}

	for (int i = 0; i < 4; i++)//카메라 별로 각도 고르기
	{	
		angle.push_back(i);
		dfs(cnt + 1);
		angle.pop_back();
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

			if (map[i][j] >= 1 && map[i][j] <= 5)
				camera.push_back({ i,j });

			//카메라 별 감시 방향 체크
			if (map[i][j] == 1)
			{
				visit[i][j][0] = true;
			}
			else if (map[i][j] == 2)
			{
				visit[i][j][0] = true;
				visit[i][j][2] = true;
			}
			else if (map[i][j] == 3)
			{
				visit[i][j][0] = true;
				visit[i][j][1] = true;
			}
			else if (map[i][j] == 4)
			{
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				visit[i][j][2] = true;
			}
			else if (map[i][j] == 5)
			{
				visit[i][j][0] = true;
				visit[i][j][1] = true;
				visit[i][j][2] = true;
				visit[i][j][3] = true;
			}
		}
	}

	dfs(0);
	cout << getMin << "\n";

	return 0;
}