#include <string>
#include <vector>
#include <queue>
using namespace std;

const int MAX=20010;
vector<int> v[MAX];
bool visited[MAX];
int dist[MAX];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0, getMax=-1;
    queue<int> que;
    
    for(int i=0; i<edge.size(); i++)
    {
        int from = edge[i][0];
        int to = edge[i][1];
        v[from].push_back(to);
        v[to].push_back(from);
    }
    
    que.push(1);
    visited[1]=true;
    dist[1]=0;
    
    while(!que.empty())
    {      
        int cur=que.front();
        que.pop();

        for(int i=0; i<v[cur].size(); i++)
        {
            int next=v[cur][i];
            if(!visited[next])
            {
                visited[next]=true;
                dist[next]=dist[cur]+1;
                que.push(next);
            }
        }
    }
    
    for(int i=1; i<=n; i++)
    {
        if(getMax<dist[i])  getMax=dist[i];
    }
    
    for(int i=1; i<=n; i++)
    {
        if(getMax==dist[i]) answer++;
    }
    
    return answer;
}