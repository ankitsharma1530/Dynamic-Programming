// O(n*n*m)
// class Solution {
// public:
//     int minFallingPathSum(vector<vector<int>>& arr) {
//         vector <vector <int>> dp = arr;
//         for(int i = 1; i < arr.size(); ++i)
//             for(int j = 0; j < arr[0].size(); ++j){
//                 dp[i][j] = INT_MAX;
//                 for(int k = 0; k < arr[0].size(); ++k){
//                     if(j == k)
//                         continue;
//                     dp[i][j] = min(dp[i - 1][k] + arr[i][j],dp[i][j]);
//                 }
//             }
        
//         int result = INT_MAX;
//         for(int i = 0; i < arr[0].size(); ++i)
//             result = min(dp[dp.size() - 1][i],result);
//         return result;
//     }
// };

class Solution {
public:
    int dp[201][201];
    int f(vector<vector<int>>& arr, int i, int j) {
        if(i == arr.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = INT_MAX;
        for(int k = 0; k < arr[0].size(); k++) {
            if(k == j)
                continue;
            int curr = arr[i][j] + f(arr, i + 1, k);
            ans = min(ans, curr);
        }
        return dp[i][j] = ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int ans = INT_MAX;
        memset(dp, -1, sizeof dp);
        for(int j = 0; j < arr[0].size(); j++) {
            ans = min(ans, f(arr, 0, j));
        }
        return ans;
    }
};
