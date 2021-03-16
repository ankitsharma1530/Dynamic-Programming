class Solution {
public:
    int dp[101][101];
    int solve(vector<int>& values,int i, int j)
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
            int temp = values[i-1]*values[k]*values[j]+solve(values,i,k)+solve(values,k+1,j);
            mn = min(temp,mn);
        }
        dp[i][j] = mn;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof(dp));
        int N = values.size();
        return solve(values,1,N-1);
    }
};
