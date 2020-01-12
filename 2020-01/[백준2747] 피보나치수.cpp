#include <iostream>
using namespace std;

const int MAX = 50;
int f[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= 45; i++)
		f[i] = f[i - 1] + f[i - 2];

	int n;
	cin >> n;
	cout << f[n];
	
	return 0;
}