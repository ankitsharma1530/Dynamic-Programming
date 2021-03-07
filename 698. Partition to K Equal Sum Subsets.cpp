class Solution {
public:
    bool solve(int index , int k ,vector<int>& nums , vector<bool>&vis, int target , int curr)
    {
        if(k==1)
        {
            return true;
        }
        // if we reach for desired sum then call for the next permutaiton with starting index and everthing started
        if(curr==target)
        {
            return solve(0,k-1,nums,vis,target,0);
        }
        for(int i=index;i<nums.size();i++)
        {
            if(vis[i]==false)
            {
            vis[i] = true;
            if(solve(i+1,k,nums,vis,target,curr+nums[i]))
            {
                return true;
            }
            vis[i] = false;
            }
        }            
        
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==0)
        {
            return true;
        }
        int sum = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum = sum+nums[i];
        }
        if(sum%k!=0)
        {
            return false;
        }
        vector<bool>vis(nums.size(),false);
        return solve(0,k,nums,vis,sum/k,0);
    }
};
