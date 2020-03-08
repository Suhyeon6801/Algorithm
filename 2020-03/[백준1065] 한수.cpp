#include <iostream>
#include <cstring>
using namespace std;

int arr[1010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	int cnt = 0;
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		memset(arr, 0, sizeof(arr));
		int temp = i;
		int idx = 0;
		while (temp > 0)
		{
			arr[idx++] = temp % 10;
			temp /= 10;
		}

		bool isRight = true;
		int gap = arr[1] - arr[0];
		for (int j = 2; j < idx; j++)
		{
			if (arr[j] - arr[j - 1] != gap)
			{
				isRight = false;
				break;
			}
		}

		if (isRight)	cnt++;
	}

	cout << cnt << "\n";

	return 0;
}