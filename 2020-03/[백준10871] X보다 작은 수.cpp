#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, X, m;
	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> m;

		if (m < X)
			cout << m << " ";
	}

	return 0;
}[]