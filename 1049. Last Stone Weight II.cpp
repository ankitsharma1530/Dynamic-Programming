class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0, n=stones.size();
        for(int i=0; i<n; i++){
            sum += stones[i];
        }
        
        bool dp[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i==0)
                    dp[i][j]=false;
                if(j==0)
                    dp[i][j]=true;
            }
        }
        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-stones[i-1]];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        vector<int> temp;
        for(int j=0; j<=(sum/2); j++){
            if(dp[n][j]==true){
                temp.push_back(j);
            }
        }
        int max=-1;
        for(int i=0; i<temp.size(); i++){
            if(temp[i]>max)
                max=temp[i];
        }
        
        int res = sum - (2*max);
        return res;
    }
};
