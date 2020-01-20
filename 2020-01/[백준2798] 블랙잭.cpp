#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[110];
int result[110];
int ret = 0;
bool check[110];

void f(int len, int sum)
{
	if (sum > m)	return;
	if (len == 3)
	{
		ret = max(ret, sum);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			check[i] = true;
			//result[len] = arr[i];
			f(len + 1, sum + arr[i]);
			//result[len] = 0;
			check[i] = false;
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
	f(0,0);
	cout << ret << "\n";
	return 0;
}