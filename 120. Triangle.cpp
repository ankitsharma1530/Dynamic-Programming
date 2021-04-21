class Solution {
public:
    // int ans = 0;
    int dp[201][201];
    int solve(vector<vector<int>>& triangle, int k, int i, int n)
    {
        if(k>=n)
        {
            return 0;
        }
        if(dp[k][i]!=-1)
        {
            return dp[k][i];
        }
        int c = triangle[k][i];
        c+=min(solve(triangle,k+1,i,n),solve(triangle,k+1,i+1,n));
        dp[k][i] = c;
        return dp[k][i];
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        memset(dp,-1,sizeof(dp));
        return solve(triangle,0,0,n);
        
    }
};
