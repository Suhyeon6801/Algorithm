#include <iostream>
#include <cmath>
using namespace std;

int n;
int arr[10] = { 0, };
bool check[200] = { 0, };
int arr2[10] = { 0, };
int getMax = -1;

int calc(int a[])
{
	int sum = 0;
	for (int i = 0; i <n-1; i++)
	{
		sum += abs(a[i] - a[i + 1]);
	}
	return sum;
}

void f(int len)
{
	if (len == n)
	{
		if (calc(arr2) > getMax)	getMax = calc(arr2);
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!check[i])
		{
			arr2[len] = arr[i];
			check[i] = true;
			f(len + 1);
			arr2[len] = 0;
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	f(0);

	cout << getMax << "\n";

	return 0;
}