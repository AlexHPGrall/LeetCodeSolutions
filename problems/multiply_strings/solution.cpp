class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size()<num2.size())
            swap(num1, num2);
        int m= num1.length();
        int n=num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        uint32_t rmd =0;
        string res;
        for(int i=0; i<m; ++i)
        {
            uint32_t sum =0;
            for(int j=i; ~j; --j)
            {
                if(i-j>=n)
                    break;
                sum += (num1[j]-'0')*(num2[i-j]-'0');
                
            }
           
            sum += rmd;
            res.push_back('0'+(sum%10));
            rmd = sum/10;
        }
        for(int i=1; i<n; ++i)
        {
             uint32_t sum =0;
            for(int j=m-1; j>=i; --j)
            {
                if(m-1+i-j>=n)
                    break;
                sum += (num1[j]-'0')*(num2[m-1+i-j]-'0');
                
            }
           
            sum += rmd;
            res.push_back('0'+(sum%10));
            rmd = sum/10;
        }
        while(rmd)
        {
            res.push_back('0'+(rmd%10));
            rmd = rmd/10;
        }
        reverse(res.begin(), res.end());
        int i=0;
        while(i<res.size()-1 && res[i] == '0')
            ++i;
        return res.substr(i);
    }
};