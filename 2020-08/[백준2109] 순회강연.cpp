#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 10010;
pair<int, int> lec[MAX];
bool visited[MAX];

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	return p1.first > p2.first;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, d, p;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p >> d;
		lec[i].first = p, lec[i].second = d;
	}

	sort(lec, lec + N, comp);

	int result = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = lec[i].second; j >= 1; j--)
		{
			if (!visited[j])
			{
				result += lec[i].first;
				visited[j] = true;
				break;
			}
		}
	}

	cout << result << "\n";

	return 0;
}