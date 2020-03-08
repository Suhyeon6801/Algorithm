#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 300000;
struct Jewel {
	int weight;
	int price;
};
Jewel jewel[MAX];
int bag[MAX];

bool comp(Jewel j1, Jewel j2)
{
	return j1.weight < j2.weight;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	priority_queue<int> pq;
	int n, k;
	int m, v, c;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> m >> v;
		jewel[i].weight = m;
		jewel[i].price = v;
	}

	for (int i = 0; i < k; i++)
	{
		cin >> c;
		bag[i] = c;
	}

	sort(jewel, jewel + n, comp);
	sort(bag, bag + k);

	long long sum = 0;
	int idx = 0;
	//무게제한이 낮은 가방부터 비싼 보석을 넣는다.
	for (int i = 0; i < k; i++)
	{
		//가방이 허용할 수 있는 보석까지 우선순위 큐에 넣는다.
		while (idx < n&& jewel[idx].weight <= bag[i])
		{
			pq.push(jewel[idx].price);
			idx++;
		}
		//우선순위큐 = maxHeap -> 보석 중 무게가 제일 큰 거가 top
		if (!pq.empty())
		{
			sum += pq.top();
			pq.pop();
		}
	}
	cout << sum << "\n";
	
	return 0;
}