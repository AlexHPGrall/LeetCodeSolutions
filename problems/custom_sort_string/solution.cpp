class Solution {
public:
    string customSortString(string order, string s) {
        char mp[26]={0};
        for(int i =0; i<order.size();++i)
        {
            mp[order[i]-'a']=i;
        }
        sort(s.begin(), s.end(), [&mp](char a, char b){
            return mp[a-'a']<mp[b-'a'];
        });
        
        return s;
    }
};