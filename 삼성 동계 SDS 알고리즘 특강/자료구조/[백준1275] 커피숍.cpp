#include <iostream>
using namespace std;

const int MAX = 100010;
long long int arr[MAX] = { 0, };
long long int tree[MAX * 4] = { 0, };

long long int init(long long int start, long long int end, long long int node)
{
	if (start == end)	return tree[node] = arr[start];

	long long int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long int sum(long long int start, long long int end, long long int node, long long int left, long long int right)
{
	if (left>end || right<start)	return 0;
	if (left <= start&&right >= end)	return tree[node];

	long long int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(long long int start, long long int end, long long int node, long long int index, long long int val)
{
	if (index<start || index>end)	return;

	tree[node] += val;

	if (start == end)	return;

	long long int mid = (start + end) / 2;
	update(start, mid, node * 2, index, val);
	update(mid + 1, end, node * 2 + 1, index, val);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, q;
	long long int x, y, a, b;
	cin >> n >> q;

	for (long long int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	init(1, n, 1);

	for (long long int i = 0; i < q; i++)
	{
		cin >> x >> y >> a >> b;

		if (x > y)
		{
			cout << sum(1, n, 1, y, x) << "\n";
		}
		else
		{
			cout << sum(1, n, 1, x, y) << "\n";
		}
		long long int val = b - arr[a];
		arr[a] = b;
		update(1, n, 1, a, val);
	}
	return 0;;
}