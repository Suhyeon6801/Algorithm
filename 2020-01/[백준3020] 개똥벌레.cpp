#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, h;
	int t, b;
	cin >> n >> h;
	vector<int> top(n / 2, { 0 }), bottom(n / 2, { 0 });
	for (int i = 0; i < n / 2; i++)
		cin >> bottom[i] >> top[i];

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int result = 987654321;
	int cnt = 0;
	for (int i = 1; i <= h; i++)
	{
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		temp += (top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin()));

		if (result == temp)//똑같은 구간발견
			cnt++;

		if (result > temp)//작은 구간
		{
			result = temp;
			cnt = 1;
		}

	}
	cout << result << " " << cnt << "\n";

	return 0;
}