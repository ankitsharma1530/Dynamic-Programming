class Solution {
public:
    // time complexity - O(n^3)
    vector<int> prefixSum;			
    int dp[501][501];
    int solve(vector<int>& stoneValue,int i,int j)
    {
        // as if i==j , this means we have only one element with us
        // as at one element the game is over
        // hence our base condn is changed
        if(i==j)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int ans = 0;
        for(int p=i+1;p<=j;p++)		//Try each partition.
        {
            // sum of the left subarray
			int l=prefixSum[p]-prefixSum[i];
            // sum of the right subarray
            int r=prefixSum[j+1]-prefixSum[p];
            
			if(l<r){
                //Left part is smaller
                ans=max(ans,l+solve(stoneValue,i,p-1));
            }
            else if(l>r){
                //Right part is smaller
                ans=max(ans,r+solve(stoneValue,p,j));
            }
            else{
                //Both parts are equal
                ans=max(ans,l+max(solve(stoneValue,p,j),
                                                solve(stoneValue,i,p-1)));
            }
        }
        return dp[i][j] = ans;
    }
    int stoneGameV(vector<int>& stoneValue)
    {
        memset(dp,-1,sizeof(dp));
        // holding the prefix sum array
        prefixSum.resize(stoneValue.size()+1,0);
        for(int i=0;i<stoneValue.size();i++){		
            //Create prefix Sums
            prefixSum[i+1]=prefixSum[i]+stoneValue[i];
        }
        int profit_alice =  solve(stoneValue,0,stoneValue.size()-1);
        return profit_alice;
    }
};
