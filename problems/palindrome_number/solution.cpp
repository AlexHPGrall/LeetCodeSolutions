class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int m=x, n=0;
        while(m)
        {
            int d =m%10;
            m/=10;
            if(n>INT_MAX/10)
                return false;
            n*=10;
            if(n>INT_MAX-d)
                return false;
            n+=d;
        }
        return (n==x);
    }
};