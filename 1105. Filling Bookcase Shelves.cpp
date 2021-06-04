class Solution {
public:
    /*
    Without memoisation(i.e recursion), O(2 ^ n), where n is the number of books.
    With memoisation, O(n * m), where m is the maximum width.
    */
    
    int dp[1001][1001];
    int solve(vector<vector<int>>& books, int ind, int curr_width, int curr_height, int max_width){
        if(ind>=books.size()){
            return dp[ind][curr_width] = curr_height;
        }
        if(dp[ind][curr_width]!=-1){
            return dp[ind][curr_width];
        }
        // if we can put current element in same level
        if(curr_width+books[ind][0]<=max_width){
            // then update the height
            int new_height = max(curr_height,books[ind][1]);
            return dp[ind][curr_width] = 
                min(solve(books,ind+1,curr_width+books[ind][0],new_height,max_width),
                      solve(books,ind+1,books[ind][0],books[ind][1],max_width)+curr_height);
            
        }
        else{
            return dp[ind][curr_width] = 
                curr_height+solve(books,ind+1,books[ind][0],books[ind][1],max_width);
        }
    }
    int minHeightShelves(vector<vector<int>>& books, int max_width) {
        memset(dp,-1,sizeof(dp));
        return solve(books,0,0,0,max_width);
    }
};
