class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1.length()<str2.length())
            swap(str1, str2);
        int xlen=0;
        int mask=0, mask2=0;
        for(int i=0;i<str1.length();++i)
        {
            if(str1[i]!=str2[i%str2.length()])
                return "";
            mask|=(1<<(str1[i]-'A'));
        }
        mask2=mask;
        for(int i=0;i<str2.length();++i)
        {
            mask2^=(1<<(str2[i]-'A'));
            if(mask2==mask)
            {
                for(int j=0; j<str2.length(); ++j)
                {
                    if(str2[j]!= str2[j%(i+1)])
                        goto end;
                }
                xlen=i;
                break;
                
            } 
end:    continue;
        }
        //cout<<xlen<<endl;
        if(xlen)
        {
            xlen=(xlen/2);
        }
        else
        {
            xlen=str2.length()-1;
        }
        xlen++;
        int m=str1.length()/(xlen);
        int n = str2.length()/(xlen);
        
        xlen*= gcd(m,n);
        string res;
        for(int i=0;i<xlen;++i)
        {
            res.push_back(str2[i]);
        }
        return res;
        
    }
};