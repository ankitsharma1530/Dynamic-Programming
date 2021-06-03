class Solution {
public:
    //  TC - O(amount*number of coins)
    int dp[5001][301];
    
    int solve(vector<int>& coins, int amount, int ind){
        
        if(amount==0){
            return 1;
        }
        if(amount<0){
            return 0;
        }
        if(dp[amount][ind]!=-1){
            return dp[amount][ind];
        }
        int ans = 0;
        for(int i=ind;i<coins.size();i++){
            ans+= solve(coins,amount-coins[i],i);
        }
        return dp[amount][ind] = ans;
        
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount,0);
    }
};

// the difference between this question and combination sum-IV is basically here we had    to find combinations not the permutations 
// for finding combination we had to track the index IND
// but if we had to find permutation than we will check from 0 ---> n always
