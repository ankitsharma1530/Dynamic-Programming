class Solution {
public:
    int dp[501];
    int solve(vector<int>& arr, int start , int k)
    {
        if(dp[start]!=-1)
        {
            return dp[start];
        }
        if(start>=arr.size())
        {
            return 0;
        }
        // counting max_sum of every window of size K
        int max_sum = INT_MIN;
        int max_ele = INT_MIN;
        // iterate for every window
        for(int i=start;i<min(start+k,(int)arr.size());i++)
        {
            // find the maximum of every index 
            max_ele = max(max_ele,arr[i]);
            max_sum = max(max_sum,solve(arr,i+1,k)+max_ele*(i-start+1));
        }
        return dp[start] = max_sum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(arr,0,k);
    }
};
