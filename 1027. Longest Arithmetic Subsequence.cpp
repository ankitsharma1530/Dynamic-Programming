class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // 3 6 9 12
        // we will store the maximum length for each difference
        // as the range of  nums[i] is from 2 to 1000
        // hence the difference will be in the range of 1000 itself
        
        int n = nums.size();
        int res = -1;
        vector<vector<int>>dp(n,vector<int>(1001,1));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                int diff = nums[i]-nums[j]+500;
                if(dp[i][diff]<dp[j][diff]+1){
                    dp[i][diff] = dp[j][diff]+1;
                }
                res = max(res,dp[i][diff]);
            }
        }
        return res;
        
    }
};
