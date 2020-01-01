#include <iostream>
using namespace std;

const int MAX = 1000010;
long long int arr[MAX] = { 0 };
long long int tree[4 * MAX] = { 0 };

long long int init(long long int start, long long int end, long long int node)
{
	if (start == end)	return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	return tree[node]=init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

void update(long long int start, long long int end, long long int node, long long int index, long long int val)
{
	if (index<start || end<index)	return;
	
	tree[node] += val;

	if (start == end)	return;

	long long int mid = (start + end) / 2;
	update(start, mid, node * 2, index, val);
	update(mid + 1, end, node * 2 + 1, index, val);
}

long long int sum(long long int start, long long int end, long long int node, long long int left, long long int right)
{
	if (left > end || right < start)	return 0;

	if (left <= start && end <= right)	return tree[node];

	long long int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

int main()
{
	long long int n, m, k, a, b, c;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init(1, n, 1);

	for (int i = 0; i < m + k; i++)
	{
		cin >> a >> b >> c;

		if (a == 1)
		{
			long long int val = c - arr[b];
			arr[b] = c;
			update(1, n, 1, b, val);
		}

		if (a == 2)
		{
			cout << sum(1, n, 1, b, c) << "\n";
		}
	}

	return 0;
}