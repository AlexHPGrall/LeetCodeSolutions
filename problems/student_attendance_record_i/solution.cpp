class Solution {
public:
    bool checkRecord(string s) {
        int cons=0;
        int abs=0;
        for(char c:s)
        {
            if(c=='L')
            {
                cons++;
                if(cons==3)
                    return false;
            }
            else
                cons=0;
            if(c =='A')
            {
                abs++;
                if(abs==2)
                    return false;
            }
            
        }
        return true;
    }
};