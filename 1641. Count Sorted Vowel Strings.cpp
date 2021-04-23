class Solution {
public:
static const int size = 100;
int dp[size][size];
int find_strings(int n, int a) {
    if (n == 0) {
        return 1;
    }
	int ans = 0;
	for (int i = a; i < 5; i++) {
		if (dp[n][i] == -1) {
			ans += find_strings(n - 1, i);
			dp[n - 1][i] = ans;
		} else {
			ans += dp[n - 1][i];
		}
	}
	return ans;
}
    
int countVowelStrings(int n) {
    memset(dp,-1,sizeof(dp));
    return find_strings(n , 0);
}
}
