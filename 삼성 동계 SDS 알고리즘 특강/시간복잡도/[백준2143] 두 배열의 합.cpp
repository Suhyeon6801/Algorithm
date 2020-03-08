#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long int a[1010];
long long int b[1010];
vector<long long int> va;
vector<long long int> vb;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long int t;
	int n, m;
	cin >> t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		cin >> b[j];
	}

	//1. a,b �迭�� �κ����� ���ؼ� ���Ϳ� ��´�.
	long long int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = 0;
		for (int j = i; j < n; j++)
		{
			sum += a[j];
			va.push_back(sum);
		}
	}

	for (int i = 0; i < m; i++)
	{
		sum = 0;
		for (int j = i; j < m; j++)
		{
			sum += b[j];
			vb.push_back(sum);
		}
	}

	//2. �����Ѵ�..
	sort(va.begin(), va.end());
	sort(vb.begin(), vb.end());

	//3.a�Ǻκ���+ b�� �κ��� = T�ΰ��
	long long int high, low, result = 0;
	for (int i = 0; i < va.size(); i++)
	{
		high = upper_bound(vb.begin(), vb.end(), t - va[i]) - vb.begin();// vb.begin()�� ���ִ� ������ �ּҰ�����
		low = lower_bound(vb.begin(), vb.end(), t - va[i]) - vb.begin();

		result += (high - low);
	}
	cout << result << "\n";

	return 0;
}