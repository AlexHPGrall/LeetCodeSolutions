class Solution {
public:
    int rangeBitwiseAnd(int left, int right, int start =30) {
        uint32_t check;
        
        if(left ==0)
            return 0;
        for(int i = start; ~i; --i, --start)
        {
            if((1<<i)&left)
            {
                check=(1<<i);
                break;
            }
        }
        cout<<start<<endl;
        if((uint32_t)right<(check<<1))
            return check + rangeBitwiseAnd(left&(~check),right&(~check), start);
        else 
            return 0;
    }
};