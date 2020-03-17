#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> card;
int arr[500010];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	int check;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		card[arr[i]]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> check;

		if (binary_search(arr,arr+N, check))
		{
			cout << card.find(check)->second << " ";
		}
		else
			cout << "0 ";
	}


	return 0;
}