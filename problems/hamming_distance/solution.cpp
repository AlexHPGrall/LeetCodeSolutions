class Solution {
public:
    int hammingDistance(int x, int y) {
        int res =0;
        x^=y;
        for(int i=0; i<32; ++i)
            if(x&(1<<i))
                ++res;
        return res;
    }
};