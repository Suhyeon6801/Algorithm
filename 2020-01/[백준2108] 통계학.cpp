#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

map<int, int> mt;
vector<pair<int, int>> v;//벡터로 치환
int arr[500010];
int getMax = -4010, getMin = 500010;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second)
		return p1.first < p2.first;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, mid;
	double sum = 0.0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		mt[arr[i]]++;
		sum += arr[i];
		getMax = max(arr[i], getMax);
		getMin = min(arr[i], getMin);
	}

	//산술평균
	double ret = sum / (double)n;
	//cout << "산술평균 : ";
	cout << floor(ret + 0.5) << "\n";

	//중앙값
	//cout << "중앙값 : ";
	sort(arr, arr + n);
	mid = (n-1) / 2;
	cout << arr[mid] << "\n";

	//최빈값
	for (auto it = mt.begin(); it != mt.end(); it++)//벡터로 복사
	{
		v.emplace_back(make_pair(it->first, it->second));
	}
	//cout << "최빈값 : ";
	sort(v.begin(), v.end(), comp);//빈도값(value) 으로 정렬

	//for (int i = 0; i < v.size(); i++)
	//{
	//	cout << v[i].first << " " << v[i].second << "\n";
	//}

	if (v.size() == 1)	cout << v[0].first << "\n";
	else
	{
		if (v[0].second == v[1].second)
			cout << v[1].first << "\n";
		else
			cout << v[0].first << "\n";
	}

	//범위
	//cout << "범위 : ";
	cout << getMax - getMin << "\n";

	return 0;
}