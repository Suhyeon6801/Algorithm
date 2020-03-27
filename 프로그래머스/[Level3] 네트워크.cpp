#include <string>
#include <vector>
using namespace std;

bool visit[210];

void dfs(vector<vector<int>> temp, int cur, int n)
{
    visit[cur]=true;
    
    for(int i=0; i<n; i++)
    {
        int next=temp[cur][i];

        if(!visit[i]&&next==1)
            dfs(temp,i,n);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        if(!visit[i])
        {
            dfs(computers,i,n);
            answer++;
        }
    }
    
    return answer;
}