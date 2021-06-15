class Solution {
public:
    int dp[20001];
    int solve(vector<int>& nums, int ind){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int if_we_include_ind = ind;
        
        int sum =0;
        // if we include the current element
        while(if_we_include_ind<nums.size() and nums[ind]==nums[if_we_include_ind]){
            sum+=nums[if_we_include_ind];
            if_we_include_ind++;
        }
        // as if we had include the current elemnt then we had to ignore the
        // num+1 and num-1 element
        // as the nums array is sorted hence we have only (nums+1) number
        while(if_we_include_ind<nums.size() and nums[ind]+1==nums[if_we_include_ind]){
            if_we_include_ind++;
        }
        
        int if_curr_choose = sum+solve(nums,if_we_include_ind);
        int if_curr_ignore = solve(nums,ind+1);
        int res = max(if_curr_ignore,if_curr_choose);
        return dp[ind] = res;
        
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};
