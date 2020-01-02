#include <iostream>
#include <cstring>
using namespace std;

char op[10];
int arr[10];
bool check[10] = { 0, };
int k;
int cnt1 = 0, cnt2 = 0;

bool comp(int a, int b, char c)
{
	if (c == '>')	return a > b;
	else if (c == '<')	return a < b;
}

bool isPossible()
{
	for (int i = 0; i < k; i++)
	{
		if (!comp(arr[i], arr[i + 1], op[i]))	return false;
	}
	return true;
}

void f1(int len)
{
	if (cnt1 > 0)	return;
	if (len == k + 1)
	{
		if (!isPossible())	return;

		for (int i = 0; i < k + 1; i++)
		{
			cout << arr[i];
		}
		cout << "\n";
		cnt1++;
		return;
	}


	for (int i = 9; i >= 0; i--)
	{
		if (!check[i])
		{
			arr[len] = i;
			check[i] = true;
			f1(len + 1);
			arr[len] = 0;
			check[i] = false;
		}
	}
}

void f2(int len)
{
	if (cnt2 > 0)	return;
	if (len == k + 1)
	{
		if (!isPossible())	return;

		for (int i = 0; i < k + 1; i++)
		{
			cout << arr[i];
		}
		cout << "\n";
		cnt2++;
		return;
	}

	for (int i = 0; i <= 9; i++)
	{
		if (!check[i])
		{
			arr[len] = i;
			check[i] = true;
			f2(len + 1);
			arr[len] = 0;
			check[i] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> op[i];
	}

	f1(0);
	memset(arr, 0, sizeof(arr));
	memset(check, 0, sizeof(check));
	f2(0);

	return 0;
}