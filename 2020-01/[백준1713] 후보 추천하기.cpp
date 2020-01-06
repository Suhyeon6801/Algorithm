#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> v(30, { 0,0 });//시간,사진틀번호->초기화
	int recommand[110] = { 0, };
	int n, total, rec;

	cin >> n >> total;

	for (int i = 0; i < total; i++)
	{
		cin >> rec;

		recommand[rec]++;
		bool isChange = true;
		for (int j = 0; j < n; j++)
		{
			if (v[j].second == 0)//비어있다.
			{
				v[j].first = i;
				v[j].second = rec;
				isChange = false;
				break;
			}
			else if (v[j].second == rec)//이미 있는 추천
			{
				isChange = false;
				break;
			}
		}

		if (isChange)//갱신하는 경우
		{
			int index = 0;
			for (int j = 1; j < n; j++)
			{
				//추천수가 같으면 -> 시간 순 오래된거(작은거)
				if (recommand[v[j].second] == recommand[v[index].second])
				{
					if (v[j].first < v[index].first)
						index = j;
				}
				else if (recommand[v[j].second] < recommand[v[index].second])
				{
					//추천수 작은 거
					index = j;
				}
			}

			//바꿀 index 초기화
			recommand[v[index].second] = 0;
			//새로 갱신
			v[index].first = i;
			v[index].second = rec;
		}
	}

	vector<int> result;

	for (int i = 0; i < n; i++)
	{
		result.push_back(v[i].second);
	}

	sort(result.begin(), result.end());

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << " ";
	}
	cout << "\n";

	
	return 0;

}