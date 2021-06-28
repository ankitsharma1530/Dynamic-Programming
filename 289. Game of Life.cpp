class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int dx[8] = {0,0,-1,1,1,-1,1,-1};
        int dy[8] = {-1,1,0,0,1,-1,-1,1};
        vector<vector<int>>grid = board;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int c = 0;
                for(int ii=0;ii<8;ii++){
                    int x = i+dx[ii];
                    int y = j+dy[ii];
                    if(x>=0 and x<n and y>=0 and y<m and(board[x][y]==1||board[x][y]==2)){
                        c++;
                    }
                }
                
                // 2 -> before alive -> after dead
                if(board[i][j]==1){
                    if(c<2 || c>3){
                        board[i][j] = 2;
                    }
                }
                else{
                    // 3. before dead -> after alive
                    if(c==3){
                        board[i][j] = 3;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==2 || board[i][j]==0){
                    board[i][j] = 0;
                }
                else if(board[i][j]==3 || board[i][j]==1){
                    board[i][j] =1;
                }
            }
        }
        
    }
};
