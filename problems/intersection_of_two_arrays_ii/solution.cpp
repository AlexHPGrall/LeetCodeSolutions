class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int m = nums1.size(), n= nums2.size();
        unordered_map<int,int> freq;
        for(int i =  0; i<m;++i)
        {
            if(!freq.count(nums1[i]))
                freq[nums1[i]] =1;
            else
                freq[nums1[i]]++;
        }
        for(int i=0; i<n; ++i)
        {
            if(freq.count(nums2[i]) && freq[nums2[i]]!=0)
            {
                freq[nums2[i]]--;
                res.push_back(nums2[i]);
            }
        }
        return res;
    }
};