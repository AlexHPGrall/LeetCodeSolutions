class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int freq[501]={0};
        for(int n:nums)
        {
            freq[n]++;
        }
        for(int n:nums)
        {
            if(freq[n]&1)
                return false;
        }
        return true;
    }
};