class Solution {
public:
    int waysToMakeFair(vector<int>& A) {
        int N = A.size(), even = 0, odd = 0, ans = 0;
        vector<int> e(N + 1), o(N + 1);
        for(int i=N-1;i>=0;i--)
        {
            if(i&1){
                o[i] = o[i]+A[i];
            }
            else{
                e[i]+=A[i];
            }
            o[i]+=o[i+1];
            e[i]+=e[i+1];
        }
        int res = 0;
        for(int i=0;i<N;i++)
        {
            if(even+o[i+1]==odd+e[i+1]){
                res++;
            }
            if(i&1){
                odd+=A[i];
            }
            else{
                even+=A[i];
            }
        }
        return res;
    }
};
