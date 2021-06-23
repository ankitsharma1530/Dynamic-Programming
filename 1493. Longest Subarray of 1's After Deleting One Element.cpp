// time complexity -> O(n)
class Solution {
public:
    // as because we had to delete one element from the middle of the array
    // hence we can derive we had to calculate the left and the right values
    // hence we create this left and right prefix sum
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l[n];
        int r[n];
        l[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                l[i]=0;
            }
            else{
                l[i]=l[i-1]+1;
            }
        }
        r[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]==0){
                r[i]=0;
            }
            else{
                r[i]=r[i+1]+1;
            }
        }
        int res = 0;
        for(int i=1;i<n-1;i++){
            res = max(res,l[i-1]+r[i+1]);
        }
        return res;
        
    }
};
