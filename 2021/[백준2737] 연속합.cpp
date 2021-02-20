#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		int k = 1;
		int cnt = 0;

		N -= k;
		while (N > 0) {
			k++;
			N -= k;

			if (N%k == 0) {
				cnt++;
			}
		}

		cout << cnt << "\n";
	}

	return 0;
}