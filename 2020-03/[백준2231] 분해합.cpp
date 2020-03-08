#include <iostream>
using namespace std;

int N;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	bool flag = false;
	int result;
	for (int i = 1; i <= N; i++)
	{
		int sum = 0;
		sum += i;
		int temp = i;
		while (temp > 0)
		{
			sum += temp % 10;
			temp /= 10;
		}

		if (sum == N)
		{
			flag = true;
			result = i;
			break;
		}
	}

	if (flag)	cout << result << "\n";
	else
		cout << "0\n";


	return 0;
}