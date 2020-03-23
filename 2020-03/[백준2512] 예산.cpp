#include <iostream>
using namespace std;

int arr[10010];
int N;
int M;

bool check(int x)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < x)
			sum += arr[i];
		else
			sum += x;
	}

	if (sum <= M)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int getMax = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];

		if (getMax < arr[i])
			getMax = arr[i];
	}

	cin >> M;

	int start = 0;
	int end = getMax;

	if (check(end))
	{
		cout << end << "\n";
		return 0;
	}
	
	while (start + 1 < end)
	{
		int mid = (start + end) / 2;

		if (!check(mid))
			end = mid;
		else
			start = mid;
	}

	cout << start << "\n";


	return 0;
}