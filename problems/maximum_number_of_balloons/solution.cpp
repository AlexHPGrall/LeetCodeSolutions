class Solution {
public:
    char b[5] ={'b','a','l','o','n'};
    int maxNumberOfBalloons(string text) {
        vector<int> freq(26, 0);
        for(char c: text)
        {
            ++freq[c-'a'];
        }
        freq['l'-'a']/=2;
        freq['o'-'a']/=2;
        int res=INT_MAX;
        for(char c:b)
        {
            res =min(res, freq[c-'a']);
        }
        return res;
    }
};