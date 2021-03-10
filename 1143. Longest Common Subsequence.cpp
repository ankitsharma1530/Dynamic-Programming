class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
        
    }
};
// int solve(string text1, string text2, int n, int m, vector<vector<int>>& dp)
    // {
    //     if(n==0 || m==0)
    //     {
    //         return 0;
    //     }
    //     if(dp[n][m] !=-1)
    //     {
    //         return dp[n][m];
    //     }
    //     if(text1[n-1]==text2[m-1])
    //     {
    //         dp[n][m] = 1+solve(text1,text2,n-1,m-1,dp);
    //         return dp[n][m];
    //     }
    //     else
    //     {
    //         dp[n][m] = max(solve(text1,text2,n-1,m,dp), solve(text1,text2,n,m-1,dp));
    //         return dp[n][m];
    //     }
    // }
