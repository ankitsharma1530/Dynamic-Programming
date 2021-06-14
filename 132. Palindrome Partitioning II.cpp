class Solution {
public:
    // from my side TC -> O(n^2)
    int dp1[2001][2001];
    int dp2[2001][2001];
    
    // memo code for palindrome
    bool isPalin(string& s, int i, int j) {
        if (i >= j) return true;
        if (dp1[i][j] != -1) return dp1[i][j];
        if (s[i] == s[j]) return dp1[i][j] = isPalin(s, i + 1, j - 1);
        return dp1[i][j] = false;
    }
    
    
    // memo code for our solution
    int ff(string& s, int i, int j) {
        if (i >= j) return 0;
        
        // before entering into the main operations we have to check wether the given 
        // is a palindrome or not
        if (isPalin(s, i, j)) return dp2[i][j] = 0;
        if (dp2[i][j] != -1) return dp2[i][j];
        
        int min_cuts = INT_MAX;
        
        for (int idx = i; idx <= j; idx++) {
            if (isPalin(s, i, idx)) {
                min_cuts = min(min_cuts, 1 + ff(s, idx + 1, j));
            }
        }
        
        return dp2[i][j] = min_cuts;
    }
    
    int minCut(string s) {
        memset(dp1, -1, sizeof dp1);
        memset(dp2, -1, sizeof dp2);
        return ff(s, 0, s.length() - 1);
    }
};
