class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n==1)
        {
            return s;
        }
        if(n==2)
        {
            if(s[0]==s[1])
            {
                return s;
            }
            else
            {
                string res = "";
                res.push_back(s[0]);
                return res;
            }
        }
        vector<vector<bool>>dp(n,vector<bool>(n));
        string res = "";
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
                    res = s.substr(i,j-i+1);
                 }
                i++;  
            }
        }
        // return "c";
        return res;
        
    }
};
