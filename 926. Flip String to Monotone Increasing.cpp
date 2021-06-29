class Solution {
public:
    // O(1) space solution in leetcode notes
    int minFlipsMonoIncr(string s) {
        // We need to split the array into left '0' and right '1' sub-arrays, 
        // so that sum of '1' -> '0' flips (left) and '0' -> '1' flips (right) is minimal.
        // Count of '0' -> '1' flips going left to right, and store it in f0.
        // Count of '1' -> '0' flips going right to left, and store it in f1.
        // Find a the smallest f0[i] + f1[i].
        int n = s.length();
        int f0[n];
        int f1[n];
        f0[0] = s[0]=='1'?1:0;
        f1[n-1] = s[n-1]=='0'?1:0;
        for(int i=1;i<n;i++){
            if(s[i]=='1'){
                // the left one which we had to swap
                f0[i] = 1+f0[i-1];
            }
            else{
                f0[i] = f0[i-1];
            }
        }
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0'){
                // these are the zeros which are on right side and which we had to swap
                f1[i] = f1[i+1]+1;
            }
            else{
                f1[i] = f1[i+1];
            }
        }
        
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            res = min(f0[i]+f1[i]-1,res);
        }
        return res;
    }
};
