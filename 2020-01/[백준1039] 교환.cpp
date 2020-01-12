#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 1000010;
int dp[MAX][11];
int k;

int dfs(string str, int x)
{
	int num = stoi(str);

	if (x == 0)	return	 num;
	if (dp[num][x] != 0)	return dp[num][x];

	int result = -1;
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i+1; j < str.length(); j++)
		{
			if (i == 0 && str[j] == '0')//앞자리가 0인 경우
				continue;

			swap(str[i], str[j]);
			result = max(result, dfs(str, x - 1));
			swap(str[j], str[i]);//초기화
		}
	}

	return dp[num][x] = result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string number;
	cin >> number >> k;

	cout<<dfs(number, k);
	
	return 0;
}