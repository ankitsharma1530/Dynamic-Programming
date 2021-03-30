class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_set<char>st;
        vector<int>count(26,0);
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']++;
        }
        string res = "";
        for(int i=0;i<s.length();i++)
        {
            // as s[i] is going to used here hence we subtract 1 count of s[i] from COUNT_array
            // it actually indicates how many occurrence of that character are left in the string.
            count[s[i]-'a']--;
            // if our character is already present in the set
            if(st.find(s[i])!=st.end())
            {
                continue;
            }
            // main loop
            // here we have to find wether lexicographical order is not followed 
            while(res.length()>0 && s[i]<res.back() && count[res.back()-'a']>0)
            {
                st.erase(res.back());
                res.pop_back();
            }
            res.push_back(s[i]);
            st.insert(s[i]);
        }
        return res;
    }
};
