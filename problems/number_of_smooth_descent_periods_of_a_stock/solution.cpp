class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        if(n==1)
            return 1;
        unsigned long long p=1;
        unsigned long long res=0;
        for(int i=1;i<n;++i)
        {
            if(prices[i-1]==prices[i]+1)
                ++p;
            else
            {
                res+=(p*(p+1))/2;
                p=1;
            }
        }
       
        res+=(p*(p+1))/2;
        return res;
    }
};