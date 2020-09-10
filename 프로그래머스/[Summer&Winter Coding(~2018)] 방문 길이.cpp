#include <string>
#include <iostream>
using namespace std;

bool visit[11][11][11][11];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int solution(string dirs) {
    int answer = 0;
    int y=5,x=5, ny,nx;
     
    for(int i=0; i<dirs.length(); i++)
    {
        if(dirs[i]=='U')
        {
            ny=y+dy[0], nx=x+dx[0];
        }
        else if(dirs[i]=='D')
        {
            ny=y+dy[1], nx=x+dx[1];
        }
        else if(dirs[i]=='R')
        {
            ny=y+dy[2], nx=x+dx[2];
        }
        else if(dirs[i]=='L')
        {
            ny=y+dy[3], nx=x+dx[3];
        }
        
        if(ny<0||nx<0||ny>10||nx>10)    continue;
        if(!visit[y][x][ny][nx])
        {
            visit[y][x][ny][nx]=true;
            visit[ny][nx][y][x]=true;          
            answer++;
        }
        
        y=ny, x=nx;
    }
    //answer=visit.size();
    
    return answer;
}