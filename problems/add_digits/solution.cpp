class Solution {
public:
    int addDigits(int num) {
        int res=0;
        while(num)
        {
            res+=(num%10);
            if(res>=10)
                res=(res%10)+1;
            num/=10;
        }
        
        return res;
    }
};