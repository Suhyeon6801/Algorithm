#include <iostream>
using namespace std;

char arr[110];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int sum = 0;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		sum += arr[i] - '0';
	}

	cout << sum << "\n";
	
	return 0;
}