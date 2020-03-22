#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int testcase;
	cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++)
	{
		int N, M;
		int a, b;
		cin >> N >> M;

		for (int i = 0; i < M; i++)
			cin >> a >> b;

		//모든 노드를 방문 할 수 있는 간선의 최소 개수 -> MST 에서는 항상 N-1!!
		cout << N - 1 << "\n";
	}


	return 0;
}