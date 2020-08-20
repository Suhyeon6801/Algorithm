#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, h;
	stack<pair<int, int>> st;//높이, idx

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> h;

		while (!st.empty())
		{
			if (st.top().first > h)
			{
				cout << st.top().second << " ";
				break;
			}
			else
				st.pop();
		}

		if (st.empty())
			cout << "0 ";

		st.push({ h,i });
	}

	return 0;
}