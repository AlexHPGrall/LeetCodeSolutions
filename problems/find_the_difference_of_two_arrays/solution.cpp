class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        vector<vector<int>> res(2);
        for(int n:nums1)
            s1.insert(n);
        for(int n:nums2)
            s2.insert(n);
        for(int n:s1)
            if(!s2.count(n))
                res[0].push_back(n);
        for(int n:s2)
            if(!s1.count(n))
                res[1].push_back(n);
        return res;
    }
};