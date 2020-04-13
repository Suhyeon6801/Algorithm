#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 510;
int N, M;
int map[MAX][MAX];
bool visit[MAX][MAX];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int dfs(int y, int x, int cnt)//ㅗ를 제외한 나머지 모양 -> 회전/대칭으로 dfs가능
{
	if (cnt == 4)
	{
		return map[y][x];
	}

	int sum = 0;

	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny >= 0 && nx >= 0 && ny < N && nx < M && !visit[ny][nx])
		{
			visit[ny][nx] = true;
			sum = max(sum, map[y][x] + dfs(ny, nx, cnt + 1));
			visit[ny][nx] = false;
		}
	}

	return sum;
}

int check(int y, int x)//ㅗ
{
	int sum = 0;

	if (y >= 1 && x >= 1 && x < M - 1)//ㅗ
	{
		sum = max(map[y][x] + map[y - 1][x] + map[y][x - 1] + map[y][x + 1], sum);
	}
	if (y >= 1 && y < N - 1 && x < M - 1)//ㅏ
	{
		sum = max(map[y][x] + map[y - 1][x] + map[y + 1][x] + map[y][x + 1], sum);
	}
	if (x >= 1 && y < N - 1 && x < M - 1)//ㅜ
	{
		sum = max(map[y][x] + map[y][x - 1] + map[y][x + 1] + map[y + 1][x], sum);
	}
	if (y >= 1 && x >= 1 && y < N - 1)//ㅓ
	{
		sum = max(map[y][x] + map[y][x - 1] + map[y - 1][x] + map[y + 1][x], sum);
	}

	return sum;
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
		}
	}

	//나 기준 하나씩 다 탐색
	int getMax = -1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			visit[i][j] = true;
			getMax = max(dfs(i, j, 1), getMax);//1부터 시작(나 포함해서 4개!)
			getMax = max(check(i, j), getMax);
			visit[i][j] = false;//초기화
		}
	}
	cout << getMax << "\n";

	return 0;
}