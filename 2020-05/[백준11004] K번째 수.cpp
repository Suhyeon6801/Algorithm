#include <iostream>
#include <algorithm>
using namespace std;

int arr[5000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;
	K--;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	nth_element(arr, arr+K,arr + N);//부분적으로 정렬.
	cout << arr[K];

	return 0;
}