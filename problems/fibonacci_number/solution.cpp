class Solution {
    int fibArray[30] = {0,1};
public:
    int fib(int n) {
      
        if(n==0 || n ==1)
            return n;
        
        if(fibArray[n-1] == 0)
            fibArray[n-1] = fib(n-1);
        if(fibArray[n-2] == 0)
            fibArray[n-2] = fib(n-2);
        
        return fibArray[n-1] + fibArray[n-2];
        
    }
};