class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        int res = 0;
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(A[i-1]==B[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                    res = max(res,dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }
};
