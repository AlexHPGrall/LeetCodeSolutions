class Solution {
public:
    string toLowerCase(string s) {
        string cpy =s;
        int n = cpy.length();
        for(int i=0; i<n; ++i)
            if(cpy[i]>='A' && cpy[i]<='Z')
                cpy[i] = cpy[i] - 'A' + 'a';
        
        return cpy;
    }
};