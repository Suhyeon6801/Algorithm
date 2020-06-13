#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MIN_INF = -987654321;
const int MAX = 1501;
int arr[MAX][MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
    int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}

	vector<int> v;

	while (1)
	{
		int getMax = MIN_INF;
		int idx = 0;
		for (int i = 0; i < N; i++)
		{
			if (arr[N - 1][i] > getMax)
			{
				getMax = arr[N - 1][i];
				idx = i;
			}
		}

		v.push_back(getMax);

		for (int i = N - 1; i >= 1; i--)
		{
			arr[i][idx] = arr[i - 1][idx];
		}
		arr[0][idx] = 0;

		if (v.size() == N)
		{
			cout << v[N - 1] << "\n";
			break;
		}
	}

	return 0;
}