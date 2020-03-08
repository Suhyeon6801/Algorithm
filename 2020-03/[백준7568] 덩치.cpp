#include <iostream>
using namespace std;

const int MAX = 60;
struct Info {
	int height, weight;
};

Info info[MAX];
int _rank[MAX];

bool comp(Info i1, Info i2)
{
	if (i1.weight > i2.weight&&i1.height > i2.height)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> info[i].weight >> info[i].height;

	for (int i = 0; i < N; i++)//초기화
		_rank[i] = 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i != j)
			{
				if (comp(info[i], info[j]))
					_rank[j]++;
			}
		}
	}
	
	for (int i = 0; i < N; i++)
		cout << _rank[i] << " ";

	return 0;
}