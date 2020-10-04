#include <iostream>
using namespace std;

const int MAX = 1010;
int pre[MAX];
int arr[MAX];
int N;

void solve(int left, int right, int idx)
{
	if (left > right)	return;

	int temp = arr[pre[idx]];
	solve(left, temp-1, idx + 1);//왼쪽 서브트리
	solve(temp + 1, right, idx + temp - left + 1);//오른쪽 서브트리
	cout << pre[idx] << " ";
}


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> pre[i];

		int in;
		for (int i = 0; i < N; i++)
		{
			cin >> in;
			arr[in] = i;
		}

		solve(0, N - 1, 0);
		cout << "\n";
	}

	return 0;
}