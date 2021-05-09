class Solution{

public:
	ll countStrings(int n) {
	    const ll MOD = 1e9 + 7;
	    ll a[n], b[n];
	    a[0] = b[0] = 1;
	    for (int i = 1; i < n; i++) {
	        a[i] = (a[i - 1] % MOD + b[i - 1] % MOD) % MOD;
	        b[i] = a[i - 1] % MOD;
	    }
	    return (a[n - 1] % MOD + b[n - 1] % MOD) % MOD;
	}
};
