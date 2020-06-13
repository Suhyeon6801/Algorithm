#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

const int INF = 2000000001;
const int MAX = 100010;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int left = 0, right = 1;
	long long getMin = INF;
	while (left<N && right<N)
	{
		long long diff = abs(arr[right] - arr[left]);
		if (diff < M)
		{
			if(left<N)
				right++;
		}
		else
		{
			if (getMin > diff)
				getMin = diff;

			if(right<N)
				left++;
		}
	}

	cout << getMin << "\n";
	
	return 0;
}