#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

int n, m;
int arr[10];
int result[10];
set<string> st;

bool isDup()
{
	string str = "";

	for (int i = 0; i < m; i++)
	{
		char c = result[i] + '0';
		str += c;
		str += " ";
	}

	if (st.find(str) != st.end())
		return false;

	st.insert(str);
	return true;
}

void f(int x, int start)
{
	if (x == m)
	{
		if (!isDup())	return;

		for (int i = 0; i < x; i++)
			cout << result[i] << " ";
		cout << "\n";
		return;
	}

	for (int i = start; i < n; i++)
	{
		result[x] = arr[i];
		f(x + 1, i);
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
	f(0,0);

	return 0;
}