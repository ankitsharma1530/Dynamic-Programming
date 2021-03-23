class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n));
        //gap method
        for(int gap=0;gap<n;gap++)
        {
            int i=0;
            for(int j=gap;j<n;j++)
            {
                if(gap==0)
                {
                    dp[i][j] = nums[i];
                }
                else if(gap==1)
                {
                    dp[i][j] = max(nums[i],nums[j]);
                }
                else
                {
                    int val1 = nums[i]+min(dp[i+2][j],dp[i+1][j-1]);
                    int val2 = nums[j]+min(dp[i+1][j-1],dp[i][j-2]);
                    dp[i][j] = max(val1,val2);
                }
                i++;
            }
        }
        int sum =accumulate(nums.begin(),nums.end(),0);
        int num = dp[0][n-1];
        if(num>=sum-num)
            return true;
        return false;
    }
};
