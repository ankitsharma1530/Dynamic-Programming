class Solution {
public:
    // Time complexity -> O(n^2)
    // O(n) -> for n number of calls as n=5 can be called for 1+1+1+1+1 (i.e 5)
    // O(n) -> n calls total
    int dp[59];
    int solve(int n){
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int m = 0;
        for(int i=1;i<n;i++){
            // at every step we have two choices
            // 1. either dump our solution right here -> i*(n-i)
            // 2. or call recursively further i*(solve(n-i))
            m = max({m,i*(n-i),i*solve(n-i)});
        }
        return dp[n] = m;
    }
    int integerBreak(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};
