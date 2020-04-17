#include <iostream>
using namespace std;

const int MAX = 1000010;
int N, B, C;
int arr[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> B >> C;

	long long int cnt = N;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] - B == 1)
		{
			cnt += 1;
		}
		else if (arr[i] - B > 1)
		{
			int temp = (arr[i] - B);
			cnt += temp / C;

			if (temp%C != 0)
				cnt += 1;
		}
	}

	cout << cnt << "\n";
	
	return 0;
}