#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
const int INF = 1e9;
int N;
string str;
bool check[30];//괄호 체크
ll getMax = -INF;

ll calc(ll a, ll b, string op)
{
	if (op == "+")	return a + b;
	else if (op == "-")	return a - b;
	else if (op == "*")	return a * b;
}

ll func()//계산순서 : 괄호->곱하기->더하기,나누기(왼쪽부터 순서대로)
{
	vector<string> v;
	string s = "";
	int i = 0;

	while(i<N)
	{
		if (!check[i])
		{
			s = "";
			s = str[i];
			v.push_back(s);
			i++;
		}
		else
		{
			ll a = str[i] - '0';
			ll b = str[i + 2] - '0';

			s = "";
			s += str[i + 1];

			ll temp = calc(a, b, s);
			v.push_back(to_string(temp));
			i += 3;
		}
	}

	vector<string> v2;
	i = 0;
    
	while(i<v.size())
	{
		if (v[i] == "*")
		{
			ll a = stoll(v2[v2.size() - 1]);
			ll b = stoll(v[i + 1]);
			ll temp = calc(a, b, v[i]);
			v2.pop_back();
			v2.push_back(to_string(temp));
			i += 2;
		}
		else
		{
			v2.push_back(v[i++]);
		}
	}

	ll ret = stoll(v2[0]);
	for (int i = 1; i < v2.size(); i+=2)
	{
		if (v2[i] == "+")	ret += stoll(v2[i + 1]);
		else if (v2[i] == "-")	ret -= stoll(v2[i + 1]);
	}

	return ret;
}

void dfs(int idx)
{
	if (idx >= N)
	{
		getMax = max(func(), getMax);
		return;
	}

	for (int i = idx; i < N; i += 2)
	{
		if (i + 2 < N)
		{
			if (!check[i] && !check[i + 2])
			{
				check[i] = true;
				check[i + 2] = true;
				dfs(i + 2);
				check[i + 2] = false;
				check[i] = false;
			}

		}
		else
			dfs(i+1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	cin >> str;

	dfs(0);

	cout << getMax << "\n";

	return 0;
}