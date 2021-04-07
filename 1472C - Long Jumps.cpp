#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define ff first
#define ss second
#define pii pair<int,int>
#define vii vector<ii>
#define lli long long int
#define ll long 
#define INF 1000000000;
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
/*
vector<lli>arr;
for(int i=0;i<n;i++)
{
	lli it;
	cin>>it;
	arr.push_back(it);
}
*/
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
		lli n;
		cin>>n;
		vector<lli>arr;
		for(int i=0;i<n;i++)
		{
			lli it;
			cin>>it;
			arr.push_back(it);
		}
		vector<lli>dp(n);
		for(int i=n-1;i>=0;i--)
		{
			lli sum = 0;
			if(arr[i]+i<n)
			{
				sum+=dp[arr[i]+i];
			}
			dp[i] = sum+arr[i];
		}
		cout<<*max_element(dp.begin(),dp.end());
	  	cout<<endl;
    }
}
