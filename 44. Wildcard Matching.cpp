class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        if(m==0)
        {
            return n==0;
        }
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        // if string and pattern both are empty then answer is always true
        dp[0][0] = true;
        // initialise of first row
        // example - : str="" pat="a*" here output is false
        // str-""  pat="**" here true because both the * sign represent empty string
        // hence we will simply check if upto * sign the ans is true then after * it will true
        // if upto * is false then after * it will false
        for(int i=1;i<=m;i++)
        {
            if(p[i-1]=='*')
            {
                dp[0][i] = dp[0][i-1]; 
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                // if our pattern is having * on j-1
                if(p[j-1]=='*')
                {
                    // dp[i][j-1] this represent the * as empty
                    // s="abc" p="abc*" hence * is empty here
                    // dp[i-1][j] this represent that * is the charater str[i-1]
                    // s="abc" p="ab*" hence *=c so we have to check dp[i-1][j]
                    // * can be a string of many characters
                    // putting * as c above, this can only be happen if (ab*) gives us true
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                // if both the character match or if pattern is having ?
                // then it simple we can place any charater in ?
                // hence for this answer is always true
                // now we have to check wether upto this index our previous answer is what (true or false)
                else if(p[j-1]==s[i-1] || p[j-1]=='?')
                {
                    // puting previous answer
                    dp[i][j] = dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
