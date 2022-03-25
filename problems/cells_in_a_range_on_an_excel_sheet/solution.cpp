class Solution {
public:
    vector<string> cellsInRange(string s) {
        char sc=s[0];
        char sr=s[1];
        char ec=s[3];
        char er=s[4];
        vector<string> res;
        for(int i=0; sc+i<=ec;++i)
        {
            for(int j=0; sr+j<=er;++j)
            {
                string t(2,' ');
                t[0]=sc+i;
                t[1]=sr+j;
                res.push_back(t);
            }
        }
        return res;
    }
};