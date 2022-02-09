class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int curr=prices[0];
        for(int i=1;i<prices.size();++i)
        {
            if(curr>prices[i])
                curr=prices[i];
            else
                res=max(res, prices[i]-curr);
        }
        return res;
    }
};