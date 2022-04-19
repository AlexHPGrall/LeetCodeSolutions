class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size()>k)
        {
            string w="";
            for(int i=0; i<s.size();i+=k)
            {
                int n=0;
                for(int j=0;j<k&&i+j<s.size();++j)
                {
                    n+=s[i+j]-'0';
                }
                w+=to_string(n);
            }
            s=w;
        }
        return s;
    }
};