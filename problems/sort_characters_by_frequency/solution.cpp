struct myPair
{
    char c;
    int freq;
};
class Solution {
public:
    string frequencySort(string s) {
        int n = s.length();
        vector<myPair> vec(n,{0,0});
        unordered_map<char,int> mp;
        for(int i=0; i<n; ++i)
        {
            vec[i].c = s[i];
            if(mp.count(s[i]))
                mp[s[i]]++;
            else
                mp[s[i]] =1;
        }
        for(int i=0; i<n; ++i)
        {
            vec[i].freq = mp[s[i]];
        }
        sort(vec.begin(), vec.end(), [](myPair a, myPair b) {return (a.freq > b.freq)||(a.freq == b.freq && a.c<b.c); });
        string ret(n,0);
        for(int i=0; i<n; ++i)
        {
           ret[i] = vec[i].c;
        }
        return ret;
        
    }
};