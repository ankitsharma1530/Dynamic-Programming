class Solution {
public:
    // recursion + memoization
    bool solve(string s,unordered_set<string>& us, unordered_map<string,bool>& ump)
    {
        // recusion base condn
        if(us.find(s)!=us.end())
        {
            return true;
        }
        // memoization base condn
        if(ump.find(s)!=ump.end())
        {
            return ump[s];
        }
        for(int i=0;i<s.length();i++)
        {
            string left = s.substr(0,i+1);
            string right = s.substr(i+1);
            if(us.find(left)!=us.end())
            {
                if(solve(right,us,ump)==true)
                {
                    ump[s]=true;
                    return ump[s];
                }
            }
        }
        return ump[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>us;
        for(auto x:wordDict)
        {
            us.insert(x);
        }
        // for memoization will we create a data structure
        unordered_map<string,bool>ump;
        return solve(s,us,ump);
    }
};
