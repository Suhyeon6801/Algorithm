#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Test {
	int time, score;
};
Test test[110];
int dp[110][10010];//n단원, t시간까지 공부했을 때 얻는 최대 점수
int N, T;

int solve(int chapter, int time)
{
	if (chapter == N)
		return 0;

	int& ret = dp[chapter][time];
	if (ret != -1)	return ret;

	if (test[chapter].time <= time)
	{
		ret = test[chapter].score + solve(chapter + 1, time - test[chapter].time);
	}

	ret = max(ret, solve(chapter + 1, time));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T;
	for (int i = 0; i < N; i++)
		cin >> test[i].time >> test[i].score;

	memset(dp, -1, sizeof(dp));

	cout << solve(0, T);
	
	return 0;
}