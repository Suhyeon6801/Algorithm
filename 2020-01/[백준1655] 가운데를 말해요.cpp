#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//heap 사용
	//top에 가장 큰 값이 저장되는  maxheap, 가장 작은 값이 저장 되는 minheap
	//minheap의 크기+1 <= maxheap 로 유지
	//maxHeap의 모든 원소는 minHeap의 모든 원소보다 작거나 같다.->  maxHeap의 top이 minHeap의 top 보다 작거나 같음.
	//maxHeap의 top이 가운데 값


	priority_queue<int, vector<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

	int n, m;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> m;

		if (maxHeap.size() > minHeap.size())	minHeap.push(m);
		else	maxHeap.push(m);

		if (!maxHeap.empty()&&!minHeap.empty()&&(maxHeap.top() > minHeap.top()))
		{
			int a = maxHeap.top();
			int b = minHeap.top();

			maxHeap.pop();
			minHeap.pop();

			maxHeap.push(b);
			minHeap.push(a);
		}
		//cout << "답 : ";
		cout << maxHeap.top() << "\n";
	}
	
	return 0;;
}