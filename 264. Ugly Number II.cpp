class Solution {
public:
    int nthUglyNumber(int n) {
        int i2=0;
        int i3=0;
        int i5=0;
        int dp[n];
        int m2 = 2;
        int m3 = 3;
        int m5 = 5;
        //initalise our dp
        dp[0] = 1;
        for(int i=1;i<n;i++)
        {
            int mn = min({m2,m3,m5});
            dp[i] = mn;
            if(mn==m2)
            {
                i2=i2+1;
                m2=dp[i2]*2;
            }
            if(mn==m3)
            {
                i3=i3+1;
                m3=dp[i3]*3;
            }
            if(mn==m5)
            {
                i5=i5+1;
                m5=dp[i5]*5;
            }
        }
        return dp[n-1];
    }
};
