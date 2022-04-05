class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n=start^goal;
        int res=0;
        while(n)
        {
            if(n&1)
                res++;
            n>>=1;
            
        }
        return res;
    }
};