class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        int res;
        int currmax=0;
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size()-1;++i)
        {
            if(nums[i]==key)
            {
                freq[nums[i+1]]++;
                if(freq[nums[i+1]]>currmax)
                {currmax=freq[nums[i+1]];res=nums[i+1];}
            }
        }
        return res;
    }
};