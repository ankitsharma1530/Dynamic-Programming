class Solution {
public:
    int dp[21][2001];
    int solve(vector<int>& nums, int sum , int S, int ind){
        
        if(ind>=nums.size()){
            if(sum==S){
                return 1;
            }
            return 0;
        }
        if(dp[ind][sum+1000]!=-1){
            return dp[ind][sum+1000];
        }
        int ans = 0;
        int num1 = sum-nums[ind];
        int num2 = sum+nums[ind];
        ans +=solve(nums,num1,S,ind+1);
        ans +=solve(nums,num2,S,ind+1);
        
        return dp[ind][sum+1000] = ans;
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,S,0);
    }
};
