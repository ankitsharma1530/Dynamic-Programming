class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // if(nums.size()<2){
        //     return false;
        // }
        unordered_map<int,int>ump;
        int curr_sum = 0;
        ump[0] = -1;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            int rem = curr_sum%k;
            if(ump.find(rem)!=ump.end()){
                if(i-ump[rem]>=2){
                    return true;
                }
            }
            else{
                ump[rem] = i;
            }
        }
        return false;
    }
};
