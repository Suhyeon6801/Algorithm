#include <iostream>
#include <algorithm>
using namespace std;

int arr[10] = { 0, };
int arr2[10] = { 0, };
bool visit[10] = { 0, };
int cnt = 0;

bool check(int a[])
{
	int sum = 0;

	for (int i = 0; i < 9; i++)
	{
		sum += a[i];
	}

	if (sum == 100)	return true;
	else	return false;
}

void f(int len)
{
	if (cnt >= 1)	return;
	if (len == 7)
	{
		if (check(arr2))
		{
			cnt++;
			sort(arr2, arr2 + 7);
			for (int i = 0; i < 7; i++)
			{
				cout << arr2[i] << "\n";
			}
			cout << endl;
		}
		return;
	}

	for (int i = 0; i < 9; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			arr2[len] = arr[i];
			f(len + 1);
			visit[i] = false;
			arr2[len] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	f(0);

	return 0;
}