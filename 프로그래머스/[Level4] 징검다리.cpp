#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool check(int x, vector<int> rocks, int distance, int n)
{
    int cnt=0;
    int gap;
    int idx=0;
    
    for(int i=0; i<rocks.size(); i++)
    {
        if(i!=rocks.size())
            gap=rocks[i]-idx;
        else//도착지점이랑 그 전 바위
            gap=distance-idx;
        
        if(gap<x)
            cnt++;
        else
            idx=rocks[i];
    }
    
    if(cnt > n)  return true;
    else
        return false;
}

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int start=1;
    int end=distance;
    
    while(start+1<end)
    {
        int mid=(start+end)/2;
        if(check(mid, rocks,distance, n))
            end=mid;
        else
            start=mid;
    }
    
    answer=start;
    
    return answer;
}