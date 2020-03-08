#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int arr[10];
int result[10];
bool visit[10];
int n, m;
set<string> s;

bool isDup()
{
	string str = "";

	for (int i = 0; i < m; i++)
	{
		char c = result[i] + '0';
		str += c;
	}

	if (s.find(str) != s.end())	
		return false;
	
	s.insert(str);
	return true;
}

void f(int x)
{
	if (x == m)
	{
		if (!isDup())	return;
		
		for (int i = 0; i < x; i++)
		{
			cout << result[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			result[x] = arr[i];
			f(x + 1);
			visit[i] = false;
			result[x] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	f(0);

	return 0;
}