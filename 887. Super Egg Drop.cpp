class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>>dp(k+1,vector<int>(n+1));
        // k=number of eggs
        // n =number of floors
        for(int i=0;i<k+1;i++)
        {
            for(int j=0;j<n+1;j++)
            {
                // when there is no floor or no eggs
                if(i==0 || j==0)
                {
                    dp[i][j] = 0;
                }
                // if eggs are only ONE
                else if(i==1)
                {
                    dp[i][j] = j;
                }
                // if floor ONE
                else if(j==1)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    int mn = INT_MAX;
                    // fill in pattern wise
                    // int pj = 0
                    for(int mj=j-1, pj = 0;mj>=0;mj--,pj++)
                    {
                        // previous row j
                        
                        int val1 = dp[i][mj];  // egg survive
                        int val2 = dp[i-1][pj]; // egg break
                        int val = max(val1,val2);
                        mn = min(mn,val);
                        
                        // pj++;
                        
                    }
                    dp[i][j] = mn+1;
                }
            }
        }
        return dp[k][n];
    }
};
