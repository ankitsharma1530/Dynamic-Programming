class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>dp(n,vector<int>(n,1));
        
        for(auto x:mines){
            int i = x[0];
            int y = x[1];
            dp[i][y] = 0;
        }
        
        // chossing 4 matrix to solve this question
        // as for the plus we need all of the 4 directions data
        int dp1[n][n]; // from left
        int dp2[n][n]; // from right
        int dp3[n][n]; // from top
        int dp4[n][n]; // from bottom
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp1[i][j] = dp[i][j];
                }
                else{
                if(dp[i][j]==0){
                    dp1[i][j] = 0;
                }
                else{
                    dp1[i][j] = 1+dp1[i][j-1];
                }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(j==n-1){
                    dp2[i][j] = dp[i][j];
                }
                else{
                if(dp[i][j]==0){
                    dp2[i][j] = 0;
                }
                else{
                dp2[i][j] = 1+dp2[i][j+1];
                }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    dp3[j][i] = dp[j][i];
                }
                else{
                if(dp[j][i]==0){
                    dp3[j][i] = 0;
                    // continue;
                }
                else{
                dp3[j][i] = 1+dp3[j-1][i];
                }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=0;j--){
                if(j==n-1){
                    dp4[j][i] = dp[j][i];
                }
                else{
                    if(dp[j][i]==0){
                        dp4[j][i] = 0;
                    }
                    else{
                        dp4[j][i] = 1+dp4[j+1][i];
                    }
                }
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int ans = min({dp3[i][j],dp1[i][j],dp2[i][j],dp4[i][j]});
                res = max(res,ans);
                
            }
        }
        return res;
    }
};
