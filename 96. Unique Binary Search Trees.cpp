class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0] =1;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {
            int x = 0;
            int y = i-1;
            dp[i]=0;
            while(x<=i-1)
            {
                dp[i]+=(dp[x]*dp[y])%1000000007;
                x++;
                y--;
            }
        }
        return dp[n];
    }
};
