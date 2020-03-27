#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int R;
		string S;
		cin >> R >> S;

		for (int i = 0; i < S.length(); i++)
		{
			for (int j = 0; j < R; j++)
			{
				cout << S[i];
			}
		}
		cout << "\n";
	}
	return 0;
}