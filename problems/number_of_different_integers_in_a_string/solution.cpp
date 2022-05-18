class Solution {
public:
    int numDifferentIntegers(string word) {
        int cnt=0;
        int i=0;
        unordered_map<string, int> vis;
        while(i<word.size())
        {
            string s;
            while(i<word.size() &&word[i]=='0')
            {
                ++i;
                s="0";
            }
            if(i<word.size() && word[i]>'0'&& word[i]<='9')
                s="";
            while(i<word.size() && word[i]>='0'&& word[i]<='9')
            {
                s.push_back(word[i]);
                ++i;
            }
            if(!s.empty())
            {
                if(!vis.count(s))
                {
                    cnt++;
                    vis[s]=1;
                }
            }
            while(i<word.size() && word[i]>='a'&& word[i]<='z')
                ++i;
            
        }
        return cnt;
            
    }
};