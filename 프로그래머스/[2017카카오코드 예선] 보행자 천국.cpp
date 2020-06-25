#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int MOD = 20170805;
int dp[501][501][2];
int dy[2] = { 0,1 };
int dx[2] = { 1,0 };

int f(int y, int x, int d, int M, int N, vector<vector<int>> &map)//map을 call by reference로 넘기기!! -> 시간초과 해결!
{
    if (y == M - 1 && x == N - 1)	return 1;
	int &ret = dp[y][x][d];
	if (ret != -1)	return ret;

	dp[y][x][d] = 0;

	for (int i = 0; i < 2; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= M || nx >= N)	continue;
        else
        {
            if (map[y][x] == 0 || (map[y][x] == 2 && i == d))
                dp[y][x][d] += f(ny, nx, i, M, N, map)%MOD;
        }
	}

	return dp[y][x][d]%MOD;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    memset(dp, -1, sizeof(dp));
	
	answer = f(0, 0, 0, m,n, city_map);
    
    return answer;
}