class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int obp = -prices[0]; // old buy profit
        int osp = 0;          // old sell profit
        int ocp = 0;          // old cool down profit
        for(int i=1;i<prices.size();i++)
        {
            int nbp = 0;
            int nsp = 0;
            int ncp = 0;
            // update nbp
            if(ocp-prices[i]>obp)
            {
                nbp = ocp-prices[i];
            }
            else
            {
                nbp = obp;
            }
            // update nsp
            if(obp+prices[i]>osp)
            {
                nsp = obp+prices[i]; 
            }
            else
            {
                nsp = osp;
            }
            // update ncp
            if(osp>ocp)
            {
                ncp = osp;
            }
            else
            {
                ncp = ocp;
            }
            obp = nbp;
            osp = nsp;
            ocp = ncp;
        }
        return osp;
    }
};
