class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> s1, s2;
        for(int i=0;i<nums.size();++i)
        {
            if(i&1)
                s2.push_back(nums[i]);
            else
                s1.push_back(nums[i]);
        }
        sort(s1.begin(), s1.end());
        sort(s2.rbegin(),s2.rend());
        for(int i=0;i<nums.size();++i)
        {
            if(i&1)
                nums[i]=s2[i/2];
            else
                nums[i]=s1[i/2];
        }
        return nums;
    }
        
};