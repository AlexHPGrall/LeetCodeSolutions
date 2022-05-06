class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int currmin=prices[0];
        for(int p:prices)
        {
            res=max(res, p-currmin);
            currmin=min(currmin,p);
        }
        
        return res;
    }
};