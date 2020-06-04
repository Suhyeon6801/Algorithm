#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int INF = 987654321;
const int MAX = 2500 + 1;
int dp[MAX][MAX];//i-j까지 팰린드롬이면 1 아니면 0
int dp_cnt[MAX];//i번째에서 팰린드롬 분할 최소개수

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s, str;
	cin >> s;
	str = " " + s;//길이가 1부터 시작해야함, 겁나 헷갈려....

	int len = str.length() - 1;//전체 길이 + 1, 앞에는 공백이니까

	//길이 1 -> 무조건 팰린드롬.
	for (int i = 1; i <= len; i++)
		dp[i][i] = 1;

	//길이 2
	for (int i = 1; i <= len - 1; i++)
	{
		if (str[i] == str[i + 1])
			dp[i][i + 1] = 1;
	}

	//길이 3이상
	for (int idx = 2; idx <= len; idx++)
	{
		for (int i = 1; i <= len-idx; i++)
		{
			int j = i + idx;

			//시작+1, 끝-1이 팰린드롬이고 시작=끝이 같으면 1
			if (dp[i + 1][j - 1] == 1 && str[i] == str[j])
				dp[i][j] = 1;
		}
	}

	dp_cnt[0] = 0;//1번째 인덱스 부터 시작~
	for (int i = 1; i <= len; i++)
	{
		dp_cnt[i] = INF;

		for (int j = 1; j <= i; j++)
		{
			if (dp[j][i] == 1)
			{
				dp_cnt[i] = min(dp_cnt[i], dp_cnt[j - 1] + 1);
			}
		}
	}

	cout << dp_cnt[len] << "\n";
	
	return 0;
}