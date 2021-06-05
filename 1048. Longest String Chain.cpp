class Solution {
public:
    // TC -> O(nlogn + n*l*l)
    // nlogn -> for sorting
    //n*l*l -> traversing each word * traversing each index of word * creaing substr
    static bool cmp(string& a, string& b){
        return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>ump;
        // this map will store the maximum chain length for a word
        // string --> word   ,   int --> maximum chain length
        
        // now we will sort our words array according to the length
        // because we will find our length from small words to big and bigger words
        sort(words.begin(),words.end(),cmp); // nlogn
        
        int res = 0; // result
        for(auto& word:words){ // O(n)
            
            // as for every word the minimum chain length is 1
            int chain_length = 1;
            
            // now we will delete each and every character one by one
            for(int i=0;i<word.length();i++){ // O(l)
                
                 /*
					Find all possible predecessors of word by removing one character
					If you see that we have that predecessor, then we add +1 to the 
					predecessor chain to reach to current word.
					Similarly, for all possible predecessors, find the maximum chain to                     reach
					current word.
				*/
                string new_word = word.substr(0,i)+word.substr(i+1); // O(l)
                
                // if predecessor is present
                if(ump.find(new_word)!=ump.end()){
                    // then we will find the best and max chain_length
                    chain_length = max(chain_length,ump[new_word]+1);
                }
            }
            // update the chain length for the current word
            ump[word] = chain_length;
            res = max(res,chain_length);
        }
        return res;
    }
};

// here you can also use LIS idea
// https://leetcode.com/problems/longest-string-chain/discuss/785733/Well-explained-Solution-O(n3)-C++-solution-using-the-LIS-algo
// O(n^3)

