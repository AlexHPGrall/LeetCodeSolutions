class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int, int> mem;
        int res=0;
        for(int i:nums3)
            for(int j:nums4)
            {
                mem[i+j]++;
            }
        
        for(int i:nums1)
            for(int j:nums2)
            {
                if(mem.count(-i-j))
                    res+=mem[-i-j];
            }
        return res;
    }
};