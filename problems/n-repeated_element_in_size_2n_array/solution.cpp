class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> set;
        for(int n:nums)
        {
            if(set.count(n))
                return n;
            set.insert(n);
        }
        return -1;
    }
};