#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

long long INF = 300000000000;
long long arr[100010];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int left = 0, right = N - 1, idx1 = 0, idx2 = 0;
	long long sum = 0, minSol = INF;

	while (left < right)
	{
		sum = arr[left] + arr[right];

		if (llabs(sum) < minSol)
		{
			minSol = llabs(sum);
			idx1 = left;
			idx2 = right;
		}
		
		if (sum < 0)	left++;
		else	right--;
	}

	cout << arr[idx1] << " " << arr[idx2] << "\n";
	
	return 0;
}