class Solution {
public:
    int dp[201][201];
    // not a min-max poth problem remember
    int dfs(vector<vector<int>>& dungeon,int i,int j,int n,int m){
        // out of bounds range
        if(i>=n || j>=m){
            return 1e9+5;
        }
        if(i==n-1 and j==m-1){
            if(dungeon[i][j]>0){
                // if destination cell contain positive energy
                // then according to question we need 1 unit of energy 
                return 1;
            }
            return 1+abs(dungeon[i][j]);
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // now i will check wether the right or down , which want more power 
        // we will choose that path which need less power from us
        int right = dfs(dungeon,i,j+1,n,m);
        int down = dfs(dungeon,i+1,j,n,m);
        
        int ans = min(right,down)-dungeon[i][j];
        
        if(ans<=0){
            // this means we have sufficent energy
            // henece as we know for sufficent energy we had to return 1
            return dp[i][j] = 1;
        }
        return dp[i][j] = ans;
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        int n = dungeon.size();
        int m = dungeon[0].size();
        return dfs(dungeon,0,0,n,m);
    }
};
