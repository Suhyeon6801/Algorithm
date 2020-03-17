#include <string>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < scoville.size(); i++)
	{
		pq.push(scoville[i]);
	}

	bool flag = true;
	while (1)
	{
		if (pq.empty()) 
		{
			flag = false;
			break;
		}
		if (pq.top() < K)
		{
			int temp1 = pq.top();
			pq.pop();
            if(pq.empty())
            {
                flag=false;
                break;
            }
			int temp2 = pq.top();
			pq.pop();

			pq.push(temp1 + temp2 * 2);
			answer++;
		}
		else
			break;
	}
    
    if(!flag)   answer=-1;
    
    return answer;
}