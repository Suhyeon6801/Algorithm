#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 50;

int n, k, result;
string word[MAX];
bool check[26];


void f(int alpha, int cnt)
{
	if (cnt == k)
	{
		int temp = 0;

		for (int i = 0; i < n; i++)
		{
			bool flag = true;
			for (int j = 0; j < word[i].length(); j++)
			{
				if (!check[word[i][j] - 'a'])
				{
					flag = false;
					break;
				}
			}
			if (flag)	temp++;

		}
		result = max(result, temp);
		return;
	}

	for (int c = alpha; c < 26; c++)
	{
		if (!check[c])
		{
			check[c] = true;
			f(c, cnt + 1);
			check[c] = false;
		}

	}

}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if (k < 5)
	{
		cout << 0 << "\n";
	}
	else if (k == 26)
	{
		cout << n << "\n";
	}
	else
	{

		k -= 5;
		string s;
		for (int i = 0; i < n; i++)

		{

			cin >> s;

			for (int j = 4; j < s.length() - 4; j++)
			{
				word[i] += s[j];
			}

		}

		check[0] = true;
		check[2] = true;
		check[8] = true;
		check[13] = true;
		check[19] = true;

		f(0, 0);

		cout << result << "\n";
	}

	return 0;

}