class Solution {
public:
    int dp[101][101];
    // time complexity -> O(k*n^2)
    int makePalindrome(int i,int j,string s)
    {
        int len=j-i+1;
        int ret=0;
        for(int k=0;k<len/2;++k)
            if(s[i+k]!=s[j-k])
                ++ret;
        return ret;
    }
    int solve(string s, int k, int i, int j,vector<vector<int>>& count){
        
        
        if(k==0 and i==s.length()){
            return 0;
        }
        if(k<0){
            return INT_MAX/2;
            // INT_MAX/2 is because to overcome the overflow codn
        }
        if(k>0 and i==s.length()){
            return INT_MAX/2;
        }
        
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int ans = INT_MAX;
        for(int ind=i;ind<=j;ind++){
            ans = min(ans,count[i][ind]+solve(s,k-1,ind+1,j,count));
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        int n = s.length();
        vector<vector<int>> count(n,vector<int>(n,0));
        for(int i=0;i<n;++i)
		for(int j=i+1;j<n;++j)
			count[i][j]=makePalindrome(i,j,s);
        return solve(s,k,0,s.length()-1,count);
    }
};
