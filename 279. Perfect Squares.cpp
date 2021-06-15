class Solution {
public:
    // time complexity -> O(n^2);
    int dp[10001];
    int solve(int n){
        if(n<=0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int ans = INT_MAX;
        for(int j=1;j*j<=n;j++){
            int temp = j*j;
            ans = min(ans,1+solve(n-temp));
        }
        return dp[n] = ans;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
