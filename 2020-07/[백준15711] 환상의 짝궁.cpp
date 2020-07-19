#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
const int MAX = 2000001;
bool isPrime[MAX];
vector<int> p;

bool check(ll sum)
{
	for (int i = 0; i<p.size(); i++)
	{
		if (p[i] * p[i] > sum)	break;
	
		if (sum%p[i] == 0)	return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	isPrime[1] = true;
	for (int i = 2; i*i <MAX; i++)
	{
		for (int j = i * i; j < MAX; j += i)
			isPrime[j] = true;
	}

	for (int i = 2; i < MAX; i++)
	{
		if (!isPrime[i])	p.push_back(i);
	}

	int T;
	ll A, B;
	cin >> T;

	while (T--)
	{
		cin >> A >> B;

		ll sum = A + B;
		if (sum < 4)	cout << "NO\n";
		else if (sum % 2 == 0)	cout << "YES\n";//골드바흐의 추측 : 2보다 큰 모든 짝수는 두개의 소수의 합으로 표시 가능
		else
		{
			sum -= 2;
			if (check(sum))	cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
	
	return 0;
}