#include <iostream>
#include <string>
#include <algorithm>//reverse, swap
using namespace std;

string f[10010];

string sum(string s1, string s2)//큰수의 덧셈
{
	string result = "";
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int len1 = s1.length();
	int len2 = s2.length();
	
	if (len1 < len2)
		swap(s1, s2);

	int sum = 0;
	int carry = 0;

	for (int i = 0; i < len1; i++)
	{
		if (i < len2)
		{
			sum = s1[i] - '0' + s2[i] - '0' + carry;
			carry = sum / 10;
			sum %= 10;
			result+=sum + '0';
		}
		else
		{
			sum = s1[i] - '0' + carry;
			carry = sum / 10;
			sum %= 10;
			result += sum + '0';
		}
	}
	result+=carry + '0';
	

	reverse(result.begin(), result.end());

	int idx = 0;
	for (int i = 0; i < result.length(); i++)
	{
		if (result[i] != '0')
		{
			idx = i;
			break;
		}
	}

	string temp = "";
	for (int i = idx; i < result.length(); i++)
		temp += result[i];

	return temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	f[0] = "0";
	f[1] = "1";

	for (int i = 2; i <= 10000; i++)
	{
		f[i] = sum(f[i - 1], f[i - 2]);
	}

	cout << f[n] << "\n";

	return 0;
}