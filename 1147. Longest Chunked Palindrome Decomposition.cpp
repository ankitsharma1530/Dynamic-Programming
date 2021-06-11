class Solution {
public:
    int longestDecomposition(string text) {
        int i=0;
        int j=text.length()-1;
        string left = "";
        string right = "";
        int ans = 0;
        while(i<j){
            left+=text[i];
            right = text[j]+right;
            if(left==right){
                ans+=2;
                left="";
                right="";
            }
            i++;
            j--;
        }
        if(left.size()==0 and right.size()==0 and text.length()%2){
            ans++;
        }
        if(left.size() || right.size()){
            ans++;
        }
        return ans;
    }
};
