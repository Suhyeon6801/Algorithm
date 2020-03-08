#include <iostream>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	set <int> nodes;
	int u, v, cnt, k = 1;
	bool finish = false;

	while (1) 
	{
		nodes.clear();
		cnt = 0;
		while (1) 
		{
			cin >> u >> v;
			if (u == 0 && v == 0)
				break;
			if (u < 0 && v < 0) 
			{
				finish = true;
				break;
			}
			nodes.insert(v);
			nodes.insert(u);
			cnt++;
		}
		if (finish)
			break;
		if (cnt == 0 || cnt == (int)nodes.size() - 1)
			printf("Case %d is a tree.\n", k);
		else
			printf("Case %d is not a tree.\n", k);
		k++;
	}

	return 0;;
}