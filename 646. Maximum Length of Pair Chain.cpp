class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        // sort according to the ending time
        sort(pairs.begin(),pairs.end(),cmp);
        int c=1;
        
        // idea -> we put the minimum to the leftmost index
        // now we just had to calculate how many intervals starting time is greater
        // than the minimum ending time
        int end = pairs[0][1];
        for(int i=1;i<pairs.size();i++){
            if(pairs[i][0]>end){
                end = pairs[i][1];
                c++;
            }
        }
        return c;
        
    }
    // TC -> O(nlogn)+O(n)
};

/*

    // solution by DP longest incresaing subsequence(LIS) problem
    
    class Solution {
    public:

        int findLongestChain(vector<vector<int>>& pairs) {
            vector<int>dp(pairs.size(),1);
            sort(pairs.begin(),pairs.end());
            for(int i=1;i<pairs.size();i++){
                for(int j=0;j<i;j++){
                    if(pairs[i][0]>pairs[j][1]){
                        if(dp[i]<dp[j]+1){
                            dp[i] = dp[j]+1;
                        }
                    }
                }
            }
            return *max_element(dp.begin(),dp.end());
        }
    };

    Time complexity - O(nlogn)+O(n^2)
    space -> O(n)
*/
