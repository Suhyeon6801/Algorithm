#include <iostream>
#include <algorithm>
#include <stack>//���� ����������
using namespace std;

const int MAX = 1000001;
long long int arr[MAX];
pair<int, long long> p[MAX];//LIS�� �� �� �ִ� ��ġ, �� �� �ش��ϴ� ��.
long long int dp[MAX];//i��° ���� ������ LIS

int isSearch(int start, int end, long long target)
{
	int mid;
	while (start < end)
	{
		mid = (start + end) / 2;
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
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	int dpIdx = 1;
	int idx = 2;//arr�� index
	dp[1] = arr[1];
	p[1].first = 1;
	p[1].second = arr[1];

	while (idx <= n)
	{
		if (dp[dpIdx] < arr[idx])
		{
			dpIdx++;
			dp[dpIdx] = arr[idx];
			p[idx].first = dpIdx;
			p[idx].second = arr[idx];
		}
		else
		{
			int val = isSearch(1, dpIdx, arr[idx]);//index��
			dp[val - 1] = arr[idx];

			p[idx].first = val - 1;
			p[idx].second = arr[idx];
		}
		idx++;
	}

	/*for (int i = 1; i <= dpIdx; i++)
	{
	cout << dp[i] << " ";
	}
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
	cout << p[i].first << " " << p[i].second << endl;
	}*/
	cout << dpIdx << "\n";

	int temp = dpIdx;
	stack<long long> st;

	for (int i = n; i >= 1; i--)
	{
		if (p[i].first == temp)
		{
			st.push(p[i].second);
			temp--;
		}
	}

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << "\n";

	return 0;
}