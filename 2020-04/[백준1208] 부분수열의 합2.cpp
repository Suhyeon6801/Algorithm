#include <iostream>
#include <map>
using namespace std;

int arr[50];
int N, S;
long long cnt = 0;
map<int, int> mp;

void Left(int idx, int sum)
{
	if (idx == N / 2)
	{
		mp[sum]++;
		return;
	}

	Left(idx + 1, sum + arr[idx]);
	Left(idx + 1, sum);
}

void Right(int idx, int sum)
{
	if (idx == N)
	{
		cnt += mp[S - sum];
		return;
	}

	Right(idx + 1, sum + arr[idx]);
	Right(idx + 1, sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	Left(0, 0);
	Right(N / 2, 0);
	
	if (S == 0)	cnt--;

	cout << cnt << "\n";

	return 0;
}