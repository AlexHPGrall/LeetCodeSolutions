class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        vector<long long> res;
        if(n%2!=0)
            return res;
        n/=2;
        long long i=1;
        while(n)
        {
            if(n-i<=i)
                i=n;
            n-=i;
            res.push_back(2*i);
            i++;
        }

        return res;
    }
};