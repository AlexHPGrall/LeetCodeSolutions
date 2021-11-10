class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int H=-prices[0];
        int N = 0;
        for(int i=1;i<n; ++i)
        {
            int tmp = H;
            H=max(H, N-prices[i]);
            N=max(N, tmp + prices[i]);
        }
        return max(H, N);
    }
};