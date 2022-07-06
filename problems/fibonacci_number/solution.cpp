class Solution {
public:
    int fib(int n) {
        int c=2, b=1, a=0;
        while(n--)
        {
            c=b+a;
            a=b;
            b=c;
        }  
            return a;
    }
};