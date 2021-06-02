// class Solution {
// public:
//     int dp[50001];
//     int solve(vector<int>&arr, int ind){
//         //base condn
//         if(ind>=arr.size()){
//             return 0;
//         }
//         if(dp[ind]!=-1){
//             return dp[ind];
//         }
//         int value = arr[ind]-solve(arr,ind+1);
//         int sum = arr[ind];
//         int n = arr.size();
//         for(int i=ind+1;i<min(ind+3,n);i++){
//             sum+=arr[i];
//             value = max(value,sum-solve(arr,i+1));
//         }
//         return dp[ind] = value;
//     }
//     string stoneGameIII(vector<int>& arr) {
//         memset(dp,-1,sizeof(dp));
//         int value = solve(arr,0);
//         // here value means the maximum value that our First player (ALICE) can have
//         // this value can be zero if the score tie
//         // this value will be > 0 if alice is having more points
//         // and will<0 if alice is having less points than bob
//         if(value>0){
//             return "Alice";
//         }
//         else if(value<0){
//             return "Bob";
//         }
//         return "Tie";
//     }
// };

class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size()+1, INT_MIN);
        
        dp[stoneValue.size()] = 0;
        
        for(int i = stoneValue.size()-1; i>=0; --i)
        {
            int sum = stoneValue[i];
            int value = sum - dp[i+1];
            
            for(int j = i+1; j < min(i+3, (int)stoneValue.size()); ++j)
            {
              sum+=stoneValue[j];
                value = max(value, sum- dp[j+1]);
            } 
            
            dp[i]= value;
            
        }
        
       int value = dp[0];    
       if(value > 0)
           return "Alice";
        else if(value  < 0)
            return "Bob";
        else
            return "Tie";
        }
};
