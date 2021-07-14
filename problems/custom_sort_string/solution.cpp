class Solution {
public:
    string customSortString(string order, string str) {
        
        int m = order.size(), n=str.size();
        vector<char> ordermap(m);
        vector<int>numletter(26, -1);
        
        for(int i =0; i<m; i++)
        {
            ordermap[i] =order[i];
            numletter[order[i] -'a'] = 0;
        }
        string res;
        for(int i =0; i<n; ++i)
        {
            if(numletter[str[i] -'a'] == -1)
            {
                
                res.push_back(str[i]);
            }
            else
                numletter[str[i]-'a']++;
        }
        
        for(char c : ordermap)
        {
            for(int i=0; i<numletter[c-'a']; ++i)
                res.push_back(c);
        }
        return res;
        
    }
};