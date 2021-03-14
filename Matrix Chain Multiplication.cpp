class Solution{
public:
    int dp[101][101];
    int solve(int arr[],int i, int j)
    {
        //base condn
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn = INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp = arr[i-1]*arr[k]*arr[j]+solve(arr,i,k)+solve(arr,k+1,j);
            mn = min(temp,mn);
        }
        dp[i][j] = mn;
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(arr,1,N-1);
        
    }
};
