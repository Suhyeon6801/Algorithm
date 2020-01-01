#include <iostream>
#include <algorithm>
using namespace std;

struct Medal
{
	int country;
	int gold;
	int silver;
	int bronze;
	int grade;
};

int n, k;//n=국가 수, k=등수를 알고 싶은 국가

bool comp(Medal m1, Medal m2)
{
	if (m1.gold > m2.gold)
	{
		return true;
	}
	else if (m1.gold == m2.gold)
	{
		if (m1.silver > m2.silver)
		{
			return true;
		}
		else if (m1.silver == m2.silver)
		{
			if (m1.bronze > m2.bronze)
			{
				return true;
			}
			else if (m1.bronze == m2.bronze)
				return m1.country == k;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	Medal medal[1010] = { 0 };
	
	int gold, silver, bronze, country;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> country >> gold >> silver >> bronze;

		medal[i].country = country;
		medal[i].gold = gold;
		medal[i].silver = silver;
		medal[i].bronze = bronze;
	}

	//금메달을 기준으로 내림차순 정렬
	sort(medal, medal + n, comp);

	for (int i = 0; i < n; i++)
	{
		if (medal[i].country == k)
		{
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}
