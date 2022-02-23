class Solution {
public:
    int reverse(int x) {
        int res=0;
        int sign=1;
        if(x<0)
            sign=-1;
        while(x)
        {
            int rem = abs(x)%10;
            if(res>INT_MAX/10 || res<INT_MIN/10)
                return 0;
            res*=10;
            if(sign==1 && res>INT_MAX-rem)
                return 0;
            if(sign==-1 && res<INT_MIN+rem)
                return 0;
            res+=sign*rem;
            x=(x-(sign*rem))/10;
        }
        return res;
    }
};