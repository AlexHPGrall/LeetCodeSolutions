class Solution {
public:
    int arrangeCoins(uint32_t n) {
        uint32_t res=0;
        for(uint32_t i=1, j=2; n>=i;i=i+j, ++j)
            res++;
        return res;
        }
    
};