#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 1010;
int dp[MAX][MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2;
	string str1, str2;
	cin >> s1 >> s2;

	str1 = '0' + s1;
	str2 = '0' + s2;

	for (int i = 0; i < str1.length(); i++)
	{
		dp[0][i] = 0;
	}

	for (int i = 0; i < str2.length(); i++)
	{
		dp[i][0] = 0;
	}

	for (int i = 1; i < str2.length(); i++)
	{
		for (int j = 1; j < str1.length(); j++)
		{
			if (str1[j] == str2[i])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	cout << dp[str2.length()-1][str1.length()-1] << "\n";

	stack<int> st;
	int idx1 = str1.length() - 1;
	int idx2 = str2.length() - 1;

	while (dp[idx2][idx1] != 0)
	{
		if (dp[idx2][idx1] == dp[idx2][idx1 - 1])
			idx1--;
		else if (dp[idx2][idx1] == dp[idx2 - 1][idx1])
			idx2--;
		else if (dp[idx2][idx1] - 1 == dp[idx2 - 1][idx1 - 1])
		{
			st.push(idx1);
			idx1--;
			idx2--;
		}
	}

	while (!st.empty())
	{
		cout << str1[st.top()];
		st.pop();
	}
	return 0;
}