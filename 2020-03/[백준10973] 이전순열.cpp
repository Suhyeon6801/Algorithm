#include <iostream>
#include <algorithm>
using namespace std;

int arr[10010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, num;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	if (prev_permutation(arr, arr + N))
	{
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << "\n";
	}
	else
		cout << "-1\n";


	return 0;
}