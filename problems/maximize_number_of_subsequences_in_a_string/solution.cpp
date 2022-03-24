class Solution {
public:
    long long maximumSubsequenceCount(string text, string p) {
        long long cfreq=0;
        long long count=0;
        for(char c:text)
            if(c==p[1])
                ++cfreq;
        long long f0=0,f1=cfreq;
        for(char c:text)
        {
            if(c==p[1])
                --cfreq;
            if(c==p[0])
            {
                ++f0;
                count+=cfreq;
            }
        }
        return count + max(f0,f1);
    }
};