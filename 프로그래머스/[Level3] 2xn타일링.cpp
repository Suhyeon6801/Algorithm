#include <string>
#include <vector>

using namespace std;

const int MOD=1000000007;
const int MAX=60010;
int dp[MAX];

int solution(int n) {
    int answer = 0;
    
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++)
        dp[i]=(dp[i-1]+dp[i-2])%MOD;
    
    answer=dp[n]%MOD;
    
    return answer;
}