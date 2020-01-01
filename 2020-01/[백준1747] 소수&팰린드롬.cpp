#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1004000;
int num[MAX] = { 0, };

bool isPalindrome(int prime)
{
	int arr[10] = { 0, };
	int arr2[10] = { 0, };
	int idx2 = 0;
	int k = 0;
	int x = prime;

	while (x > 0)
	{
		arr[idx2++] = x % 10;
		x /= 10;
	}

	int idx = idx2;
	x = prime;
	while (x > 0)
	{
		arr2[k] = x / (pow(10, idx - 1));
		x = x - arr2[k] * pow(10, idx - 1);
		k++;
		idx--;
	}

	for (int j = 0; j < idx2; j++)
	{
		if (arr[j] != arr2[j])	return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//에라토스테네스
	num[1] = 1;
	for (int i = 2; i <= sqrt(MAX); i++)
	{
		for (int j = i * i; j < MAX; j += i)
		{
			num[j] = 1;
		}
	}
	
	int n;
	cin >> n;

	for (int i = n; i <MAX; i++)
	{
		if (num[i] == 0)
		{
			if (isPalindrome(i))
			{
				cout << i << "\n";
				return 0;
			}
		}
	}

	return 0;

}