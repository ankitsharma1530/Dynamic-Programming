class Solution {
public:
    bool dfs(string s, int n, int ind,long long int val)
    {
       if(ind==s.length())
       {
           return true;
       }
        for(int j=ind;j<n;j++)
        {
            long long int temp_val = stoll(s.substr(ind,j-ind+1));
            // cout<<temp_val<<endl
            if(temp_val>=1e11)
                break;
            if(temp_val+1==val && dfs(s,n,j+1,temp_val)==true)
            {
                return true;
            }
        }
        return false;
        
    }
    
    bool splitString(string s) {
        int n = s.length();
        for(int i=0;i<n-1;i++)
        {
            long long int val = stoll(s.substr(0,i+1));
            // string st = s.substr(i+1,n);
            if(val>=1e11)
                break;
            if(dfs(s,n,i+1,val)==true)
            {
                return true;
            }
        }
        return false;
    }
};
