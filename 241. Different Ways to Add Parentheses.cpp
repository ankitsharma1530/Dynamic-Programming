// check the leetcode notes for recursive diagram
// time compleity -> 

// INTRO -> this is a new type of problem 
// we are creating a left and right sub tree for every OPERATOR
// we iterate for string from left to right... when we got the operator (i.e +,-,*) we simply call on string from 0-->i(left) and i+1-->n(right)
// this can be shown in the diagram
class Solution {
public:
    // for memo we will use map
    unordered_map<string,vector<int>>ump;
    vector<int> solve(string expression){
        if(ump.find(expression)!=ump.end()){
            return ump[expression];
        }
        vector<int>res;
        vector<int>left,right;
        for(int i=0;i<expression.length();i++){
            if(expression[i]=='*' || expression[i]=='+' || expression[i]=='-'){
                left = solve(expression.substr(0,i));
                right = solve(expression.substr(i+1));
            }
            
            for(auto& x:left){
                for(auto& y:right){
                    if(expression[i]=='*'){
                        res.push_back(x*y);
                    }
                    else if(expression[i]=='-'){
                        res.push_back(x-y);
                    }
                    else if(expression[i]=='+'){
                        res.push_back(x+y);
                    }
                }
            }
        }
        // the base case when there is no operator 
        // eg-> "1" or "12" or "123"
        // here we simply add integer value to the array
        if(res.size()==0){
            res.push_back(stoi(expression));
        }
        return ump[expression] = res;
    }
    vector<int> diffWaysToCompute(string expression) {
        return solve(expression);
    }
};
