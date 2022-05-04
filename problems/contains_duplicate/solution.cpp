class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int ,int> vis;
        for(int n:nums)
        {
            if(vis[n])
                return true;
            vis[n]=1;
        }
        return false;
    }
};