class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n));
        int count = 0;
        for(int gap=0;gap<n;gap++)
        {
            int i=0;
            for(int j=gap;j<n;j++)
            {
                if(gap==0)
                {
                    dp[i][j] = true;
                }
                else if(gap==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] =false;
                    }
                }
                else 
                {
                    if(s[i]==s[j] && dp[i+1][j-1]==true)
                    {
                        dp[i][j] = true;
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
                if(dp[i][j]==true)
                {
                    count++;
                }
                i++;
            }
        }
        return count;
    }
};
