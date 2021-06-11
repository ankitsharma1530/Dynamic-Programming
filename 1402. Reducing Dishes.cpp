class Solution {
public:
    // O(nlogn) + O(n*n)
    int dp[501][501];
    int solve(vector<int>& s, int ind, int n,int m){
        if(ind>n){
            return 0;
        }
        if(dp[ind][m]!=-1){
            return dp[ind][m];
        }
        return dp[ind][m] = max(solve(s,ind+1,n,m),m*s[ind]+solve(s,ind+1,n,m+1));
    }
    int maxSatisfaction(vector<int>& s) {
        int n = s.size();
        sort(s.begin(),s.end());
        memset(dp,-1,sizeof(dp));
        return solve(s,0,n-1,1);
        
        
    }
};
