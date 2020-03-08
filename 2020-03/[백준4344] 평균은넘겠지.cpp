#include <iostream>
#include <cstring>
using namespace std;

double arr[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C;
	cin >> C;
	for (int tc = 1; tc <= C; tc++)
	{
		memset(arr, 0, sizeof(arr));
		int N;
		int cnt = 0;
		double score;
		double sum = 0.0, average;
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			cin >> arr[i];
			sum += arr[i];
		}

		average = sum / N;

		for (int i = 0; i < N; i++)
		{
			if (arr[i] > average)
				cnt++;
		}

		cout << fixed;
		cout.precision(3);
		cout << (double)cnt / N *100<< "%\n";

	}
	
	return 0;
}