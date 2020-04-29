#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	vector<pair<string, int>> v(N);
	vector<string> dogam(N + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> dogam[i];
	}

	for (int i = 0; i < N; i++)
	{
		v[i].first = dogam[i+1];
		v[i].second = i+1;
	}

	sort(v.begin(), v.end());//이름 순으로 정렬하기.

	/*for (int i = 0; i < v.size(); i++)
		cout << v[i].first << " " << v[i].second << "\n";
*/
	string q;

	for (int i = 0; i < M; i++)
	{
		cin >> q;

		//cout << "정답 ";

		if (isdigit(q[0]))
		{		
			int temp = stoi(q);
			cout << dogam[temp] << "\n";
		}
		else
		{
			int start = 0;
			int end = N - 1;

			if (v[start].first == q)
			{
				cout << v[start].second << "\n";
			}
			else if (v[end].first == q)
			{
				cout << v[end].second << "\n";
			}
			else
			{
				while (start + 1 < end)
				{
					int mid = (start + end) / 2;
					if (v[mid].first < q)
						start = mid;
					else
						end = mid;
				}

				cout << v[end].second << "\n";
			}
		}
	}
	
	return 0;
}