class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                // base condn of our LIS
                if(dp[i]<dp[j]+1 && nums[i]>nums[j])
                {
                    dp[i] = dp[j]+1;
                    count[i] = count[j];
                }
                else if(dp[i]==dp[j]+1)
                {
                    count[i]=count[i]+count[j];
                }
            }
        }
        int res = 0;
        int m = *max_element(dp.begin(),dp.end());
        for(int i=0;i<n;i++)
        {
            if(dp[i]==m)
            {
                res=res+count[i];
            }
        }
        return res;
    }
};
