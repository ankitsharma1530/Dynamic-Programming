class Solution {
public:
    // time complexity -> O(n^2)
    int dp[2001][4];
    int pal[2001][2001];
    
    bool ispal(string& s,int i,int j){
        if(i>=j){
            return true;
        }
        if(pal[i][j]!=-1){
            return pal[i][j];
        }
        if(s[i]==s[j]){
            return pal[i][j] = ispal(s,i+1,j-1);
        }
        return pal[i][j] = false;
    }
    
    bool solve(string& s, int i, int j, int k){
        
        
        if(i>=j){
            if(k==3){
                return true;
            }
            return false;
        }
        if(k>=3){
            return false;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        
        
        bool ans = false;
        for(int ind=i;ind<j;ind++){
            if(ispal(s,i,ind)){
                ans = ans || solve(s,ind+1,j,k+1);
                if(ans){
                    break;
                }
            }
        }
        return dp[i][k] = ans;
        
    }
    bool checkPartitioning(string s) {
        int k = 3;
        memset(dp,-1,sizeof(dp));
        memset(pal,-1,sizeof(pal));
        return solve(s,0,s.length(),0);
    }
};
