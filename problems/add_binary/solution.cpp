class Solution {
public:
    string addBinary(string a, string b) {
        int m =a.size(), n=b.size();
        int pa=m-1, pb=n-1;
        char carry = 0;
        vector<char> str;
        for(;pa>=0 || pb>=0;pa--,pb--)
        {
            char ad=0,bd=0;
            char res;
            if(pa>=0)
            {
                ad=a[pa]-'0';
            }
            if(pb>=0)
            {
                bd=b[pb]-'0';
            }
            res=ad+bd+carry;
            str.push_back(res%2 + '0');
            if(res>1)
            {
                carry=1;
            }
            else
                carry=0;
        }
        
        if(carry)
            str.push_back('1'); 
        string res;
        
        for(auto it = str.end()-1; it >=str.begin(); --it)
        {

            res.push_back(*it);
        }
        
        return res;
    }
};