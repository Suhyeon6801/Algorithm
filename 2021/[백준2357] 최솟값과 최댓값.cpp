#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100010;
const int INF = 1e9;
int arr[MAX];
int minTree[MAX * 4];
int maxTree[MAX * 4];

void init(int start, int end, int node) {
	if (start == end) {
		minTree[node] = maxTree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	init(start, mid, node * 2);
	init(mid + 1, end, node * 2 + 1);
	minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
	maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
	return;
}

pair<int, int> find(int start, int end, int left, int right, int node) {
	if (left > end || right < start)	return make_pair(INF, 0);
	if (start <= left && right <= end) {
		return make_pair(minTree[node], maxTree[node]);
	}

	pair<int, int> l, r;
	l = find(start, end, left, (left + right) / 2, node * 2);
	r = find(start, end, (left + right) / 2 + 1, right, node * 2 + 1);
	return make_pair(min(l.first, r.first), max(l.second, r.second));
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, a, b;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	init(0, N - 1, 1);

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		pair<int, int> ans = find(a - 1, b - 1, 0, N - 1, 1);
		cout << ans.first << " " << ans.second << "\n";
	}

	return 0;
}