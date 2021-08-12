class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> hashmap;
        vector<vector<string>> res;
        
        for (string key : strs) {
            string aux = key;
            sort(key.begin(),key.end());
            if (hashmap.count(key) ==1) {
                res[hashmap[key]].push_back(aux);
            } else if (hashmap.count(key) == 0){
                hashmap.insert({key, res.size()});
                vector<string> temp;
                res.push_back(temp);
                res[hashmap[key]].push_back(aux);
            }
            
        }
        return res;
    }
};