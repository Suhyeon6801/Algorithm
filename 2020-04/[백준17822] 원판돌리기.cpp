#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 60;
int N, M, T;
int map[MAX][MAX];
int c_map[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
bool visit[MAX][MAX];
struct Command {
	int x, d, k;
};
vector<Command> cmd;

void RotateMap(int x, int d, int k)
{
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			c_map[i][j] = map[i][j];

	if (d == 0)
	{
		for (int i = 0; i < M; i++)
		{
			int val = map[x][i];
			int temp = (k + i) % M;
			c_map[x][temp] = val;
		}
	}
	else
	{
		for (int i = 0; i < M; i++)
		{
			int val = map[x][i];
			int temp = k % M;
			int pos = i - temp;
			if (pos < 0)	pos += M;
			c_map[x][pos] = val;
		}
	}

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			map[i][j] = c_map[i][j];
}

bool bfs(int i, int j)//인접한 값이 있는지 탐색
{
	queue<pair<int, int>> que;
	vector<pair<int, int>> adj;//인접한 애들 모아두는 곳
	visit[i][j] = true;
	que.push({ i,j });
	adj.push_back({ i,j });

	while (!que.empty())
	{
		int rad = que.front().first;
		int idx = que.front().second;
		que.pop();

		int curVal = map[rad][idx];

		int left_rad = rad - 1;
		int right_rad = rad + 1;
		int left_idx = idx - 1;
		int right_idx = idx + 1;

		if (left_idx < 0)
			left_idx = M - 1;
		if (right_idx >= M)
			right_idx %= M;

		if (curVal == map[rad][left_idx])
		{
			if (!visit[rad][left_idx])
			{
				visit[rad][left_idx] = true;
				que.push({ rad,left_idx });
				adj.push_back({ rad,left_idx });
			}
		}

		if (curVal == map[rad][right_idx])
		{
			if (!visit[rad][right_idx])
			{
				visit[rad][right_idx] = true;
				que.push({ rad,right_idx });
				adj.push_back({ rad,right_idx });
			}
		}

		if (left_rad >= 1)
		{
			if (curVal == map[left_rad][idx])
			{
				if (!visit[left_rad][idx])
				{
					visit[left_rad][idx] = true;
					que.push({ left_rad,idx });
					adj.push_back({ left_rad,idx });
				}
			}
		}

		if (right_rad <= N)
		{
			if (curVal == map[right_rad][idx])
			{
				if (!visit[right_rad][idx])
				{
					visit[right_rad][idx] = true;
					que.push({ right_rad,idx });
					adj.push_back({ right_rad,idx });
				}
			}
		}
	}

	if (adj.size() == 1)
		return false;
	else
	{
		for (int i = 0; i < adj.size(); i++)
		{
			map[adj[i].first][adj[i].second] = 0;
		}
		return true;
	}
}

bool isAdj()//인접한 곳에 같은 수가 있는지 확인하기!
{
	memset(visit, 0, sizeof(visit));
	bool flag = false;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!visit[i][j] && map[i][j] != 0)
			{
				if (bfs(i, j))
					flag = true;
			}
		}
	}

	return flag;
}

void calc()
{
	int sum = 0;
	int total = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			sum += map[i][j];
			if (map[i][j] != 0)
				total++;
		}
	}

	double ave = (double)sum / (double)total;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] != 0)
			{
				if ((double)map[i][j] > ave)
					map[i][j] -= 1;
				else if ((double)map[i][j] < ave)
					map[i][j] += 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T;

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	for (int i = 0; i < T; i++)
	{
		int x, d, k;
		cin >> x >> d >> k;
		cmd.push_back({ x,d,k });
	}

	for (int i = 0; i < cmd.size(); i++)
	{
		int x = cmd[i].x;
		int d = cmd[i].d;
		int k = cmd[i].k;

		for (int j = x; j <= N; j += x)
		{
			RotateMap(j, d, k);
		}

		if (!isAdj())//인접하면서 같은수가 없음.
		{
			calc();
		}
	}

	int result = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			result += map[i][j];
		}
	}

	cout << result << "\n";

	return 0;
}