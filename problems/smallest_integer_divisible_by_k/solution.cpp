class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)
            return 1;
        if(k%2==0 || k%5 == 0)
            return -1;
        int m= 10%k;
        if(m==0)
            return -1;
        int un=0;
        for(int i=1; i<=k;++i)
        {
            un=(un*m +1)%k;
            if(!un)
                return i;
        }
        return -1;
    }
};