#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool visit[10010];
vector<string> answer;
bool flag = false;

void dfs(vector<vector<string>> tickets, string cur, vector<string> temp)
{
	if (temp.size() == tickets.size())
	{
		temp.push_back(cur);
		flag = true;
		answer = temp;
		return;
	}

	for (int i = 0; i < tickets.size(); i++)
	{
		if (flag)    break;
		if (tickets[i][0] == cur && !visit[i])
		{
			visit[i] = true;
			temp.push_back(tickets[i][0]);
			dfs(tickets, tickets[i][1], temp);
			temp.pop_back();
			visit[i] = false;
		}
	}

}

vector<string> solution(vector<vector<string>> tickets) {

	sort(tickets.begin(), tickets.end());

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i][0] == "ICN")
		{
			visit[i] = true;
			answer.push_back(tickets[i][0]);
			dfs(tickets,tickets[i][1], answer);
            
            if (flag)    return answer;

            visit[i] = false;//초기화 하고 다시 경로 찾기
            answer.pop_back();
		}
	}

	return answer;
}