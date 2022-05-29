class Solution {
public:
    int maxProduct(vector<string>& words) {
        int res=0;
        vector<int> masks;
        for(string &w:words)
        {
            int mask=0;
            for(char c:w)
                mask|=(1<<(c-'a'));
            masks.push_back(mask);
        }
        for(int i=0;i<words.size()-1;++i)
        {
            for(int j=i+1;j<words.size();++j)
            {
                if(!(masks[i]&masks[j]))
                    res=max(res, (int)words[i].size()*(int)words[j].size());
            }
        }
        return res;
    }
};