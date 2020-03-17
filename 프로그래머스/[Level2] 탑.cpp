#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    stack<pair<int,int>> st;//first->height, second->index
    
   for (int i = 0; i < heights.size(); i++)
	{	
		while (!st.empty())
		{
			if (st.top().first > heights[i])
			{
				answer.push_back(st.top().second);
				break;
			}
			else
			{
				st.pop();
			}
		}

		if (st.empty())
			answer.push_back(0);

		st.push(make_pair(heights[i], i + 1));
	}
    
    return answer;
}