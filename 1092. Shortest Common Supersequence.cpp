class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j] = 0;
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        string res = "";
        while(n>0 || m>0)
        {
            if(m==0)
            {
                res.push_back(str1[n-1]);
                n--;
            }
            else if(n==0)
            {
                res.push_back(str2[m-1]);
                m--;
            }
            else if(str1[n-1]==str2[m-1])
            {
                res.push_back(str2[m-1]);
                m--;
                n--;
            }
            else if(dp[n-1][m]>dp[n][m-1])
            {
                res.push_back(str1[n-1]);
                n--;
            }
            else
            {
                res.push_back(str2[m-1]);
                m--;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
