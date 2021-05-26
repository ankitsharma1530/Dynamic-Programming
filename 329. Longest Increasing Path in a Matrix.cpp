class Solution {
public:
    int dp[201][201];
    int dfs(vector<vector<int>>& matrix, int n, int m,int x,int y,int val)
    {
        if(x<0 or x>=n or y<0 or y>=m)
        {
            return 0;
        }
        
        if(matrix[x][y]>val)
        {
            if(dp[x][y]!=-1)
            {
                return dp[x][y]; 
            }
            int a = dfs(matrix,n,m,x+1,y,matrix[x][y]);
            int b = dfs(matrix,n,m,x-1,y,matrix[x][y]);
            int c = dfs(matrix,n,m,x,y+1,matrix[x][y]);
            int d = dfs(matrix,n,m,x,y-1,matrix[x][y]);
            dp[x][y] = max({a,b,c,d})+1;
            return dp[x][y];
        }
        return 0;
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        memset(dp,-1,sizeof(dp));
        int max_len = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                max_len = max(max_len,dfs(matrix,n,m,i,j,INT_MIN));
            }
        }
        return max_len;
    }
};
