class Solution {
public:
    int balancedStringSplit(string s) {
        int sum=0;
        int res=0;
        for(char c:s)
        {
            if(c=='L')
                sum+=1;
            else
                sum-=1;
            if(sum==0)
                res++;
        }
        return res;
    }
};