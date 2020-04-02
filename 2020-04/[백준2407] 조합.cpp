#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string dp[110][110];

string getSum(string s1, string s2)
{
	string temp = "";

	if (s1.length() < s2.length())
		swap(s1, s2);

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int sum = 0, carry = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (i < s2.length())
		{
			sum = (s1[i] - '0' + s2[i] - '0' + carry) % 10;
			temp += sum + '0';
			carry=(s1[i] - '0' + s2[i] - '0' + carry) / 10;
		}
		else
		{
			sum = (s1[i] - '0' + carry) % 10;
			temp += sum + '0';
			carry = (s1[i] - '0' + carry) / 10;
		}
	}
	temp += carry + '0';

	reverse(temp.begin(), temp.end());

	int idx = 0;
	for (int i = 0; i < temp.length(); i++)
	{
		if (temp[i] != '0')
		{
			idx = i;
			break;
		}
	}

	return temp.substr(idx, temp.size());
}

string comb(int x, int y)//dp 메모제이션
{
	if (x == y || y == 0)
		return "1";
	else
	{
		string &ret = dp[x][y];
		if (ret != "")
			return ret;

		ret = getSum(comb(x - 1, y - 1), comb(x - 1, y));
		return ret;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	//cout << getSum("7", "3") << "\n";

	cout<< comb(n, m);//숫자 long long벗어나니까 string으로 구해야함.
	
	return 0;
}