class NumMatrix {
public:
    vector<vector<int>>dp;
    // check for all test cases on notebook
    // its important to handle those test cases
    NumMatrix(vector<vector<int>>& matrix) {
        dp = matrix; // in this way we can copy whole matrix into dp
        int r = matrix.size();
        int c = matrix[0].size();
        if(r==0 || c==0)
        {
            return;
        }
        // finding cumilative sum for the matrix
        for(int i=1;i<r;i++)
        {
            dp[i][0] +=dp[i-1][0];
        }
        for(int j=1;j<c;j++)
        {
            dp[0][j]+=dp[0][j-1];
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                dp[i][j] +=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1==0 && col1==0)
        {
            return dp[row2][col2];
        }
        // edge cases
        if(row1 == 0 || col1 == 0){
            if(row1 == 0){
                return (dp[row2][col2] - dp[row2][col1-1]);
            }
            else if(col1 == 0){
                return (dp[row2][col2] - dp[row1-1][col2]);
            }
        }
        return dp[row2][col2] - dp[row1-1][col2]-dp[row2][col1-1]+dp[row1-1][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
