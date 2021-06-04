class Solution {
public:
    // TC - O(mn)
    int dp[1001][1001];
    int find_sum(string& s,int ind){
        // function to find sum of the string
        int sum = 0;
        for(int i=ind;i<s.length();i++){
            sum+=int(s[i]);
        }
        return sum;
    }
    
    int solve(string& s1, string& s2, int i,int j){
        if(i==s1.length() || j==s2.length()){
        // if we reach the end of both strings 
        //this means we do not have to subtract anything because they r already equal
            if(i==s1.length() and s2.length()==j){
                return 0;
            }
            
        // if our one string is empty but other is not
        // then we had to delete every element from that string to make strings equal
            if(i==s1.length()){
                return dp[i][j] = find_sum(s2,j);
            }
            else if(j==s2.length()){
                return dp[i][j] = find_sum(s1,i);
            }
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int ans = 0;
        // if the character match then we dont have to do anything
        // we just ignored it and call for the next
        if(s1[i]==s2[j]){
            ans = solve(s1,s2,i+1,j+1);
        }
        else{
            // if the ith character of s1 and jth character of s2 dont match
            // then we had two option to do as we have in LCS
            // either we can skip i, or we can skip j
            // so we will skip both, and which ever will gives us the minimum we will               // take that
            
            ans = min({int(s1[i])+solve(s1,s2,i+1,j),
                     int(s2[j])+solve(s1,s2,i,j+1)});
            
        }
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);        
        
    }
};


// we can also do this by first finding LCS for both the strings
// Then using that LCS string we will find the cost of subtraction 
