#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 4010;
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int getMax = -1;
	string s1, s2;
	cin >> s1 >> s2;

	string str1 = "0" + s1;
	string str2 = "0" + s2;

	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 0; i < len1; i++)
		dp[0][i] = 0;
	for (int i = 0; i < len2; i++)
		dp[i][0] = 0;

	for (int i = 1; i < len2; i++)
	{
		for (int j = 1; j < len1; j++)
		{
			if (str1[j] == str2[i])
				dp[i][j] = dp[i - 1][j - 1] + 1;

			getMax = max(getMax, dp[i][j]);
		}
	}

	cout << getMax << "\n";

	return 0;
}