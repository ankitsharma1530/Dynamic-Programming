class Solution {
public:
    int dp[101][101];
    // time complexity -> O(m*n)
    bool solve(string& s1, string& s2, string& s3, int i, int j,int k){
        if(i==s1.length() and j==s2.length() and k==s3.length()){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        bool ans = false;
        if(i!=s1.length()){
            if(s1[i]==s3[k])
                ans = ans||solve(s1,s2,s3,i+1,j,k+1);
        }
        if(j!=s2.length()){
            if(s2[j]==s3[k])
                ans = ans||solve(s1,s2,s3,i,j+1,k+1);
        }
        return dp[i][j] = ans;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        return solve(s1,s2,s3,0,0,0);
    }
};
