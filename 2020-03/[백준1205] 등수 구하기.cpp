#include <iostream>
#include <algorithm>
using namespace std;

int arr[60];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, score, P;
	int rank = 1;
	int check = 1;
	cin >> N >> score >> P;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];

		if (arr[i] > score)	rank++;
		if (arr[i] >= score)	check++;
	}

	if (rank > P)	cout << "-1\n";
	else if (check > P)	cout << "-1\n";
	else
		cout << rank << "\n";
	
	return 0;
}