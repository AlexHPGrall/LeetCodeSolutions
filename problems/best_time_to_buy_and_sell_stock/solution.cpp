class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int best=prices[0];
        for(int i=1; i<prices.size();++i)
        {
            res=max(res, prices[i]-best);
            best=min(best,prices[i]);
        }
        return res;
    }
};