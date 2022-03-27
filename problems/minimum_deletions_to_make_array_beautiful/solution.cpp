class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int res=0;
        int offset=0;
        for(int i=0;i<nums.size()-1;++i)
        {
            if((i-offset)%2==0)
            {
                int j=i+1;
                while(j<nums.size() && nums[j]==nums[i])
                {
                    offset++;
                    res++;
                    ++j;
                }
                i=j-1;
                
            }
        }
        if((nums.size()-res) &1)
            ++res;
        return res;
    }
};