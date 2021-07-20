class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int res = 0;
        int n = arr.size();
        for(int i=1;i<n-1;i++){
            // check for the peak condition
            // if peak find then go the left and the right direction
            if(arr[i]>arr[i-1] and arr[i]>arr[i+1]){
                int left = i;
                int right = i;
                while(left>0 and arr[left]>arr[left-1]){
                    left--;
                }
                while(right<n-1 and arr[right]>arr[right+1]){
                    right++;
                }
                res = max(res,right-left+1);
                i = right;
            }
        }
        return res;
    }
};
