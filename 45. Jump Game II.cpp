class Solution {
public:
    int jump(vector<int>& nums) {
        // [2,3,1,1,4]
        // [0,1,1,2,2]
        // ans  = 2
        // dp[] = [0,INF,INF,INF,INF]
        // [0,1,1,INF,INF]
        // [0,1,1,2,2]
        int n = nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n-1;i++)
        {
            int steps = nums[i];
            for(int j=i+1;j<=steps+i;j++)
            {
                if(j>=n)
                {
                    break;
                }
                dp[j] = min(dp[j],dp[i]+1);
            }
                
        }
        return dp[n-1];
        
        
    }
};
