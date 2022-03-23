class Solution {
public:
    int brokenCalc(int s, int t) {
        int res=0;
        while(s<t)
        {
            if(!(t&1))
                t>>=1;
            else
                t+=1;
            res++;
        }
        res+=s-t;
        return res;
    }
};