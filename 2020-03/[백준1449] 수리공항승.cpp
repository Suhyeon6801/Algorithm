#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];
int check[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;
	cin >> N >> L;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	int cnt = 0;
	int p1 = 0, p2 = 0;
	while (p1 < N&&p2 < N)
	{
		if (arr[p2] - arr[p1] <= L - 1)
		{
			p2++;
		}
		else
		{
			cnt++;
			p1 = p2;
		}

	}

	cout << cnt + 1 << "\n";

	return 0;
}