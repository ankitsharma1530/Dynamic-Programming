class Solution {
public:
    int dp[101][101][601];
    int solve(vector<pair<int,int>>& arr, int m, int n,int ind){
        if(ind>=arr.size()){
            return 0;
        }
        if(dp[m][n][ind]!=-1){
            return dp[m][n][ind];
        }
        int ans ;
        if(arr[ind].first<=m and arr[ind].second<=n){
            ans = max(1+solve(arr,m-arr[ind].first,n-arr[ind].second,ind+1),
                      solve(arr,m,n,ind+1));
        }
        else{
            ans = solve(arr,m,n,ind+1);
        }
        return dp[m][n][ind] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>arr;
        for(auto x:strs){
            int i=0;
            int j=0;
            for(auto y:x){
                if(y=='0'){
                    i++;
                }
                else{
                    j++;
                }
            }
            arr.push_back(make_pair(i,j));
        }
        memset(dp,-1,sizeof(dp));
        return solve(arr,m,n,0);
    }
};
