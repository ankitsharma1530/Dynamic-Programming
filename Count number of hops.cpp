class Solution{
    public:
    // function to count number of ways to reach top of the stair
    long long countWays(int n)
{
    long long dp[n+1];
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int i = 4; i <= n; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3])%1000000007;
    }
    
    return dp[n];
}
      //Recursive solution
      // long long countWays(int n){
      // if(n == 0 || n == 1)
      // return 1;
      // if(n == 2)
      // return 2;
      // if(n == 3)
      // return 3;
      // return (countWays(n-1)+countWays(n-2)+countWays(n-3))+1;
      // }
};
