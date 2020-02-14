#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MAX = 500010;
pair<int, int> cable[MAX];
pair<int, int> p[MAX];//first는 LIS 인덱스, second는 A전봇대.
int dp[MAX];
bool check[MAX];
stack<int> st;
int n;

int Search(int start, int end, int target)
{
	while (start < end)
	{
		int mid = (start + end) / 2;
		if (dp[mid] < target)
			start = mid + 1;
		else
			end = mid;
	}
	return end + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> cable[i].first >> cable[i].second;
		check[cable[i].first] = true;
	}

	sort(cable + 1, cable + 1 + n);

	int dpIdx = 1;
	int idx = 2;
	dp[1] = cable[1].second;
	p[1].first = 1;
	p[1].second = cable[1].first;

	while (idx <= n)
	{
		if (dp[dpIdx] < cable[idx].second)
		{
			dpIdx++;
			dp[dpIdx] = cable[idx].second;
			p[idx].first = dpIdx;
			p[idx].second = cable[idx].first;
		}
		else
		{
			int val = Search(1, dpIdx, cable[idx].second);
			dp[val - 1] = cable[idx].second;
			p[idx].first = val-1;
			p[idx].second = cable[idx].first;
		}
		idx++;
	}

	cout << n - dpIdx << "\n";

	int ret = dpIdx;

	//for (int i = 1; i <= n; i++)
	//	cout << p[i].first << " " << p[i].second << "\n";

	for (int i = n; i >= 1; i--)
	{
		if (ret == p[i].first)
		{
			st.push(p[i].second);
			ret--;
		}
	}

	while (!st.empty())
	{
		check[st.top()] = false;
		st.pop();
	}

	for (int i = 1; i < MAX; i++)
	{
		if (check[i])
			cout << i << "\n";
	}
	
	return 0;
}