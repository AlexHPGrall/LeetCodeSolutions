struct VectorHash {
    size_t operator()(const std::vector<int>& v) const {
        std::hash<int> hasher;
        size_t seed = 0;
        for (int i : v) {
            seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
        }
        return seed;
    }
};
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> mySet;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0; i<(1<<n); ++i)
        {
            vector<int> temp;
            for(int j=0; j<n; ++j)
            {
                if(i&(1<<j))
                    temp.push_back(nums[j]);
            }
            
            mySet.insert(temp);
        }
        
        vector<vector<int>> res;
        for(auto v : mySet)
            res.push_back(v);
        return res;
    }
};