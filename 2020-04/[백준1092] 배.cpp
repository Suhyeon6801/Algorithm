#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

int N, M;
int crain[60];
int box[10010];

bool check()
{
	for (int i = 0; i < M; i++)
	{
		if (box[i] != 0)
			return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> crain[i];
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> box[i];
	}

	sort(crain, crain + N, greater<int>());
	sort(box, box + M, greater<int>());

	if (crain[0]<box[0])
	{
		cout << "-1\n";
	}
	else
	{
		int i = 0, j = 0;
		int sec = 0;
		while (1)
		{
			if (check())
				break;

			i = 0;
			for (j = 0; j < M; j++)
			{
				if (i == N)	break;

				if (box[j] != 0)
				{
					if (crain[i] >= box[j])
					{
						i++;
						box[j] = 0;
						j = j - 1;
					}
				}
			}
			sec++;
		}

		cout << sec << "\n";
	}

	return 0;
}