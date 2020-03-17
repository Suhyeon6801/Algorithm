#include <iostream>
using namespace std;

int N, S;
int arr[30];
int cnt = 0;

void f(int sum, int start)
{
	if (start >= N)	return;

	if (sum+arr[start] == S)
	{
		cnt++;
	}

	f(sum + arr[start], start + 1);

	f(sum, start + 1);

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	f(0, 0);
	cout << cnt << "\n";

	return 0;
}