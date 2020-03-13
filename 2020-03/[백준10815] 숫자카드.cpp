#include <iostream>
#include <algorithm>
using namespace std;

int arr[500010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, num;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> num;

		if (binary_search(arr,arr+N, num))
			cout << "1 ";
		else
			cout << "0 ";
	}
	return 0;
}