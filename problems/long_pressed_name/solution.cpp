class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        while(i<name.length() && j<typed.length())
        {
            char c=name[i];
            int ncount=0, tcount=0;
            while(i<name.length() && name[i]==c)
            {++i;++ncount;}
            while(j<typed.length() && typed[j]==c)
            {
                ++j;
                ++tcount;
            }
            if(tcount<ncount)
                return false;
        }
        if(i==name.length()&& j==typed.length())
        {
            return true;
        }
        else
            return false;
    }
};