class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1,s2,s3,s4;
        for(int n:nums1)
            s1.insert(n);
        for(int n:nums2)
            s2.insert(n);
        for(int n:nums3)
            s3.insert(n);
        vector<int> res;
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),inserter(s4, s4.begin()));
        set_intersection(s1.begin(),s1.end(),s3.begin(),s3.end(),inserter(s4, s4.begin()));
        set_intersection(s3.begin(),s3.end(),s2.begin(),s2.end(),inserter(s4, s4.begin()));
        for(int n:s4)
            res.push_back(n);
        return res;
        
    }
};