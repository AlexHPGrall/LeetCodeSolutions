class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        int freq[1001]={0};
        for(auto &v:nums)
        {
            for(int n:v)
            {
                freq[n]++;
            }
        }
        vector<int> res;
        for(int i=0; i<1001; ++i)
            if(freq[i]==nums.size())
                res.push_back(i);
        return res;
    }
};