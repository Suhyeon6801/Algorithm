#include <iostream>
using namespace std;

int money2017[101] = { 0,5000000,3000000,3000000,2000000,2000000,2000000,500000,500000,500000,500000,
300000,300000,300000,300000,300000,100000,100000,100000,100000,100000,100000 };
int money2018[65] = { 0,5120000,2560000,2560000,1280000,1280000,1280000,1280000,640000,640000,640000,640000,640000,640000,640000,640000
,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000,320000 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int a, b, result;
		cin >> a >> b;

		result = money2017[a] + money2018[b];
		cout << result << "\n";
	}

	return 0;
}