class Solution {
public:
    bool binarySearch(int l, int r, int target)
    {
        if(l>r)
            return false;
        
        uint64_t mid = l+(r-l)/2;
        
        if(mid*mid== target)
            return true;
        if(mid*mid < target)
        {
            return binarySearch(mid+1, r, target);
        }
        else
        {
            return binarySearch(l, mid-1, target);
        }
        
    }
    bool judgeSquareSum(int c) {
        for(uint64_t a=0; a*a<=c; ++a)
        {
            int b = c-(a*a);
            if(binarySearch(0, b,b))
               return true;
        }
               return false;
    }
};