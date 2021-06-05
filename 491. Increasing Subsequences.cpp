// class Solution {
// public:
    // we used set so that duplicates will handeled easily
    // set<vector<int>> result;
    // vector<int> temp;
    // void solve(vector<int> nums,int src,int last){ 
    // last = last number of temp_array
    //     if(temp.size()>1)
    //         result.insert(temp);
    //     for(int i=src;i<nums.size();i++){
            // on the time of insertion we will check wether LIS property is followed or not . If lis property is not followed then we simply ignore that number and check for the next numbers.
            
            
//             if(nums[i]>=last){ // lis property followed
//                 temp.push_back(nums[i]);
//                 solve(nums,i+1,nums[i]);
//                 temp.pop_back();
//             }else{
//                 solve(nums,i+1,last);
//             }
//         }
//     }
//     vector<vector<int>> findSubsequences(vector<int>& nums) {
//         solve(nums,0,INT_MIN); 
//         vector<vector<int>> res(result.begin(),result.end());
//         return res;
//     }
// };

// Time complexity -> The worst case should be O(2^N) (e.g for sorted increasing array); since the total search tree contains O(2^N) of nodes (because each number can be in or not in the list). For random array, since we can pruning a lot of subtree search, usually, it will be much faster.




class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(nums, temp, res, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<int>& temp, 
             vector<vector<int>>& res, int start) {
        if(temp.size() >= 2) {
            res.push_back(temp);
        }
        
        unordered_set<int> used;
        for(int i = start; i < nums.size(); ++i) {
            if((temp.empty() || nums[i] >= temp.back()) && !used.count(nums[i])) {
                temp.push_back(nums[i]);
                dfs(nums, temp, res, i + 1);
                used.insert(nums[i]);
                temp.pop_back();
            }
        }
    }
};
