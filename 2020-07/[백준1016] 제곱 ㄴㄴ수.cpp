#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;
const int MAX = 1000010;
bool check[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	ll min, max;
	cin >> min >> max;

	for (ll i = 2; i <= sqrt(max); i++)
	{
		ll temp = min / (i*i);
		if (temp*i*i != min)	temp++;
		for (ll j = temp; i*i*j <= max; j++)
			check[i*i*j-min] = true;
	}

	ll cnt = 0;
	for (ll i = 0; i <= max - min; i++)
	{
		if (!check[i]) cnt++;
	}
	cout << cnt << "\n";

	return 0;
}