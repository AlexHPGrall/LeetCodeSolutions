class Solution {
public:
    string decodeCiphertext(string s, int rows) {
        int col =s.size()/rows;
        string res;
        for(int i=0;i<col;++i)
        {
            for(int j=0;j<(s.size()-i);j+=col+1)
                res.push_back(s[i+j]);
        }
        for(int i=res.size()-1;i>=0&& res[i]==' ';--i)
            res.pop_back();
        return res;
    }
};