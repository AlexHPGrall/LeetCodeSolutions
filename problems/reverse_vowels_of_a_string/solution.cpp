class Solution {
public:
    bool isV(char c)
    {
        return c=='a' ||c=='e' ||c=='i' ||c=='o' ||c=='u' ||c=='A' ||c=='E' ||c=='I' ||c=='O' ||c=='U';
    }
    string reverseVowels(string s) {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            while(l<r&&!isV(s[l]))
                ++l;
            while(r>l&&!isV(s[r]))
                --r;
            if(l<r)
                swap(s[l],s[r]);
            ++l;
            --r;
                
        }
        return s;
    }
};