#include <iostream>
using namespace std;

double score[1010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	double N, M = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> score[i];

		if (score[i] > M)	M = score[i];
	}

	double sum = 0.0;
	for (int i = 0; i < N; i++)
	{
		score[i] = (score[i] / M) * 100;
		sum += score[i];
	}
	cout << (double)sum / N;

	return 0;
}