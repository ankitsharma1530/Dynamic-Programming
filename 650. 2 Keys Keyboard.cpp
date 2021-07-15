class Solution {
public:
    // In each step there are 2 choices: 
    // Paste copy value with current value => 1 step
    // Copy current value and then paste it with itself => 2 step

    // Get minimum value from those 2 recursive calls.
    int dp[1001][1001];
    int dfs(int steps, int value,int copy, int& n){
        if(value>n){
            return INT_MAX;
        }
        if(value==n){
            return steps;
        }
        if(dp[value][steps]!=-1){
            return dp[value][steps];
        }
        return dp[value][steps] = 
            min(dfs(steps+1,value+copy,copy,n),dfs(steps+2,value*2,value,n));
    }
    int minSteps(int n) {
        if(n==1)
            return 0;
        memset(dp,-1,sizeof(dp));
        return dfs(1,1,1,n);
    }
};
