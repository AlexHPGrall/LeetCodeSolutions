#define ll long long
class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        if(stockPrices.size()<3)
            return stockPrices.size()-1;
        sort(stockPrices.begin(), stockPrices.end());
        int res=1;
        for(int i=0;i<stockPrices.size()-2;++i)
        {
            ll ax=stockPrices[i+1][0]-stockPrices[i][0];
            ll ay=stockPrices[i+1][1]-stockPrices[i][1];
            ll bx=stockPrices[i+2][0]-stockPrices[i][0];
            ll by=stockPrices[i+2][1]-stockPrices[i][1]; 
            if((ax*by)-(ay*bx)!=0)
                res++;
        }
        return res;
    }
};