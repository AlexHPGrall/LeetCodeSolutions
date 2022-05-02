class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, unordered_map<string, int>> orderMap;
        set<string> items;
        for(auto &v:orders)
        {
            items.insert(v[2]);
            orderMap[stoi(v[1])][v[2]]++;
        }
        vector<vector<string>> res(orderMap.size()+1, vector<string>(items.size()+1));
        res[0][0]="Table";
        int i=1;
        int j=1;
        for(auto &it:orderMap)
        {
            res[j][0]=to_string(it.first);
            ++j;
        }
        j=1;
        
        for(string item:items)
        {
            res[0][j]=item;
            for(auto& [key,mp]:orderMap)
            {
                
                res[i][j]=to_string(mp[item]);
                ++i;
            }
            i=1;
            ++j;
        }
       
        return res;
    }
};