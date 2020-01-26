#include <iostream>
using namespace std;

int f[50][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	f[0][0] = 1;
	f[0][1] = 0;
	f[1][0] = 0;
	f[1][1] = 1;

	for (int i = 2; i < 50; i++)
	{
		f[i][0] = f[i - 1][0] + f[i - 2][0];
		f[i][1] = f[i - 1][1] + f[i - 2][1];
	}


	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		cout << f[N][0] << " " << f[N][1] << "\n";
	}
	

	return 0;
}