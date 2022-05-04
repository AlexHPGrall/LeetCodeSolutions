class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int ,vector<int>> map;
        for(int i=0; i<nums.size();++i)
            map[nums[i]].push_back(i);
        for(auto &[key, v]:map)
        {
            
            if(map.count(target-key))
            {
                if(target==2*key && v.size()<2)
                    continue;
                int index=v.back();
                v.pop_back();
                return {index, map[target-key].back()};
            }
        }
        return {};
    }
};