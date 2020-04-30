#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	int score;
	for (int i = 0; i < 5; i++)
	{
		cin >> score;

		if (score >= 40)
			sum += score;
		else
			sum += 40;
	}

	cout << sum / 5 << "\n";

	
	return 0;
}