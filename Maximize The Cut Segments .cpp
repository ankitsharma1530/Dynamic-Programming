int dp[10001];
int solve(int n,int x, int y, int z)
{
    if(n==0)
    {
        return 0;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int v1=INT_MIN,v2=INT_MIN,v3=INT_MIN;
    if(n>=x) v1 = solve(n-x,x,y,z);
    if(n>=y) v2 = solve(n-y,x,y,z);
    if(n>=z) v3 = solve(n-z,x,y,z);
    return dp[n] = 1+max({v1,v2,v3});
    
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    memset(dp,-1,sizeof(dp));
    int a = solve(n,x,y,z);
    if(a<0)
    {
        return 0;
    }
    return a;
}
