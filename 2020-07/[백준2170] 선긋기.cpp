//라인스위핑 : 수평선의 왼쪽부터 훑다가 마주치는 선분이 있으면 뭔가 처리를 해준다.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;
vector<pair<int, int>> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, p1, p2;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> p1 >> p2;
		p.push_back({ p1,p2 });
	}

	sort(p.begin(), p.end());//왼쪽 점을 오름차순으로 정렬

	//[l,r] : 현재 합치고 있는 구간
	int l = -INF, r = -INF, result = 0;

	for (int i = 0; i < N; i++)
	{
		if (r < p[i].first)//현재 구간과 이번 선분이 합쳐질 수 없다.
		{
			result += (r - l);
			l = p[i].first;
			r = p[i].second;
		}
		else
			r = max(r, p[i].second);
	}

	result += (r - l);

	cout << result << "\n";
	
	return 0;
}