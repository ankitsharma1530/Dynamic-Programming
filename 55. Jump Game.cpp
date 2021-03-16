class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
        {
            return true;
        }
        if(nums.size()==0)
        {
            return false;
        }
        int jumps =-1;
        for(int i=0;i<nums.size();i++)
        {
            jumps = max(jumps,nums[i]);
            
            
            if(jumps==0 && i!=nums.size()-1)
            {
                return false;
            }
            jumps--;
        }
        return true;
    }
};
