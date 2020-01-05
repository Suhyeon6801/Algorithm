#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	int cnt = 0;
	int use[110] = { 0, };// i번 구멍에 사용중인 기기번호
	int arr[110] = { 0, };//i순서로 사용할 기기번호
	cin >> n >> k;

	//사용순서 입력받기
	for (int i = 0; i < k; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++)
	{
		bool isUsed = false;

		//1.해당 기기가 구멍에 꽂혀있는지 확인한다.
		for (int j = 0; j < n; j++)
		{
			if (use[j] == arr[i])
			{
				isUsed = true;
				break;
			}
		}

		if (isUsed)	continue;

		//2.비어있는 구멍이 있는지 확인하고 
		for (int j = 0; j < n; j++)
		{
			if (!use[j])//비어있으면 꽂는다.
			{
				use[j] = arr[i];
				isUsed = true;
				break;
			}
		}

		if (isUsed)	continue;

		//3.비어 있지 않으면 현재 사용중인 기기 중 
		//앞으로 가장 나중에 사용할 가전기기를 뽑고 거기에 꽂는다.
		int idx = -1;
		int getIndex;
		for (int j = 0; j < n; j++)
		{
			int lastidx = 0;
			for (int t = i+1; t < k; t++)
			{
				if (use[j] == arr[t])	break;
				lastidx++;
			}

			if (lastidx > idx)
			{
				getIndex = j;
				idx = lastidx;
			}
		}
		cnt++;

		use[getIndex] = arr[i];
	}

	cout << cnt << "\n";
	return 0;
}