#include <string>
#include <vector>

using namespace std;

long long dp[90];

long long solution(int N) {
    long long answer = 0;
    
    dp[0]=0;
    dp[1]=1;
    
    for(int i=2; i<=80; i++)
        dp[i]=dp[i-1]+dp[i-2];
    
    long long w,h;
    if(N/2==0)
    {
        w=dp[N];
        h=dp[N-1]+dp[N];
    }
    else
    {
        w=dp[N]+dp[N-1];
        h=dp[N];
    }
    
    answer=(w+h)*2;
    
    return answer;
}