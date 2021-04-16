class Solution {
public:
    int helper(string s1,string s2,int n,int m,int i,int j,vector<vector<int> > &hash)
    {
        if(i==n && j==m) 
            return 0;
        if(j==m) 
            return n-i;
        if(i==n) 
            return m-j;
        if(hash[i][j]!=-1) 
            return hash[i][j];
        if(s1[i] == s2[j])
        return hash[i][j] = helper(s1,s2,n,m,i+1,j+1,hash);
        return hash[i][j] = 1+min(helper(s1,s2,n,m,i,j+1,hash),min(helper(s1,s2,n,m,i+1,j,hash),helper(s1,s2,n,m,i+1,j+1,hash)));
    }
    
    int minDistance(string s1, string s2) {
        vector<vector<int> > hash(s1.size(),vector<int>(s2.size(),-1));
        return helper(s1,s2,s1.size(),s2.size(),0,0,hash);
    }
};
