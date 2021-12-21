class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        uint32_t i=n;
             i = i - ((i >> 1) & 0x55555555);        // add pairs of bits
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);  // quads
     i = (i + (i >> 4)) & 0x0F0F0F0F;        // groups of 8
     return ((i * 0x01010101) >> 24)== 1;
        
    }
};