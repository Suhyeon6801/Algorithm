class Solution {
    public static int MOD = 1000000007;
    public static int[][] dp = new int[110][110];
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        for(int i=1; i<=n; i++)
            dp[i][1]=1;
        
        for(int i=1; i<=m; i++)
            dp[1][i]=1;
        
        for(int i=0; i<puddles.length; i++)
            dp[puddles[i][1]][puddles[i][0]] = -1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
            {
                if(i==1 && j==1)   continue;
                
                if(dp[i][j]==-1)    dp[i][j]=0;
                else
                {
                    dp[i][j]=(dp[i][j-1]+dp[i-1][j])%MOD;
                }
            }
        }
        
        answer=dp[n][m]%MOD;
        
        return answer;
    }
}