class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>>dp(n,vector<int>(m));
        dp[0][0] = mat[0][0];
        for(int i=1;i<m;i++)
        {
            dp[0][i] = dp[0][i-1]+mat[0][i];
        }
        for(int i=1;i<n;i++)
        {
            dp[i][0] = dp[i-1][0]+mat[i][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j] = mat[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int x1 = i-k,y1 = j-k, x2 = i+k, y2 = j+k;
                if(x1 < 0) x1=0;
                if(y1 < 0) y1=0;
                if(x2>=n) x2 = n-1;
                if(y2>=m) y2 = m-1;
                
                if(x1!=0 && y1!=0){
                    ans[i][j] = dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1]; 
                }
                else if(x1 == 0 && y1 != 0){
                    ans[i][j] = dp[x2][y2] - dp[x2][y1-1];
                }
                else if(x1!=0 && y1 == 0){
                    ans[i][j] = dp[x2][y2] - dp[x1-1][y2];
                }
                else if(x1==0 && y1 ==0){
                    ans[i][j] = dp[x2][y2];
                }
                
            }
        }
        return ans;
    }
};
