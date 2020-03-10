#include <iostream>
using namespace std;

const int MAX = 100000;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
    //4366632%1000==666인지? 아니면 /=10
	int cnt = 0;
	int i = 1;
	int temp;
	bool flag = false;
	while (1)
	{
		temp = i;
		flag = false;
		while (temp > 0)
		{
			if (temp % 1000 == 666)
				flag = true;

			temp /= 10;
		}
		i++;

		if (flag)
		{
			cnt++;
			if (cnt == N)
				break;
		}
	}

	cout << i -1 << "\n";

	return 0;
}