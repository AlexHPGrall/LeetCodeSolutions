class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        int i=0;
        while(i<n)
        {
            int l=i;
            int r=min(k+i,n)-1;
            while(l<r)
            {
                swap(s[l++],s[r--]);
            }
            i+=2*k;
        }
        return s;
    }
};