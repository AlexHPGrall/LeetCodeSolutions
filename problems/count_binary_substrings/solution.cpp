class Solution {
public:
    int countBinarySubstrings(string s) {
        char cur, prev;
        int cum0, cum1;
        prev='2';
        cum0 = cum1=0;
        int res =0;
        for(char c :s )
        {
            cur = c;
            if(prev == cur)
            {
                if(cur =='0')
                    cum0++;
               else
                    cum1++;
            }
                
            else
            {
                res += min(cum1, cum0);
                if(cur== '0')
                    cum0 = 1;
                else
                    cum1 =1;
            }
            //cout<<cur<<' '<<prev<<' '<<cum0<<' '<<cum1<<endl;
            prev = cur;
        }
        res+= min(cum1, cum0);
        return res;
        
    }
};