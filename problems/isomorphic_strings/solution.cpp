class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> map1, map2;
        for(int i =0; i<n; ++i)
        {
            if(map1.find(s[i]) == map1.end())
            {
                if(map2.find(t[i]) ==map2.end())
                {
                    map1[s[i]] =t[i];
                    map2[t[i]] =s[i];
                    
                }
                else
                    return false;
                
            }
            else
            {
                if(map1[s[i]] != t[i])
                    return false;
            }
        }
        return true;
            
    }
};