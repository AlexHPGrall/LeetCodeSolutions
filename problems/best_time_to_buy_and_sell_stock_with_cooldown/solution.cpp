class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profits(n+3,0);
        
        for(int i =0; i<n; ++i)
        {
            int prof =profits[i+2];
            for(int j=0; j<i;++j)
            {
                prof = max(prof, prices[i]-prices[j] + profits[j+1]);
            }
            profits[i+3]=prof;
            
        }
        return profits[n+2];
    }
};