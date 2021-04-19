class Solution {
public:
   int solve(vector<int>& nums,int target,vector<int>&dp)
    {
        int result = 0;
        if(target==0) 
            return 1;
        
        if(target<0)
            return 0;
        
        if(dp[target] != -1)       // If already computed
            return dp[target];
        
        for(int i=0;i<nums.size();i++)
           result += solve(nums,target-nums[i],dp);
            
        
        dp[target] = result;
        return result;
    }
 
 
    int combinationSum4(vector<int>& nums, int target) {
        // sort(nums.begin(),nums.end());
        if(nums.size()==0)
            return 0;
        
       int cnt = 0;
       vector<int>dp(target+1,-1);
      return  solve(nums,target,dp);
        
       
       
        
    }
};
