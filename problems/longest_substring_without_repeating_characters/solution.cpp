class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        unordered_map<char, int> letters;
        int curr=0;
        int res=1;
        for(int i=0; i<s.size();++i)
        {
            if(letters.count(s[i]) && letters[s[i]]>=curr)
            {
                res=max(res, i-curr);
                curr=letters[s[i]]+1;
            }
            letters[s[i]]=i;
        }
        return max(res, (int)s.size()-curr);
    }
};