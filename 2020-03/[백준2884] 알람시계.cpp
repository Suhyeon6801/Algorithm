#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int H, M;
	cin >> H >> M;

	if (M < 45)
	{
		if (H - 1 < 0)
			cout << H - 1 + 24 << " " << M + 15 << "\n";
		else
			cout << H - 1 << " " << M + 15 << "\n";
	}
	else
	{
		cout << H << " " << M - 45 << "\n";
	}
	
	return 0;
}