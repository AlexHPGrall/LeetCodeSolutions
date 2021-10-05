class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=3)
            return n;
        
        int a, b;
        a=3, b=2;
        for(int i=3;i<n;++i)
        {
            a=a+b;//careful overflow!
            b=a-b;
        }
        return a;
    }
};