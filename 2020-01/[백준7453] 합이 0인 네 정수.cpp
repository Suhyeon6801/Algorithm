#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 4001;
int arr[MAX][4];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<long long int> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v.push_back(arr[i][0] + arr[j][1]);
		}
	}

	sort(v.begin(), v.end());

	long long int high, low, result = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			long long int val = arr[i][2] + arr[j][3];

			result += (upper_bound(v.begin(), v.end(), -val) - lower_bound(v.begin(), v.end(), -val));
		}
	}

	cout << result << "\n";

	return 0;

}