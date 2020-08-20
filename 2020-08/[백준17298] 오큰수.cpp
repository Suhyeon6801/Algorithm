#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX = 1000010;
int result[MAX];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, a;
	stack<pair<int, int>> st;//원소, idx

	cin >> N;

	memset(result, -1, sizeof(result));

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		
		while (!st.empty())
		{
			if (st.top().first < a)
			{
				int idx = st.top().second;
				result[idx] = a;
				st.pop();
			}
			else
				break;
		}

		st.push({ a,i });
	}

	for (int i = 0; i < N; i++)
		cout << result[i] << " ";
	
	return 0;
}