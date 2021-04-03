class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(k==0 || prices.size()<2)
        {
            return 0;
        }
        int n = prices.size(); 
        // table to store results of subproblems dp[k][i] stores maximum
        // profit using atmost k transactions up to day i (including day i)
        vector<vector<int>>dp(k+1,vector<int>(n+1));
        // profit is 0 if we don't do any transation (i.e. k =0)
        for(int i=0;i<=n;i++)
        {
            dp[0][i] = 0;
        }
        // For day 0, you can't earn money irrespective of how many times you trade
        for(int i=0;i<=k;i++)
        {
            dp[i][0] = 0;
        }
        // bottom up
        for(int i=1;i<=k;i++)
        {
            int pre = INT_MIN;
            for(int j=1;j<n;j++)
            {
                pre = max(pre,dp[i-1][j-1]-prices[j-1]);
                dp[i][j] = max(dp[i][j-1],prices[j]+pre);
            }
        }
        return dp[k][n-1];
    }
};
