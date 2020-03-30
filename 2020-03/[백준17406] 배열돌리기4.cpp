#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Command {
	int idx, r, c, s;
};

Command cmd[10];
const int MAX = 60;
int arr[MAX][MAX];
int copyArr[MAX][MAX];
int rotateArr[MAX][MAX];
bool visit[10];
int isSelect[10];
int N, M, K;
int getMin = 987654321;

void copyFunc()
{
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			copyArr[i][j] = arr[i][j];
}

void rotateFunc(int r, int c, int s)
{
	memset(rotateArr, 0, sizeof(rotateArr));

	while (s > 0)
	{
		int sy = r - s;
		int sx = c - s;
		int ey = r + s;
		int ex = c + s;

		rotateArr[sy][sx] = copyArr[sy + 1][sx];

		sx += 1;
		for (int i = sx; i <= ex; i++)//->
			rotateArr[sy][i] = copyArr[sy][i - 1];

		sy += 1;
		for (int i = sy; i <= ey; i++)//↓
			rotateArr[i][ex] = copyArr[i - 1][ex];

		ex -= 1;
		for (int i = ex; i >= sx - 1; i--)//<-
			rotateArr[ey][i] = copyArr[ey][i + 1];

		ey -= 1;
		for (int i = ey; i >= sy; i--)//↑
			rotateArr[i][sx - 1] = copyArr[i + 1][sx - 1];

		s--;

	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			if (rotateArr[i][j] != 0)
				copyArr[i][j] = rotateArr[i][j];
}

void dfs(int x)
{
	if (x == K)
	{
		copyFunc();
		for (int i = 0; i < K; i++)
		{
			int temp = isSelect[i];

			rotateFunc(cmd[temp].r, cmd[temp].c, cmd[temp].s);
		}

		int sum = 0;
		for (int i = 1; i <= N; i++)
		{
			sum = 0;
			for (int j = 1; j <= M; j++)
			{
				sum += copyArr[i][j];
			}
			getMin = min(sum, getMin);
		}

		return;
	}

	for (int i = 0; i < K; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			isSelect[x] = cmd[i].idx;
			dfs(x + 1);
			visit[i] = false;
			isSelect[x] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		cin >> cmd[i].r >> cmd[i].c >> cmd[i].s;
		cmd[i].idx = i;
	}

	dfs(0);

	cout << getMin << "\n";

	return 0;
}