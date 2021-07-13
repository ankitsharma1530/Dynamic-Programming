class Solution {
public:
    vector<vector<int>> length;
    unordered_map<int, int> idx;
    
    int dfs(vector<int>& nums, int i, int j)
    {
        if(length[i][j] != -1)
        	return length[i][j];
        else if(idx.count(nums[i] + nums[j]) == 0)
            return length[i][j] = 0;
        else
            return length[i][j] = max(length[i][j], 1 + 
                                      dfs(nums, j, idx[nums[i] + nums[j]]));
    }
    
    int lenLongestFibSubseq(vector<int>& nums) 
    {
    	if(nums.size() < 3)
    		return 0;

    	for(int i = 0; i < nums.size(); i++)
    		idx[nums[i]] = i;

    	int res = 0;
    	length = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -1));
        for(int i = 0; i + 1 < nums.size(); i++)
            for(int j = i + 1; nums[i] + nums[j] <= nums.back(); j++)
                res = max(res, dfs(nums, i, j));

        return res == 0 ? res : res + 2;
    }
};
