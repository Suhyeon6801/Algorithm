#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    //첨에 시간 초과 나서 next_permutation 함수 사용!!
    //순열 구해주는 함수, 입력 값의 다음 순열을 구해준다!!
	int N, num;

	cin >> N;

	vector<int> v(N);

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		v[i] = num;
	}

	if (next_permutation(v.begin(), v.end()))
	{
		for (int i = 0; i < N; i++)
			cout << v[i] << " ";
		cout << "\n";
	}
	else
		cout << "-1\n";


	return 0;
}