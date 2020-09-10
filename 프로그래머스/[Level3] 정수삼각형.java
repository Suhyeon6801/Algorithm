import java.util.*;

class Solution {
    public static int[][] dp = new int[510][510];
    
    public int getMax(int a, int b){
        if(a>b) return a;
        else return b;
    }
    
    public int solution(int[][] triangle) {
        int answer = 0;
        int n=triangle.length;
        
        dp[0][0]=triangle[0][0];
        for(int i=1; i<n; i++)
        {
            dp[i][0]=dp[i-1][0]+triangle[i][0];
            dp[i][i]=dp[i-1][i-1]+triangle[i][i];
        }
        
        for(int i=2; i<n; i++)
        {
            for(int j=1; j<i; j++)
            {
                dp[i][j] = getMax(dp[i-1][j-1], dp[i-1][j])+triangle[i][j];
            }
        }
        
        for(int i=0; i<n; i++)
        {
            answer=getMax(dp[n-1][i],answer);
        }
        
        return answer;
    }
}