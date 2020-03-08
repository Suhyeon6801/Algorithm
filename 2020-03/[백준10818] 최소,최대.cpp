#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int getMin = 1000001;
	int getMax = -1000001;
	int N, M;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> M;
		if (M > getMax)	getMax = M;
		if (M < getMin)	getMin = M;
	}
	cout << getMin << " " << getMax << "\n";

	return 0;
}