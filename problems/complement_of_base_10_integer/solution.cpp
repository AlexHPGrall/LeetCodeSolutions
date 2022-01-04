class Solution {
public:
    int bitwiseComplement(int num) {
        int tmp=num;
        int mask=0;
        if(!num)
            return 1;
        while(tmp>>=1)
        {
            mask=(mask<<1) +1;   
        }
        return ~num &mask;
        
    }
};