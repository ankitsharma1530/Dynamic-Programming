class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[0] = 0; 
        dp[1] = 0; // we donot compare for minimum because we have two starting points
        for(int i=2;i<=n;i++)
        {
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};
