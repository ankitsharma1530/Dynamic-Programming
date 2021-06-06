class Solution {
public:
    // Time complexity -> O(k*n^2)
    
    
    double solve(vector<int>& nums, int k, int ind,vector<vector<double>>& dp){
        if(ind>=nums.size()){
            return  0;
        }
        
        // this is an edge case
        // see if k==0 then it means that we can not afford any more partitons
        // as the first base condn was not true which means we are not on the last index
        // so we can conclude that more numbers are there to include in partiton
        // for exp -> [1,2,3,4,5] and k=3 , and our partitions are [1],[2],[3]
        // as total paritions are occupied and we are not on last index, so the 4,5                 elements were left. Which is a faulty case. hence we return INT_MIN
        
        if(k==0){
            return INT_MIN;
        }
        if(dp[ind][k]!=-1.00){
            return dp[ind][k];
        }
        double ans = INT_MIN;
        double sum = 0;
        for(int i=ind;i<nums.size();i++){
            sum+=nums[i];
            ans = max(ans,sum/(i-ind+1) + solve(nums,k-1,i+1,dp));
            // (i-ind+1) -> number of elements that together add and make SUM
        }
        return dp[ind][k] = ans;
    }
    double largestSumOfAverages(vector<int>& nums, int k) {
        // memset(dp,-1.00,sizeof(dp));
        vector<vector<double>>dp(nums.size()+1,vector<double>(nums.size()+1,-1.00));
        // read the question
        // we can take AT_MOST k partitions
        // this means less than are also allowed
        return solve(nums,k,0,dp);
    }
};
