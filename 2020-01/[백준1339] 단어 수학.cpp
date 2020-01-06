#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

bool comp(int a, int b)
{
	return a > b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	string s;
	vector<string> v;
	bool check[26] = { 0, };
	int arr[26] = { 0, }; 

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(s);

		int k = 1;
		for (int j = s.length()-1; j >=0; j--)
		{
			int index = s[j] - 'A';

			arr[index] +=  k;
			k = k * 10;
		}
	}

	sort(arr, arr + 26, comp);

	int sum = 0;
	int i = 0;
	int number = 9;
	while (1)
	{
		if (arr[i] == 0)	break;

		sum += arr[i] * number;
		number--;
		i++;
	}

	cout << sum << "\n";
	return 0;
}