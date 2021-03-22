class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int  n=scores.size(), dp[n],ans=0;;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({ages[i],scores[i]});
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            scores[i] = v[i].second;
            ages[i] = v[i].first;
        }
        for(int i=0;i<n;i++){
            dp[i] = scores[i];
            for(int j=0;j<i;j++){
                if(scores[i]>=scores[j] and ages[i]>=ages[j]) dp[i] = max(dp[i],dp[j]+scores[i]);
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
