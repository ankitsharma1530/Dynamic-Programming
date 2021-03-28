class Solution {
public:
    int solve(vector<int>& arr)
    {
        // now we have solve it like a normal DP robber question
        int m = arr.size();
        vector<int>dp(m);
        dp[0]=arr[0];
        dp[1]=max(arr[0],arr[1]);
        for(int i=2;i<m;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        }
        return dp[m-1];
        
    }
    int rob(vector<int>& nums) {
        int n =nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        if(n==3)
        {
            return max({nums[0],nums[1],nums[2]});
        }
        // now problem is from circular array
        // hence we will first ignore first element
        // then we will ignore the last element
        vector<int>v1(nums.begin(),nums.end()-1);
        vector<int>v2(nums.begin()+1,nums.end());
        int value1 = solve(v1);
        int value2 = solve(v2);
        return max(value1,value2);
    }
};
