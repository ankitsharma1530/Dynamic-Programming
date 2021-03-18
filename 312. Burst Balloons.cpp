class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        //gap method 
        for(int gap=0;gap<n;gap++)
        {
            int i=0;
            for(int j=gap;j<n;j++)
            {
                int m = INT_MIN;
                for(int k=i;k<=j;k++)
                {
                    // int left = if(k==i) ? 0:dp[i][k-1];
                    int leftval = 1;
                    int rightval= 1;
                    if(i!=0)
                    {
                        leftval = nums[i-1];
                    }
                    if(j!=n-1)
                    {
                        rightval = nums[j+1];
                    }
                    
                    int before = 0;
                    int after = 0;
                    if(i!=k)
                    {
                        before = dp[i][k-1];
                    }
                    if(j!=k)
                    {
                        after = dp[k+1][j];
                    }
                    dp[i][j] = max(dp[i][j],before+after+(leftval*nums[k]*rightval));
                }
                i++;
            }
        }
        return dp[0][n-1];
        
    }
};
