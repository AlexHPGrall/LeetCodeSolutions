class Solution {
public:
    string reformat(string s) {
        vector<char> a,b;
        for(char c:s)
        {
            if(c>='a'&& c<='z')
                a.push_back(c);
            else
                b.push_back(c);
        }
        if(abs((int)a.size()-(int)b.size())>1)
            return "";
        if(a.size()<b.size())
            swap(a,b);
        string res;
        for(int i=0; i<a.size();++i)
        {
            res.push_back(a[i]);
            if(i<b.size())
                res.push_back(b[i]);
        }
        return res;
    }
};