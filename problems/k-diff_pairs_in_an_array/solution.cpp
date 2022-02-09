class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> cache;
        const int n = nums.size();
        for (auto x: nums) cache[x]++;
        int count = 0;
        for (auto x: cache) {
            int p=x.first; int v=x.second;
            if (k>0 && cache.count(p+k)>0) count++;
            else if (k == 0 && v>1) count++;
        }
        return count;
    }
};