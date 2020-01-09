#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000010;
int arr[MAX];
int gcd1[MAX];
int gcd2[MAX];

int getGCD(int a, int b)
{
	int x = a;
	int y = b;
	int r, gcd;

	while (1)
	{
		r = x%y;
		if (r == 0)
		{
			gcd = y;
			break;
		}
		x = y;
		y = r;
	}
	return gcd;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	int result = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
	{
		gcd1[i] = getGCD(gcd1[i - 1], arr[i]);
		gcd2[n - i + 1] = getGCD(gcd2[n - i + 2], arr[n - i + 1]);
	}

	int getMax = gcd1[n];
	int idx =-1, idx2;
	//bool flag = false;
	for (int i = 1; i < n; i++)
	{
		int k = getGCD(gcd1[i - 1], gcd2[i + 1]);
		 
		if (k > getMax)
		{
			getMax = k;
			idx = k;
			idx2 = arr[i];
			//flag = true;
		}
	}
	if (idx==-1)
		cout << "-1\n";
	else
		cout << idx << " " << idx2 << "\n";


	return 0;
}