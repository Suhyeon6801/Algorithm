#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	int result = INF;
	
	for (int i = 0; i <= N / 3; i++)
	{
		for (int j = 0; j <= N / 5; j++)
		{
			if (3 * i + 5 * j == N)
				result = min(i + j, result);
			else if (3 * i + 5 * j > N)
				break;
		}
	}

	if (result == INF)
		cout << "-1\n";
	else
		cout << result << "\n";
	
	return 0;
}