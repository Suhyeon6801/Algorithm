#include <iostream>
using namespace std;

const int MAX = 110;
int dp[MAX][MAX][4];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int w, h;
	cin >> w >> h;

	//0,2->커브함
	//1,3->커브 안함
	for (int i = 1; i <= h; i++)//세로
		dp[i][1][1] = 1;
	for (int i = 1; i <= w; i++)//가로
		dp[1][i][3] = 1;

	for (int i = 2; i <= h; i++)
	{
		for (int j = 2; j <= w; j++)
		{
			dp[i][j][0] = dp[i - 1][j][3];//최근에 온 가로일 경우 세로로 꺽임
			dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % 100000;//최근에 세로로 온 모든 경로이면 그래도 세로로 진행
			dp[i][j][2] = dp[i][j-1][1];
			dp[i][j][3] = (dp[i][j-1][2] + dp[i][j-1][3]) % 100000;
		}
	}

	cout << (dp[h][w][0] + dp[h][w][1] + dp[h][w][2] + dp[h][w][3])% 100000 << "\n";
	
	return 0;
}