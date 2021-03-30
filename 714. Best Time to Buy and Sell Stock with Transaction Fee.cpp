class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int obp = -prices[0];
        int osp = 0;
        for(int i=1;i<prices.size();i++)
        {
            int nbp = 0;
            int nsp = 0;
            if(osp-prices[i]>obp)
            {
                nbp = osp-prices[i];
            }
            else
            {
                nbp = obp;
            }
            if(prices[i]+obp-fee>osp)
            {
                nsp = prices[i]+obp-fee;
            }
            else
            {
                nsp = osp;
            }
            osp=nsp;
            obp=nbp;
        }
        return osp;
    }
};
