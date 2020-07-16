//뭔가 어려워..ㅠㅠ https://jaimemin.tistory.com/1110 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int wantSize, M, N;//M=A, N=B
	cin >> wantSize;
	cin >> M >> N;

	vector<int> a(M);
	vector<int> b(N);
	vector<int> v(1, 0);
	vector<int> v2(1, 0);

	for (int i = 0; i < M; i++)
		cin >> a[i];

	for (int i = 0; i < N; i++)
		cin >> b[i];

	//모든 가능한 합을 구한다.
	int left = 0, right = 0, sum = 0;
	while (left<a.size())
	{
		sum += a[right++];

		if (sum <= wantSize)
			v.push_back(sum);
		else
		{
			left++;
			right = left;
			sum = 0;
		}

		if (right == a.size())	right = 0;

		if ((!left&& !right) || right + 1 == left)
		{
			left++;
			right = left;
			sum = 0;
		}
	}

	left = 0, right = 0, sum = 0;
	while (left < b.size())
	{
		sum += b[right++];

		if (sum <= wantSize)
			v2.push_back(sum);
		else
		{
			left++;
			right = left;
			sum = 0;
		}

		if (right == b.size())	right = 0;

		if ((!left && !right) || right + 1 == left)
		{
			left++;
			right = left;
			sum = 0;
		}
	}

	sort(v.begin(), v.end());
	sort(v2.begin(), v2.end());

	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		int low = lower_bound(v2.begin(), v2.end(), wantSize - v[i]) - v2.begin();
		int high = upper_bound(v2.begin(), v2.end(), wantSize - v[i]) - v2.begin();

		cnt += (high - low);
	}

	cout << cnt << "\n";


	return 0;
}