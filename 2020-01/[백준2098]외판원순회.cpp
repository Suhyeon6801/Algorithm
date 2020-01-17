#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int IMPOSSIBLE = 1000000000;
int w[16][16];
int n;
int start = 0;
int dp[16][65536];

int TSP(int currentTown, int visited)
{
	//현재 외판원은 currentTown에 위치하고, 방문한 마을이 모두 visited일때 
	//앞으로 남은 모든 마을을 방문하고 0번 마을로 돌아갈 때 드는 최소 비용

	//기저조건 => 모든 마을을 방문한 경우
	//현재마을에서 다시 시작지점으로 돌아 갈 수 있으면 해당 비용 반환, 그렇지 않다면 불가능한 값을 반환한다.
	if (visited == (1 << n) - 1)
	{
		if (w[currentTown][start]!=0)
			return w[currentTown][start];
		else
			return IMPOSSIBLE;
	}
	int &ret = dp[currentTown][visited];
	if (ret != -1)	return ret;

	ret = IMPOSSIBLE;
	//아직 방문하지 않은 곳을 순회해본다.
	for (int i = 0; i < n; i++)
	{
		if (visited&(1 << i))	continue;
		if (w[currentTown][i] == 0)	continue;
		ret = min(ret, TSP(i, visited | (1 << i)) + w[currentTown][i]);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));//메모제이션.
	cout << TSP(0, 1) << "\n";//시작점은 항상 0

	return 0;
}