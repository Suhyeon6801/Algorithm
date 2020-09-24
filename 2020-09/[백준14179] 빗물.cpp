#include <iostream>
#include <algorithm>
using namespace std;

int arr[510];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int H, W, sum = 0, left, right;
	cin >> H >> W;

	for (int i = 0; i < W; i++)
		cin >> arr[i];

	for (int i = 1; i < W-1; i++)
	{
		left = arr[i], right = arr[i];

		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		for (int j = i + 1; j < W; j++)
			right = max(right, arr[j]);

		sum += (min(left, right) - arr[i]);
	}

	cout << sum << "\n";

	return 0;
}