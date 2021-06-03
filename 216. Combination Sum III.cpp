class Solution {
public:
    void solve(vector<vector<int>>& res, vector<int>& ans, int start, int k, int n){
        
        if(ans.size()>k){
            return;
        }
        // base codn
        // when the size of ans = k 
        // and also we reached the targeted value
        if(n==0 && ans.size()==k){
            res.push_back(ans);
            return;
        }
        
        for(int i=start;i<=9;i++){
            ans.push_back(i);
            solve(res,ans,i+1,k,n-i);
            ans.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>ans;
        if(n>45){
            return res;
        }
        // we had to start from 1
        int start = 1;
        solve(res,ans,start,k,n);
        return res;
    }
};
