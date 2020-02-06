#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 200010;
long long int house[MAX];
int N, C;

bool check(int len)
{
	int cnt = 1;
	int s = house[0];
	for (int i = 1; i < N; i++)
	{
		if (house[i] - s >= len)
		{
			cnt++;
			s = house[i];
		}
	}

	//cout << len << " " << cnt << "\n";

	if (cnt >= C)	return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> house[i];
	}

	sort(house, house + N);
	long long int start = 1;
	long long int end = house[N - 1];
	long long int mid;

	while (start + 1 < end)
	{
		mid = (start + end) / 2;
		if (!check(mid))	end = mid;
		else
			start = mid;
	}

	cout << start;
	
	return 0;
}