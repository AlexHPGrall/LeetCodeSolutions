class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        for(int j=0;j<n;++i)
        {
            swap(nums[i],nums[j]);
            ++j;
            //cout<<i<<" "<<j<<" ";
            if(j<n && nums[j]==nums[i])
            {
                ++i;
                swap(nums[i],nums[j]);
                ++j;
            }
            //cout<<j<<" ";
            while(j<n && nums[i]==nums[j])
            {
                ++j;
                //cout<<" --> "<<j;
            }
            //cout<<endl;
        }
        
        return i;
    }
};