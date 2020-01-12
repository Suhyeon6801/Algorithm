#include <iostream>
#include <string>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string num;
	cin >> n;
	for (int tc = 0; tc < n; tc++)
	{
		cin >> num;

		string s1 = "";
		string s2 = "";
		int k = 0;
		int l = 0;
		bool flag = false;
		num.erase(0, 2);//앞에 두개는 지워버림.

		for (int i = 0; i < num.length(); i++)
		{
			if (flag&&num[i] != ')')	k++;//순환소수임.
			else if (num[i] == '(')	flag=true;//순환소수 표기
			else if (num[i] != ')'&&num[i] != '(')	l++;
		}

		//앞뒤 괄호 지워버리기
		for (int i = 0; i < num.length(); i++)
		{
			if (num[i] == '(')
			{
				num.pop_back();//뒤에')'지워 버림
				num.erase(num.begin() + i);//앞에 '('지워버림.
				break;
			}
		}

		long long x = 0, y = 0, g;

		if (k == 0)//순환소수가 아닐때
		{
			x = stoll(num);
			y = pow(10, l);
			g = gcd(x, y);
			cout << x / g << "/" << y / g << "\n";
		}
		else
		{
			string str= "";
			//분모 만들기
			for (int i = 0; i < k; i++)	
				str += "9";
			for (int i = 0; i < l; i++)
				str += "0";

			//분자만들기
			if (l == 0)
				x = stoll(num);
			else
			{
				x = stoll(num) - stoll(num.substr(0, l));
			}

			y = stoll(str);
			//cout << x << " " << y << endl;
			g = gcd(x, y);
			//cout << g << endl;
			cout << x / g << "/" << y / g << "\n";
		}
	}

	
	return 0;
}