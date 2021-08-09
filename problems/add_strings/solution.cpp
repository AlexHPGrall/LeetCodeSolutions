class Solution {
public:
    string addStrings(string num1, string num2) {
        int m=num1.length(), n=num2.length();
        int k=max(m,n);
        bool carry=false;
        vector<char> sum;
        for(int i=m-1, j=n-1, l=0;l<k;--i, --j,++l)
        {
            int c1=0, c2=0;
            if(i>=0)
                c1=num1[i]-'0';
            if(j>=0)
                c2=num2[j]-'0';
            c1+=c2;
            if(carry)
            {
                ++c1;
                carry=false;
            }
                
            
            if(c1>=10)   
            {
                c1-=10;
                carry=true;
            }
            sum.push_back(c1+'0');
            
        }
        if(carry)
            sum.push_back('1');
        k=sum.size();
        string res;
        for(int i=k-1; ~i;--i)
            res.push_back(sum[i]);
        
        return res;
    }
};