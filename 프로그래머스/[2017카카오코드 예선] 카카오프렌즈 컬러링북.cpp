#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

bool visit[110][110];
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

bool comp(int a, int b)
{
    return a>b;
}

int dfs(int y, int x, int cur, int num, int m, int n, vector<vector<int>> picture)
{
    visit[y][x]=true;
    int ret=1;
    
    for(int i=0; i<4; i++)
    {
        int ny=y+dy[i];
        int nx=x+dx[i];
        
        if(ny<0||nx<0||ny>=m||nx>=n)    continue;
        if(picture[ny][nx]==cur && !visit[ny][nx])
            ret+=dfs(ny,nx,cur,num,m,n,picture);
    }
    
    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요. --> visit초기화 해줘야....
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    memset(visit,0,sizeof(visit));
    
    vector<int> v;
    
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(picture[i][j]!=0 && !visit[i][j])
            {
                int temp = dfs(i,j,picture[i][j],number_of_area++, m,n, picture);
               // cout<<picture[i][j]<<" "<<temp<<"\n";
                v.push_back(temp);
            }
        }
    }
    
    sort(v.begin(), v.end(), comp);
    
    max_size_of_one_area = v[0];
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}