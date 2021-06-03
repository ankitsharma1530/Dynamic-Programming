// class Solution {
// public:
//     int stoneGameVI(vector<int>& A, vector<int>& B) {
//         vector<vector<int>> sums;
//         int n=A.size();
//         for(int i=0;i<n;i++) {
//             sums.push_back({A[i]+B[i], A[i], B[i]});
//         }
//         sort(sums.begin(),sums.end());
//         vector<int> res(2,0);
//         for(int i=0;i<n;i++) {
//             res[i%2]+=sums[n-1-i][i%2+1];
//         }
//         return res[0]==res[1] ? 0 : (res[0]>res[1]? 1 : -1);
//     }
// };

class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n = bobValues.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++)
            pq.push({aliceValues[i]+bobValues[i],i});
        int alice=0,bob=0,flg=1;
        while(!pq.empty())
        {
            pair<int,int> p = pq.top();
            pq.pop();
            if(flg)
            {
                alice += aliceValues[p.second];
                flg = 0;
            }
            else
            {
                bob += bobValues[p.second];
                flg = 1;
            }
        }
        if(alice == bob)
            return 0;
        return alice > bob ? 1 : -1;
    }
};
