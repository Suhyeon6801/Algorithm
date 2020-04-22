#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int MAX = 110;
int r, c, k;
int arr[MAX][MAX];
int R_cnt = 3;
int C_cnt = 3;

bool check()
{
	for (int i = 0; i < R_cnt; i++)
	{
		for (int j = 0; j < C_cnt; j++)
		{
			if (arr[r - 1][c - 1] == k)
				return true;
		}
	}

	return false;
}

bool comp(int a, int b)
{
	return a > b;
}

void Oper()
{
	vector<int> len;
	if (R_cnt >= C_cnt)//길이가 같거나 세로가 더 긴 경우
	{
		for (int i = 0; i < R_cnt; i++)
		{
			vector<pair<int, int>> v;
			map<int, int> mp;
			for (int j = 0; j < C_cnt; j++)
			{
				if (arr[i][j] != 0)
				{
					mp[arr[i][j]]++;
				}
			}

			for (auto it = mp.begin(); it != mp.end(); it++)
				v.push_back({ it->second, it->first });
			
			sort(v.begin(), v.end());

			for (int j = 0; j < C_cnt; j++)//이전꺼 비워주고
				arr[i][j] = 0;

			int idx = 0;
			int size = v.size();
			if (size >= 50)//first, second니까 50개가 max
				size = 50;
			for (int j = 0; j < size; j++)
			{
				arr[i][idx++] = v[j].second;
				arr[i][idx++] = v[j].first;
			}

			len.push_back(idx);
		}
		sort(len.begin(), len.end(), comp);
		C_cnt = len[0];//열길이 바꿔주기
	}
	else//가로가 더 긴 경우
	{
		for (int j = 0; j < C_cnt; j++)
		{
			vector<pair<int, int>> v;
			map<int, int> mp;

			for (int i = 0; i < R_cnt; i++)
			{
				if(arr[i][j]!=0)
					mp[arr[i][j]]++;
			}

			for (auto it = mp.begin(); it != mp.end(); it++)
				v.push_back({ it->second, it->first });

			sort(v.begin(), v.end());

			for (int i = 0; i < R_cnt; i++)
				arr[i][j] = 0;

			int idx = 0;
			int size = v.size();
			if (size >= 50)
				size = 50;
			for (int i = 0; i < size; i++)
			{
				arr[idx++][j] = v[i].second;
				arr[idx++][j] = v[i].first;
			}

			len.push_back(idx);
		}
		sort(len.begin(), len.end(), comp);
		R_cnt = len[0];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];

	int time = 0;
	while (1)
	{
		if (check())
		{
			cout << time << "\n";
			break;
		}

		if (time > 100)
		{
			cout << "-1\n";
			break;
		}

		Oper();
		time++;
	}

	return 0;
}