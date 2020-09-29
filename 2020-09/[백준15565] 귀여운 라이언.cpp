#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000100;
int arr[1000100];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K, getMin = MAX;
	int lion = 0;
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] == 1)	lion++;
	}

	if (lion == K)	cout << N << "\n";
	else if (lion == 0 || lion<K)	cout << "-1\n";
	else if (lion == 1)	cout << "1\n";
	else
	{
		int left = 0, right = 0, cnt = 0;
		while (right <= left)
		{
			if (cnt < K)
			{
				if (left < N)
				{
					if (arr[left++] == 1)	cnt++;
				}
				else
				{
					if (arr[right++] == 1)	cnt--;
				}
			}
			else if (cnt >= K)
			{
				if (cnt == K)
				{
					getMin = min(left - right, getMin);
				}
				
				if (arr[right++] == 1)	cnt--;
			}

			if (right > N)	break;
		}

		cout << getMin << "\n";
	}

	return 0;
}