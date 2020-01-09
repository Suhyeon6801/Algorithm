#include <iostream>
#include <deque>
using namespace std;

const int MAX = 5000001;
int arr[MAX];

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	deque <pair<int,int>> dq;//숫자, index -> 오름차순으로되게 항상

	for (int i = 0; i < n; i++)
	{
		//dp는 L이하개만 담겨 있어야함.
		if (!dq.empty() && dq.front().second <= i - l)
		{
			dq.pop_front();
		}

		//arr[i]보다 작은거 다 뺌
		while (!dq.empty() && dq.back().first > arr[i])
		{
			dq.pop_back();
		}

		dq.push_back(make_pair(arr[i], i));
		cout << dq.front().first << " ";
	}
	cout << "\n";

	return 0;

}