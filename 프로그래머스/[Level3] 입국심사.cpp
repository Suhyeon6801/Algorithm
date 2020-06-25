#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check(long long x, int n, vector<int> times)
{
    long long sum=0;
    for(int i=0; i<times.size(); i++)
    {
        sum+=(x/times[i]);
    }
    
    if(sum>=n)  return true;
    else
        return false;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long int start=1, end=-1, mid;
    
    for(int i=0; i<times.size(); i++)
    {
        if(times[i]>end)      
            end=times[i];
    }
    
    end*=n;
    
    while(start+1<end)
    {
        mid=(start+end)/2;
        if(check(mid, n,times))
            end=mid;
        else
            start=mid;
    }
    
    answer=end;
    return answer;
}